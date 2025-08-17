#include "../include/mainwindow.h"
#include "../include/modules/studentmanagement.h"
#include "../include/modules/teachermanagement.h"
#include "../include/modules/feesfinancemanagement.h"
#include "../include/modules/attendancemanagement.h"
#include "../include/modules/inventorymanagement.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QSettings>
#include <QDateTime>
#include <QStandardPaths>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_menuBar(nullptr)
    , m_statusBar(nullptr)
    , m_mainToolBar(nullptr)
    , m_navigationToolBar(nullptr)
    , m_centralWidget(nullptr)
    , m_mainSplitter(nullptr)
    , m_navigationTree(nullptr)
    , m_contentStack(nullptr)
    , m_mainTabs(nullptr)
    , m_statusLabel(nullptr)
    , m_userLabel(nullptr)
    , m_timeLabel(nullptr)
    , m_connectionLabel(nullptr)
    , m_progressBar(nullptr)
    , m_systemTray(nullptr)
    , m_trayMenu(nullptr)
    , m_studentModule(nullptr)
    , m_teacherModule(nullptr)
    , m_financeModule(nullptr)
    , m_attendanceModule(nullptr)
    , m_inventoryModule(nullptr)
    , m_examModule(nullptr)
    , m_libraryModule(nullptr)
    , m_transportModule(nullptr)
    , m_hostelModule(nullptr)
    , m_eventModule(nullptr)
    , m_communicationModule(nullptr)
    , m_reportModule(nullptr)
    , m_securityModule(nullptr)
    , m_maintenanceModule(nullptr)
    , m_hrModule(nullptr)
    , m_clockTimer(new QTimer(this))
    , m_autoSaveTimer(new QTimer(this))
    , m_currentTheme("dark")
    , m_currentLanguage("en")
    , m_autoSaveEnabled(true)
    , m_autoSaveInterval(300000) // 5 minutes
{
    setupUI();
    setupConnections();
    loadSettings();
    applyStyles();
    
    // Initialize modules
    m_studentModule = new StudentManagement(this);
    m_teacherModule = new TeacherManagement(this);
    m_financeModule = new FeesFinanceManagement(this);
    m_attendanceModule = new AttendanceManagement(this);
    m_inventoryModule = new InventoryManagement(this);
    
    // Add modules to content stack
    m_contentStack->addWidget(m_studentModule);
    m_contentStack->addWidget(m_teacherModule);
    m_contentStack->addWidget(m_financeModule);
    m_contentStack->addWidget(m_attendanceModule);
    m_contentStack->addWidget(m_inventoryModule);
    
    // Set window properties
    setWindowTitle("Institution Automation & Control System v2.0");
    setMinimumSize(1200, 800);
    resize(1600, 1000);
    
    // Center window on screen
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
    
    // Start timers
    m_clockTimer->start(1000);
    if (m_autoSaveEnabled) {
        m_autoSaveTimer->start(m_autoSaveInterval);
    }
    
    updateStatusBar();
}

MainWindow::~MainWindow()
{
    saveSettings();
}

void MainWindow::setupUI()
{
    setupMenuBar();
    setupToolBar();
    setupStatusBar();
    setupCentralWidget();
    setupSystemTray();
}

