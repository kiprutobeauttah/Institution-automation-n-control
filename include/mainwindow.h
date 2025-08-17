#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QSplitter>
#include <QTreeWidget>
#include <QTabWidget>
#include <QTableWidget>
#include <QListWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QProgressBar>
#include <QGroupBox>
#include <QScrollArea>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QPrintDialog>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QAction>
#include <QActionGroup>
#include <QIcon>
#include <QPixmap>
#include <QPainter>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QBarSeries>
#include <QPieSeries>

// Forward declarations of module classes
class StudentManagement;
class TeacherManagement;
class FeesFinanceManagement;
class AttendanceManagement;
class InventoryManagement;
class ExamManagement;
class LibraryManagement;
class TransportManagement;
class HostelManagement;
class EventManagement;
class CommunicationManagement;
class ReportManagement;
class SecurityManagement;
class MaintenanceManagement;
class HRManagement;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Navigation slots
    void showStudentManagement();
    void showTeacherManagement();
    void showFeesFinance();
    void showAttendanceManagement();
    void showInventoryManagement();
    void showExamManagement();
    void showLibraryManagement();
    void showTransportManagement();
    void showHostelManagement();
    void showEventManagement();
    void showCommunicationManagement();
    void showReportManagement();
    void showSecurityManagement();
    void showMaintenanceManagement();
    void showHRManagement();
    
    // File menu slots
    void newDocument();
    void openDocument();
    void saveDocument();
    void printDocument();
    void exportData();
    void importData();
    
    // Edit menu slots
    void undoAction();
    void redoAction();
    void cutAction();
    void copyAction();
    void pasteAction();
    
    // View menu slots
    void toggleFullScreen();
    void showDashboard();
    void customizeInterface();
    void zoomIn();
    void zoomOut();
    
    // Tools menu slots
    void showSettings();
    void showCalculator();
    void showCalendar();
    void showNotifications();
    void databaseBackup();
    void systemMaintenance();
    
    // Help menu slots
    void showHelp();
    void showAbout();
    void checkUpdates();
    void contactSupport();
    
    // System slots
    void updateStatusBar();
    void minimizeToTray();
    void showFromTray();

private:
    void setupUI();
    void setupMenuBar();
    void setupToolBar();
    void setupStatusBar();
    void setupCentralWidget();
    void setupNavigationPanel();
    void setupSystemTray();
    void setupConnections();
    void applyStyles();
    void loadSettings();
    void saveSettings();
    
    // UI Components
    QMenuBar *m_menuBar;
    QStatusBar *m_statusBar;
    QToolBar *m_mainToolBar;
    QToolBar *m_navigationToolBar;
    
    // Central widget components
    QWidget *m_centralWidget;
    QSplitter *m_mainSplitter;
    QTreeWidget *m_navigationTree;
    QStackedWidget *m_contentStack;
    QTabWidget *m_mainTabs;
    
    // Status components
    QLabel *m_statusLabel;
    QLabel *m_userLabel;
    QLabel *m_timeLabel;
    QLabel *m_connectionLabel;
    QProgressBar *m_progressBar;
    
    // System tray
    QSystemTrayIcon *m_systemTray;
    QMenu *m_trayMenu;
    
    // Module instances
    StudentManagement *m_studentModule;
    TeacherManagement *m_teacherModule;
    FeesFinanceManagement *m_financeModule;
    AttendanceManagement *m_attendanceModule;
    InventoryManagement *m_inventoryModule;
    ExamManagement *m_examModule;
    LibraryManagement *m_libraryModule;
    TransportManagement *m_transportModule;
    HostelManagement *m_hostelModule;
    EventManagement *m_eventModule;
    CommunicationManagement *m_communicationModule;
    ReportManagement *m_reportModule;
    SecurityManagement *m_securityModule;
    MaintenanceManagement *m_maintenanceModule;
    HRManagement *m_hrModule;
    
    // Timers
    QTimer *m_clockTimer;
    QTimer *m_autoSaveTimer;
    
    // Settings
    QString m_currentTheme;
    QString m_currentLanguage;
    bool m_autoSaveEnabled;
    int m_autoSaveInterval;
    
    // Actions
    QAction *m_newAction;
    QAction *m_openAction;
    QAction *m_saveAction;
    QAction *m_exitAction;
    QAction *m_aboutAction;
    QAction *m_settingsAction;
    QAction *m_fullScreenAction;
    QAction *m_minimizeAction;
    QAction *m_maximizeAction;
};

#endif // MAINWINDOW_H