void MainWindow::setupMenuBar()
{
    m_menuBar = menuBar();
    
    // File Menu
    QMenu *fileMenu = m_menuBar->addMenu("&File");
    m_newAction = fileMenu->addAction("&New", this, &MainWindow::newDocument, QKeySequence::New);
    m_openAction = fileMenu->addAction("&Open", this, &MainWindow::openDocument, QKeySequence::Open);
    m_saveAction = fileMenu->addAction("&Save", this, &MainWindow::saveDocument, QKeySequence::Save);
    fileMenu->addSeparator();
    fileMenu->addAction("&Print", this, &MainWindow::printDocument, QKeySequence::Print);
    fileMenu->addSeparator();
    fileMenu->addAction("&Import Data", this, &MainWindow::importData);
    fileMenu->addAction("&Export Data", this, &MainWindow::exportData);
    fileMenu->addSeparator();
    m_exitAction = fileMenu->addAction("E&xit", this, &QWidget::close, QKeySequence::Quit);
    
    // Edit Menu
    QMenu *editMenu = m_menuBar->addMenu("&Edit");
    editMenu->addAction("&Undo", this, &MainWindow::undoAction, QKeySequence::Undo);
    editMenu->addAction("&Redo", this, &MainWindow::redoAction, QKeySequence::Redo);
    editMenu->addSeparator();
    editMenu->addAction("Cu&t", this, &MainWindow::cutAction, QKeySequence::Cut);
    editMenu->addAction("&Copy", this, &MainWindow::copyAction, QKeySequence::Copy);
    editMenu->addAction("&Paste", this, &MainWindow::pasteAction, QKeySequence::Paste);
    
    // View Menu
    QMenu *viewMenu = m_menuBar->addMenu("&View");
    viewMenu->addAction("&Dashboard", this, &MainWindow::showDashboard);
    viewMenu->addSeparator();
    m_fullScreenAction = viewMenu->addAction("&Full Screen", this, &MainWindow::toggleFullScreen, QKeySequence::FullScreen);
    viewMenu->addAction("&Customize Interface", this, &MainWindow::customizeInterface);
    viewMenu->addSeparator();
    viewMenu->addAction("Zoom &In", this, &MainWindow::zoomIn, QKeySequence::ZoomIn);
    viewMenu->addAction("Zoom &Out", this, &MainWindow::zoomOut, QKeySequence::ZoomOut);
    
    // Modules Menu
    QMenu *modulesMenu = m_menuBar->addMenu("&Modules");
    modulesMenu->addAction("&Student Management", this, &MainWindow::showStudentManagement);
    modulesMenu->addAction("&Teacher Management", this, &MainWindow::showTeacherManagement);
    modulesMenu->addAction("&Fees & Finance", this, &MainWindow::showFeesFinance);
    modulesMenu->addAction("&Attendance", this, &MainWindow::showAttendanceManagement);
    modulesMenu->addAction("&Inventory", this, &MainWindow::showInventoryManagement);
    modulesMenu->addAction("&Examinations", this, &MainWindow::showExamManagement);
    modulesMenu->addAction("&Library", this, &MainWindow::showLibraryManagement);
    modulesMenu->addAction("&Transport", this, &MainWindow::showTransportManagement);
    modulesMenu->addAction("&Hostel", this, &MainWindow::showHostelManagement);
    modulesMenu->addAction("&Events", this, &MainWindow::showEventManagement);
    modulesMenu->addAction("&Communication", this, &MainWindow::showCommunicationManagement);
    modulesMenu->addAction("&Reports", this, &MainWindow::showReportManagement);
    modulesMenu->addAction("&Security", this, &MainWindow::showSecurityManagement);
    modulesMenu->addAction("&Maintenance", this, &MainWindow::showMaintenanceManagement);
    modulesMenu->addAction("&HR Management", this, &MainWindow::showHRManagement);
    
    // Tools Menu
    QMenu *toolsMenu = m_menuBar->addMenu("&Tools");
    m_settingsAction = toolsMenu->addAction("&Settings", this, &MainWindow::showSettings);
    toolsMenu->addSeparator();
    toolsMenu->addAction("&Calculator", this, &MainWindow::showCalculator);
    toolsMenu->addAction("&Calendar", this, &MainWindow::showCalendar);
    toolsMenu->addAction("&Notifications", this, &MainWindow::showNotifications);
    toolsMenu->addSeparator();
    toolsMenu->addAction("&Database Backup", this, &MainWindow::databaseBackup);
    toolsMenu->addAction("&System Maintenance", this, &MainWindow::systemMaintenance);
    
    // Help Menu
    QMenu *helpMenu = m_menuBar->addMenu("&Help");
    helpMenu->addAction("&Help Contents", this, &MainWindow::showHelp, QKeySequence::HelpContents);
    helpMenu->addAction("&Check for Updates", this, &MainWindow::checkUpdates);
    helpMenu->addAction("&Contact Support", this, &MainWindow::contactSupport);
    helpMenu->addSeparator();
    helpMenu->addAction("&About", this, &MainWindow::showAbout);
}

void MainWindow::setupToolBar()
{
    m_mainToolBar = addToolBar("Main");
    m_mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    
    m_mainToolBar->addAction(m_newAction);
    m_mainToolBar->addAction(m_openAction);
    m_mainToolBar->addAction(m_saveAction);
    m_mainToolBar->addSeparator();
    
    // Quick access buttons for main modules
    m_mainToolBar->addAction("Students", this, &MainWindow::showStudentManagement);
    m_mainToolBar->addAction("Teachers", this, &MainWindow::showTeacherManagement);
    m_mainToolBar->addAction("Finance", this, &MainWindow::showFeesFinance);
    m_mainToolBar->addAction("Attendance", this, &MainWindow::showAttendanceManagement);
    m_mainToolBar->addAction("Inventory", this, &MainWindow::showInventoryManagement);
    m_mainToolBar->addSeparator();
    
    m_mainToolBar->addAction(m_settingsAction);
}

void MainWindow::setupStatusBar()
{
    m_statusBar = statusBar();
    
    m_statusLabel = new QLabel("Ready");
    m_userLabel = new QLabel("User: Administrator");
    m_timeLabel = new QLabel();
    m_connectionLabel = new QLabel("Database: Connected");
    m_progressBar = new QProgressBar();
    m_progressBar->setVisible(false);
    
    m_statusBar->addWidget(m_statusLabel, 1);
    m_statusBar->addPermanentWidget(m_progressBar);
    m_statusBar->addPermanentWidget(m_connectionLabel);
    m_statusBar->addPermanentWidget(m_userLabel);
    m_statusBar->addPermanentWidget(m_timeLabel);
}

void MainWindow::setupCentralWidget()
{
    m_centralWidget = new QWidget;
    setCentralWidget(m_centralWidget);
    
    m_mainSplitter = new QSplitter(Qt::Horizontal);
    setupNavigationPanel();
    
    // Content area with tabs
    m_mainTabs = new QTabWidget();
    m_contentStack = new QStackedWidget();
    m_mainTabs->addTab(m_contentStack, "Main Content");
    
    m_mainSplitter->addWidget(m_navigationTree);
    m_mainSplitter->addWidget(m_mainTabs);
    m_mainSplitter->setSizes({250, 1350});
    
    QHBoxLayout *layout = new QHBoxLayout(m_centralWidget);
    layout->addWidget(m_mainSplitter);
    layout->setContentsMargins(0, 0, 0, 0);
}

void MainWindow::setupNavigationPanel()
{
    m_navigationTree = new QTreeWidget();
    m_navigationTree->setHeaderLabel("Navigation");
    m_navigationTree->setMaximumWidth(300);
    m_navigationTree->setMinimumWidth(200);
    
    // Add navigation items
    QTreeWidgetItem *studentItem = new QTreeWidgetItem(m_navigationTree, {"Student Management"});
    QTreeWidgetItem *teacherItem = new QTreeWidgetItem(m_navigationTree, {"Teacher Management"});
    QTreeWidgetItem *financeItem = new QTreeWidgetItem(m_navigationTree, {"Fees & Finance"});
    QTreeWidgetItem *attendanceItem = new QTreeWidgetItem(m_navigationTree, {"Attendance"});
    QTreeWidgetItem *inventoryItem = new QTreeWidgetItem(m_navigationTree, {"Inventory"});
    QTreeWidgetItem *examItem = new QTreeWidgetItem(m_navigationTree, {"Examinations"});
    QTreeWidgetItem *libraryItem = new QTreeWidgetItem(m_navigationTree, {"Library"});
    QTreeWidgetItem *transportItem = new QTreeWidgetItem(m_navigationTree, {"Transport"});
    QTreeWidgetItem *hostelItem = new QTreeWidgetItem(m_navigationTree, {"Hostel"});
    QTreeWidgetItem *eventItem = new QTreeWidgetItem(m_navigationTree, {"Events"});
    QTreeWidgetItem *commItem = new QTreeWidgetItem(m_navigationTree, {"Communication"});
    QTreeWidgetItem *reportItem = new QTreeWidgetItem(m_navigationTree, {"Reports"});
    QTreeWidgetItem *securityItem = new QTreeWidgetItem(m_navigationTree, {"Security"});
    QTreeWidgetItem *maintenanceItem = new QTreeWidgetItem(m_navigationTree, {"Maintenance"});
    QTreeWidgetItem *hrItem = new QTreeWidgetItem(m_navigationTree, {"HR Management"});
    
    m_navigationTree->expandAll();
    
    connect(m_navigationTree, &QTreeWidget::itemClicked, [this](QTreeWidgetItem *item) {
        QString text = item->text(0);
        if (text == "Student Management") showStudentManagement();
        else if (text == "Teacher Management") showTeacherManagement();
        else if (text == "Fees & Finance") showFeesFinance();
        else if (text == "Attendance") showAttendanceManagement();
        else if (text == "Inventory") showInventoryManagement();
        else if (text == "Examinations") showExamManagement();
        else if (text == "Library") showLibraryManagement();
        else if (text == "Transport") showTransportManagement();
        else if (text == "Hostel") showHostelManagement();
        else if (text == "Events") showEventManagement();
        else if (text == "Communication") showCommunicationManagement();
        else if (text == "Reports") showReportManagement();
        else if (text == "Security") showSecurityManagement();
        else if (text == "Maintenance") showMaintenanceManagement();
        else if (text == "HR Management") showHRManagement();
    });
}

void MainWindow::setupSystemTray()
{
    if (QSystemTrayIcon::isSystemTrayAvailable()) {
        m_systemTray = new QSystemTrayIcon(this);
        m_systemTray->setIcon(QIcon(":/icons/app_icon.png"));
        
        m_trayMenu = new QMenu(this);
        m_trayMenu->addAction("Show", this, &MainWindow::showFromTray);
        m_trayMenu->addAction("Hide", this, &MainWindow::minimizeToTray);
        m_trayMenu->addSeparator();
        m_trayMenu->addAction("Exit", this, &QWidget::close);
        
        m_systemTray->setContextMenu(m_trayMenu);
        m_systemTray->show();
        
        connect(m_systemTray, &QSystemTrayIcon::activated, [this](QSystemTrayIcon::ActivationReason reason) {
            if (reason == QSystemTrayIcon::DoubleClick) {
                showFromTray();
            }
        });
    }
}

void MainWindow::setupConnections()
{
    connect(m_clockTimer, &QTimer::timeout, this, &MainWindow::updateStatusBar);
    connect(m_autoSaveTimer, &QTimer::timeout, this, &MainWindow::saveDocument);
}

void MainWindow::applyStyles()
{
    // Apply custom stylesheet for modern look
    QString styleSheet = R"(
        QMainWindow {
            background-color: #2b2b2b;
        }
        QMenuBar {
            background-color: #3c3c3c;
            color: white;
            border-bottom: 1px solid #555;
        }
        QMenuBar::item {
            padding: 4px 8px;
            background-color: transparent;
        }
        QMenuBar::item:selected {
            background-color: #555;
        }
        QToolBar {
            background-color: #3c3c3c;
            border: none;
            spacing: 3px;
        }
        QTreeWidget {
            background-color: #353535;
            color: white;
            border: 1px solid #555;
            selection-background-color: #0078d4;
        }
        QTabWidget::pane {
            border: 1px solid #555;
            background-color: #2b2b2b;
        }
        QTabBar::tab {
            background-color: #3c3c3c;
            color: white;
            padding: 8px 16px;
            margin-right: 2px;
        }
        QTabBar::tab:selected {
            background-color: #0078d4;
        }
        QStatusBar {
            background-color: #3c3c3c;
            color: white;
            border-top: 1px solid #555;
        }
    )";
    setStyleSheet(styleSheet);
}

void MainWindow::loadSettings()
{
    QSettings settings;
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    m_currentTheme = settings.value("theme", "dark").toString();
    m_autoSaveEnabled = settings.value("autoSave", true).toBool();
    m_autoSaveInterval = settings.value("autoSaveInterval", 300000).toInt();
}

void MainWindow::saveSettings()
{
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("theme", m_currentTheme);
    settings.setValue("autoSave", m_autoSaveEnabled);
    settings.setValue("autoSaveInterval", m_autoSaveInterval);
}

// Navigation slots implementation
void MainWindow::showStudentManagement()
{
    if (m_studentModule) {
        m_contentStack->setCurrentWidget(m_studentModule);
        m_statusLabel->setText("Student Management Module Active");
    }
}

void MainWindow::showTeacherManagement()
{
    if (m_teacherModule) {
        m_contentStack->setCurrentWidget(m_teacherModule);
        m_statusLabel->setText("Teacher Management Module Active");
    }
}

void MainWindow::showFeesFinance()
{
    if (m_financeModule) {
        m_contentStack->setCurrentWidget(m_financeModule);
        m_statusLabel->setText("Fees & Finance Module Active");
    }
}

void MainWindow::showAttendanceManagement()
{
    if (m_attendanceModule) {
        m_contentStack->setCurrentWidget(m_attendanceModule);
        m_statusLabel->setText("Attendance Management Module Active");
    }
}

void MainWindow::showInventoryManagement()
{
    if (m_inventoryModule) {
        m_contentStack->setCurrentWidget(m_inventoryModule);
        m_statusLabel->setText("Inventory Management Module Active");
    }
}

// Placeholder implementations for other modules
void MainWindow::showExamManagement() { m_statusLabel->setText("Exam Management - Coming Soon"); }
void MainWindow::showLibraryManagement() { m_statusLabel->setText("Library Management - Coming Soon"); }
void MainWindow::showTransportManagement() { m_statusLabel->setText("Transport Management - Coming Soon"); }
void MainWindow::showHostelManagement() { m_statusLabel->setText("Hostel Management - Coming Soon"); }
void MainWindow::showEventManagement() { m_statusLabel->setText("Event Management - Coming Soon"); }
void MainWindow::showCommunicationManagement() { m_statusLabel->setText("Communication Management - Coming Soon"); }
void MainWindow::showReportManagement() { m_statusLabel->setText("Report Management - Coming Soon"); }
void MainWindow::showSecurityManagement() { m_statusLabel->setText("Security Management - Coming Soon"); }
void MainWindow::showMaintenanceManagement() { m_statusLabel->setText("Maintenance Management - Coming Soon"); }
void MainWindow::showHRManagement() { m_statusLabel->setText("HR Management - Coming Soon"); }

// File menu implementations
void MainWindow::newDocument() { m_statusLabel->setText("New document created"); }
void MainWindow::openDocument() { m_statusLabel->setText("Open document"); }
void MainWindow::saveDocument() { m_statusLabel->setText("Document saved"); }
void MainWindow::printDocument() { m_statusLabel->setText("Print document"); }
void MainWindow::exportData() { m_statusLabel->setText("Export data"); }
void MainWindow::importData() { m_statusLabel->setText("Import data"); }

// Edit menu implementations
void MainWindow::undoAction() { m_statusLabel->setText("Undo action"); }
void MainWindow::redoAction() { m_statusLabel->setText("Redo action"); }
void MainWindow::cutAction() { m_statusLabel->setText("Cut action"); }
void MainWindow::copyAction() { m_statusLabel->setText("Copy action"); }
void MainWindow::pasteAction() { m_statusLabel->setText("Paste action"); }

// View menu implementations
void MainWindow::toggleFullScreen() {
    if (isFullScreen()) {
        showNormal();
        m_statusLabel->setText("Exited full screen");
    } else {
        showFullScreen();
        m_statusLabel->setText("Entered full screen");
    }
}
void MainWindow::showDashboard() { m_statusLabel->setText("Dashboard view"); }
void MainWindow::customizeInterface() { m_statusLabel->setText("Customize interface"); }
void MainWindow::zoomIn() { m_statusLabel->setText("Zoomed in"); }
void MainWindow::zoomOut() { m_statusLabel->setText("Zoomed out"); }

// Tools menu implementations
void MainWindow::showSettings() { m_statusLabel->setText("Settings dialog"); }
void MainWindow::showCalculator() { m_statusLabel->setText("Calculator opened"); }
void MainWindow::showCalendar() { m_statusLabel->setText("Calendar opened"); }
void MainWindow::showNotifications() { m_statusLabel->setText("Notifications panel"); }
void MainWindow::databaseBackup() { m_statusLabel->setText("Database backup initiated"); }
void MainWindow::systemMaintenance() { m_statusLabel->setText("System maintenance"); }

// Help menu implementations
void MainWindow::showHelp() { m_statusLabel->setText("Help documentation"); }
void MainWindow::showAbout() {
    QMessageBox::about(this, "About", 
        "Institution Automation & Control System v2.0\n\n"
        "A comprehensive educational institution management system.\n\n"
        "Developed with Qt C++\n"
        "Copyright © 2024 Educational Solutions Inc.");
}
void MainWindow::checkUpdates() { m_statusLabel->setText("Checking for updates"); }
void MainWindow::contactSupport() { m_statusLabel->setText("Contact support"); }

// System implementations
void MainWindow::updateStatusBar()
{
    m_timeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

void MainWindow::minimizeToTray()
{
    if (m_systemTray && m_systemTray->isVisible()) {
        hide();
        m_statusLabel->setText("Application minimized to system tray");
    }
}

void MainWindow::showFromTray()
{
    show();
    raise();
    activateWindow();
    m_statusLabel->setText("Application restored from system tray");
}
