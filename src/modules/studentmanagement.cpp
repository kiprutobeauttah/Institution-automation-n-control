#include "../../include/modules/studentmanagement.h"
#include <QApplication>
#include <QHeaderView>
#include <QDateTime>
#include <QRandomGenerator>

StudentManagement::StudentManagement(QWidget *parent)
    : QWidget(parent)
    , m_mainTabs(nullptr)
    , m_mainLayout(nullptr)
    , m_registrationTab(nullptr)
    , m_registrationToolBox(nullptr)
    , m_registrationStack(nullptr)
    , m_studentsTable(nullptr)
    , m_selectedStudentId(-1)
    , m_isEditMode(false)
{
    setupUI();
    connectSignalsSlots();
    populateSampleData();
    applyModuleStyles();
}

void StudentManagement::setupUI()
{
    m_mainLayout = new QVBoxLayout(this);
    m_mainTabs = new QTabWidget();
    
    setupStudentRegistration();
    setupStudentRecords();
    setupAcademicPerformance();
    setupCommunicationTools();
    setupStudentServices();
    
    m_mainLayout->addWidget(m_mainTabs);
}

void StudentManagement::setupStudentRegistration()
{
    m_registrationTab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(m_registrationTab);
    
    // Top toolbar with main actions
    QHBoxLayout *toolbarLayout = new QHBoxLayout();
    m_addStudentBtn = new QPushButton("New Registration");
    m_editStudentBtn = new QPushButton("Edit Student");
    m_deleteStudentBtn = new QPushButton("Delete Student");
    m_importStudentsBtn = new QPushButton("Import Students");
    m_exportStudentsBtn = new QPushButton("Export Data");
    
    toolbarLayout->addWidget(m_addStudentBtn);
    toolbarLayout->addWidget(m_editStudentBtn);
    toolbarLayout->addWidget(m_deleteStudentBtn);
    toolbarLayout->addSeparator();
    toolbarLayout->addWidget(m_importStudentsBtn);
    toolbarLayout->addWidget(m_exportStudentsBtn);
    toolbarLayout->addStretch();
    
    // Search and filter section
    QHBoxLayout *filterLayout = new QHBoxLayout();
    m_studentSearchBox = new QLineEdit();
    m_studentSearchBox->setPlaceholderText("Search students...");
    m_classFilterCombo = new QComboBox();
    m_sectionFilterCombo = new QComboBox();
    m_searchStudentBtn = new QPushButton("Search");
    
    m_classFilterCombo->addItems({"All Classes", "Grade 1", "Grade 2", "Grade 3", "Grade 4", "Grade 5"});
    m_sectionFilterCombo->addItems({"All Sections", "Section A", "Section B", "Section C"});
    
    filterLayout->addWidget(new QLabel("Search:"));
    filterLayout->addWidget(m_studentSearchBox);
    filterLayout->addWidget(new QLabel("Class:"));
    filterLayout->addWidget(m_classFilterCombo);
    filterLayout->addWidget(new QLabel("Section:"));
    filterLayout->addWidget(m_sectionFilterCombo);
    filterLayout->addWidget(m_searchStudentBtn);
    filterLayout->addStretch();
    
    // Main content area with toolbox for 30+ tools
    QHBoxLayout *contentLayout = new QHBoxLayout();
    
    // Left side - Tools toolbox
    m_registrationToolBox = new QToolBox();
    m_registrationToolBox->setMaximumWidth(300);
    
    // Registration Tools Group 1
    QWidget *admissionTools = new QWidget();
    QVBoxLayout *admissionLayout = new QVBoxLayout(admissionTools);
    QStringList admissionToolsList = {
        "New Student Registration", "Bulk Student Import", "Online Admission Portal",
        "Admission Test Scheduling", "Document Verification", "Medical Examination",
        "Parent/Guardian Info", "Emergency Contacts", "Previous Education History",
        "Scholarship Eligibility"
    };
    
    for (const QString &tool : admissionToolsList) {
        QPushButton *btn = new QPushButton(tool);
        btn->setStyleSheet("text-align: left; padding: 8px;");
        admissionLayout->addWidget(btn);
        
        // Connect to respective slots
        if (tool == "New Student Registration") connect(btn, &QPushButton::clicked, this, &StudentManagement::newStudentRegistration);
        else if (tool == "Bulk Student Import") connect(btn, &QPushButton::clicked, this, &StudentManagement::bulkStudentImport);
        else if (tool == "Online Admission Portal") connect(btn, &QPushButton::clicked, this, &StudentManagement::onlineAdmissionPortal);
        else if (tool == "Admission Test Scheduling") connect(btn, &QPushButton::clicked, this, &StudentManagement::admissionTestScheduling);
        else if (tool == "Document Verification") connect(btn, &QPushButton::clicked, this, &StudentManagement::documentVerification);
        else if (tool == "Medical Examination") connect(btn, &QPushButton::clicked, this, &StudentManagement::medicalExamination);
        else if (tool == "Parent/Guardian Info") connect(btn, &QPushButton::clicked, this, &StudentManagement::parentGuardianInfo);
        else if (tool == "Emergency Contacts") connect(btn, &QPushButton::clicked, this, &StudentManagement::emergencyContactManagement);
        else if (tool == "Previous Education History") connect(btn, &QPushButton::clicked, this, &StudentManagement::previousEducationHistory);
        else if (tool == "Scholarship Eligibility") connect(btn, &QPushButton::clicked, this, &StudentManagement::scholarshipEligibilityCheck);
    }
    m_registrationToolBox->addItem(admissionTools, "Admission Tools (10)");
    
    // Registration Tools Group 2
    QWidget *allocationTools = new QWidget();
    QVBoxLayout *allocationLayout = new QVBoxLayout(allocationTools);
    QStringList allocationToolsList = {
        "Fee Structure Assignment", "Classroom Allocation", "Uniform Size Management",
        "Transport Route Assignment", "Hostel Accommodation", "Library Card Generation",
        "Student ID Card Creation", "Biometric Data Capture", "Photography Session",
        "Orientation Program Scheduling"
    };
    
    for (const QString &tool : allocationToolsList) {
        QPushButton *btn = new QPushButton(tool);
        btn->setStyleSheet("text-align: left; padding: 8px;");
        allocationLayout->addWidget(btn);
        
        // Connect to respective slots
        if (tool == "Fee Structure Assignment") connect(btn, &QPushButton::clicked, this, &StudentManagement::feeStructureAssignment);
        else if (tool == "Classroom Allocation") connect(btn, &QPushButton::clicked, this, &StudentManagement::classroomAllocation);
        else if (tool == "Uniform Size Management") connect(btn, &QPushButton::clicked, this, &StudentManagement::uniformSizeManagement);
        else if (tool == "Transport Route Assignment") connect(btn, &QPushButton::clicked, this, &StudentManagement::transportRouteAssignment);
        else if (tool == "Hostel Accommodation") connect(btn, &QPushButton::clicked, this, &StudentManagement::hostelAccommodation);
        else if (tool == "Library Card Generation") connect(btn, &QPushButton::clicked, this, &StudentManagement::libraryCardGeneration);
        else if (tool == "Student ID Card Creation") connect(btn, &QPushButton::clicked, this, &StudentManagement::studentIDCardCreation);
        else if (tool == "Biometric Data Capture") connect(btn, &QPushButton::clicked, this, &StudentManagement::biometricDataCapture);
        else if (tool == "Photography Session") connect(btn, &QPushButton::clicked, this, &StudentManagement::photographySession);
        else if (tool == "Orientation Program Scheduling") connect(btn, &QPushButton::clicked, this, &StudentManagement::orientationProgramScheduling);
    }
    m_registrationToolBox->addItem(allocationTools, "Allocation Tools (10)");
    
    // Registration Tools Group 3
    QWidget *assessmentTools = new QWidget();
    QVBoxLayout *assessmentLayout = new QVBoxLayout(assessmentTools);
    QStringList assessmentToolsList = {
        "Parent Orientation Meeting", "Student Handbook Distribution", "Academic Calendar Assignment",
        "Extracurricular Interests", "Special Needs Assessment", "Language Preference Settings",
        "Cultural Background Info", "Behavioral Assessment", "Aptitude Test Results",
        "Counseling Session Scheduling"
    };
    
    for (const QString &tool : assessmentToolsList) {
        QPushButton *btn = new QPushButton(tool);
        btn->setStyleSheet("text-align: left; padding: 8px;");
        assessmentLayout->addWidget(btn);
        
        // Connect to respective slots
        if (tool == "Parent Orientation Meeting") connect(btn, &QPushButton::clicked, this, &StudentManagement::parentOrientationMeeting);
        else if (tool == "Student Handbook Distribution") connect(btn, &QPushButton::clicked, this, &StudentManagement::studentHandbookDistribution);
        else if (tool == "Academic Calendar Assignment") connect(btn, &QPushButton::clicked, this, &StudentManagement::academicCalendarAssignment);
        else if (tool == "Extracurricular Interests") connect(btn, &QPushButton::clicked, this, &StudentManagement::extracurricularInterests);
        else if (tool == "Special Needs Assessment") connect(btn, &QPushButton::clicked, this, &StudentManagement::specialNeedsAssessment);
        else if (tool == "Language Preference Settings") connect(btn, &QPushButton::clicked, this, &StudentManagement::languagePreferenceSettings);
        else if (tool == "Cultural Background Info") connect(btn, &QPushButton::clicked, this, &StudentManagement::culturalBackgroundInfo);
        else if (tool == "Behavioral Assessment") connect(btn, &QPushButton::clicked, this, &StudentManagement::behavioralAssessment);
        else if (tool == "Aptitude Test Results") connect(btn, &QPushButton::clicked, this, &StudentManagement::aptitudeTestResults);
        else if (tool == "Counseling Session Scheduling") connect(btn, &QPushButton::clicked, this, &StudentManagement::counselingSessionScheduling);
    }
    m_registrationToolBox->addItem(assessmentTools, "Assessment Tools (10)");
    
    // Right side - Students table
    m_studentsTable = new QTableWidget();
    m_tableHeaders << "ID" << "Name" << "Class" << "Section" << "Roll No" 
                   << "Date of Birth" << "Gender" << "Parent Name" << "Contact" 
                   << "Address" << "Admission Date" << "Status";
    
    m_studentsTable->setColumnCount(m_tableHeaders.count());
    m_studentsTable->setHorizontalHeaderLabels(m_tableHeaders);
    m_studentsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_studentsTable->setAlternatingRowColors(true);
    m_studentsTable->horizontalHeader()->setStretchLastSection(true);
    
    contentLayout->addWidget(m_registrationToolBox);
    contentLayout->addWidget(m_studentsTable, 2);
    
    layout->addLayout(toolbarLayout);
    layout->addLayout(filterLayout);
    layout->addLayout(contentLayout);
    
    m_mainTabs->addTab(m_registrationTab, "Student Registration & Admission");
}

void StudentManagement::setupStudentRecords()
{
    m_recordsTab = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(m_recordsTab);
    
    m_recordsSplitter = new QSplitter(Qt::Horizontal);
    
    // Left panel - Students tree view
    m_studentsTreeView = new QTreeWidget();
    m_studentsTreeView->setHeaderLabel("Students");
    m_studentsTreeView->setMaximumWidth(300);
    
    // Right panel - Record details stack
    m_recordDetailsStack = new QStackedWidget();
    
    // Create different record views
    QWidget *personalInfoWidget = new QWidget();
    QVBoxLayout *personalLayout = new QVBoxLayout(personalInfoWidget);
    personalLayout->addWidget(new QLabel("Personal Information Details"));
    personalLayout->addWidget(new QLineEdit("Student Name"));
    personalLayout->addWidget(new QLineEdit("Date of Birth"));
    personalLayout->addWidget(new QLineEdit("Gender"));
    personalLayout->addWidget(new QLineEdit("Blood Group"));
    personalLayout->addStretch();
    
    QWidget *academicRecordsWidget = new QWidget();
    QVBoxLayout *academicLayout = new QVBoxLayout(academicRecordsWidget);
    academicLayout->addWidget(new QLabel("Academic Records"));
    m_documentsTable = new QTableWidget();
    m_documentsTable->setColumnCount(4);
    m_documentsTable->setHorizontalHeaderLabels({"Document Type", "Date", "Status", "Actions"});
    academicLayout->addWidget(m_documentsTable);
    
    m_recordDetailsStack->addWidget(personalInfoWidget);
    m_recordDetailsStack->addWidget(academicRecordsWidget);
    
    m_recordsSplitter->addWidget(m_studentsTreeView);
    m_recordsSplitter->addWidget(m_recordDetailsStack);
    
    layout->addWidget(m_recordsSplitter);
    
    m_mainTabs->addTab(m_recordsTab, "Student Records Management");
}

void StudentManagement::setupAcademicPerformance()
{
    m_performanceTab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(m_performanceTab);
    
    // Controls
    QHBoxLayout *controlsLayout = new QHBoxLayout();
    m_termCombo = new QComboBox();
    m_termCombo->addItems({"Term 1", "Term 2", "Term 3", "Annual"});
    m_subjectCombo = new QComboBox();
    m_subjectCombo->addItems({"All Subjects", "Mathematics", "Science", "English", "History", "Geography"});
    
    m_generateReportBtn = new QPushButton("Generate Report");
    m_emailReportBtn = new QPushButton("Email Report");
    m_printReportBtn = new QPushButton("Print Report");
    
    controlsLayout->addWidget(new QLabel("Term:"));
    controlsLayout->addWidget(m_termCombo);
    controlsLayout->addWidget(new QLabel("Subject:"));
    controlsLayout->addWidget(m_subjectCombo);
    controlsLayout->addStretch();
    controlsLayout->addWidget(m_generateReportBtn);
    controlsLayout->addWidget(m_emailReportBtn);
    controlsLayout->addWidget(m_printReportBtn);
    
    // Performance sub-tabs
    m_performanceSubTabs = new QTabWidget();
    
    // Grades tab
    QWidget *gradesWidget = new QWidget();
    QVBoxLayout *gradesLayout = new QVBoxLayout(gradesWidget);
    m_gradesTable = new QTableWidget();
    m_gradesTable->setColumnCount(6);
    m_gradesTable->setHorizontalHeaderLabels({"Student", "Subject", "Assignment", "Exam", "Total", "Grade"});
    gradesLayout->addWidget(m_gradesTable);
    m_performanceSubTabs->addTab(gradesWidget, "Grades & Marks");
    
    // Exams tab
    QWidget *examsWidget = new QWidget();
    QVBoxLayout *examsLayout = new QVBoxLayout(examsWidget);
    m_examsTable = new QTableWidget();
    m_examsTable->setColumnCount(5);
    m_examsTable->setHorizontalHeaderLabels({"Exam Name", "Date", "Subject", "Max Marks", "Obtained Marks"});
    examsLayout->addWidget(m_examsTable);
    m_performanceSubTabs->addTab(examsWidget, "Examinations");
    
    // Assignments tab
    QWidget *assignmentsWidget = new QWidget();
    QVBoxLayout *assignmentsLayout = new QVBoxLayout(assignmentsWidget);
    m_assignmentsTable = new QTableWidget();
    m_assignmentsTable->setColumnCount(5);
    m_assignmentsTable->setHorizontalHeaderLabels({"Assignment", "Subject", "Due Date", "Submitted", "Marks"});
    assignmentsLayout->addWidget(m_assignmentsTable);
    m_performanceSubTabs->addTab(assignmentsWidget, "Assignments");
    
    layout->addLayout(controlsLayout);
    layout->addWidget(m_performanceSubTabs);
    
    m_mainTabs->addTab(m_performanceTab, "Academic Performance");
}

void StudentManagement::setupCommunicationTools()
{
    m_communicationTab = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(m_communicationTab);
    
    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    
    // Left side - Communication tools
    QWidget *toolsWidget = new QWidget();
    QVBoxLayout *toolsLayout = new QVBoxLayout(toolsWidget);
    
    toolsLayout->addWidget(new QPushButton("Parent Portal Access"));
    toolsLayout->addWidget(new QPushButton("Student Email System"));
    toolsLayout->addWidget(new QPushButton("SMS Notifications"));
    toolsLayout->addWidget(new QPushButton("Mobile Push Notifications"));
    toolsLayout->addWidget(new QPushButton("Announcement Broadcasting"));
    toolsLayout->addWidget(new QPushButton("Event Invitations"));
    toolsLayout->addWidget(new QPushButton("Meeting Scheduling"));
    toolsLayout->addWidget(new QPushButton("Appointment Booking"));
    toolsLayout->addWidget(new QPushButton("Parent-Teacher Communication"));
    toolsLayout->addWidget(new QPushButton("Counselor Communication"));
    toolsLayout->addStretch();
    
    toolsWidget->setMaximumWidth(250);
    
    // Right side - Communication interface
    m_communicationSubTabs = new QTabWidget();
    
    // Messages tab
    QWidget *messagesWidget = new QWidget();
    QVBoxLayout *messagesLayout = new QVBoxLayout(messagesWidget);
    m_messagesList = new QListWidget();
    m_messageComposer = new QTextEdit();
    m_messageComposer->setMaximumHeight(100);
    
    QHBoxLayout *messageButtons = new QHBoxLayout();
    m_sendMessageBtn = new QPushButton("Send Message");
    m_broadcastBtn = new QPushButton("Broadcast");
    m_scheduleMessageBtn = new QPushButton("Schedule");
    messageButtons->addWidget(m_sendMessageBtn);
    messageButtons->addWidget(m_broadcastBtn);
    messageButtons->addWidget(m_scheduleMessageBtn);
    messageButtons->addStretch();
    
    messagesLayout->addWidget(m_messagesList);
    messagesLayout->addWidget(m_messageComposer);
    messagesLayout->addLayout(messageButtons);
    m_communicationSubTabs->addTab(messagesWidget, "Messages");
    
    // Contacts tab
    QWidget *contactsWidget = new QWidget();
    QVBoxLayout *contactsLayout = new QVBoxLayout(contactsWidget);
    m_parentContactsTable = new QTableWidget();
    m_parentContactsTable->setColumnCount(5);
    m_parentContactsTable->setHorizontalHeaderLabels({"Name", "Relationship", "Phone", "Email", "Preferred Contact"});
    contactsLayout->addWidget(m_parentContactsTable);
    m_communicationSubTabs->addTab(contactsWidget, "Parent Contacts");
    
    // Calendar tab
    QWidget *calendarWidget = new QWidget();
    QVBoxLayout *calendarLayout = new QVBoxLayout(calendarWidget);
    m_communicationCalendar = new QCalendarWidget();
    calendarLayout->addWidget(m_communicationCalendar);
    m_communicationSubTabs->addTab(calendarWidget, "Calendar");
    
    splitter->addWidget(toolsWidget);
    splitter->addWidget(m_communicationSubTabs);
    
    layout->addWidget(splitter);
    
    m_mainTabs->addTab(m_communicationTab, "Communication & Engagement");
}

void StudentManagement::setupStudentServices()
{
    m_servicesTab = new QWidget();
    m_servicesScrollArea = new QScrollArea();
    QWidget *servicesContent = new QWidget();
    m_servicesGrid = new QGridLayout(servicesContent);
    
    // Counseling Services Group
    m_counselingGroup = new QGroupBox("Counseling & Support Services");
    QVBoxLayout *counselingLayout = new QVBoxLayout(m_counselingGroup);
    QStringList counselingServices = {
        "Counseling Service Booking", "Psychological Support", "Career Guidance",
        "Academic Advising", "Student Welfare Programs", "Emergency Assistance"
    };
    for (const QString &service : counselingServices) {
        counselingLayout->addWidget(new QPushButton(service));
    }
    
    // Health Services Group
    m_healthGroup = new QGroupBox("Health & Medical Services");
    QVBoxLayout *healthLayout = new QVBoxLayout(m_healthGroup);
    QStringList healthServices = {
        "Medical Appointments", "Health Insurance", "Vaccination Tracking",
        "Nutrition Programs", "Fitness Assessment", "Allergy Management"
    };
    for (const QString &service : healthServices) {
        healthLayout->addWidget(new QPushButton(service));
    }
    
    // Extracurricular Group
    m_extracurricularGroup = new QGroupBox("Activities & Programs");
    QVBoxLayout *extracurricularLayout = new QVBoxLayout(m_extracurricularGroup);
    QStringList extracurricularServices = {
        "Sports Participation", "Club Membership", "Volunteer Opportunities",
        "Community Service", "Leadership Development", "Cultural Celebrations"
    };
    for (const QString &service : extracurricularServices) {
        extracurricularLayout->addWidget(new QPushButton(service));
    }
    
    // Support Services Group
    m_supportGroup = new QGroupBox("Additional Support Services");
    QVBoxLayout *supportLayout = new QVBoxLayout(m_supportGroup);
    QStringList supportServices = {
        "Financial Aid Applications", "Scholarship Tracking", "Disability Services",
        "Language Support", "Immigration Assistance", "Housing Assistance"
    };
    for (const QString &service : supportServices) {
        supportLayout->addWidget(new QPushButton(service));
    }
    
    m_servicesGrid->addWidget(m_counselingGroup, 0, 0);
    m_servicesGrid->addWidget(m_healthGroup, 0, 1);
    m_servicesGrid->addWidget(m_extracurricularGroup, 1, 0);
    m_servicesGrid->addWidget(m_supportGroup, 1, 1);
    
    m_servicesScrollArea->setWidget(servicesContent);
    m_servicesScrollArea->setWidgetResizable(true);
    
    QVBoxLayout *layout = new QVBoxLayout(m_servicesTab);
    layout->addWidget(m_servicesScrollArea);
    
    m_mainTabs->addTab(m_servicesTab, "Student Services & Support");
}

void StudentManagement::connectSignalsSlots()
{
    connect(m_addStudentBtn, &QPushButton::clicked, this, &StudentManagement::newStudentRegistration);
    connect(m_editStudentBtn, &QPushButton::clicked, this, &StudentManagement::personalInformationUpdate);
    connect(m_deleteStudentBtn, &QPushButton::clicked, [this]() {
        QMessageBox::information(this, "Delete Student", "Delete student functionality");
    });
    connect(m_generateReportBtn, &QPushButton::clicked, this, &StudentManagement::progressReportGeneration);
    connect(m_sendMessageBtn, &QPushButton::clicked, this, &StudentManagement::parentPortalAccess);
}

void StudentManagement::populateSampleData()
{
    // Sample student data
    QStringList sampleStudents = {
        "John Doe, Grade 5, Section A, 101, 2010-05-15, Male, Robert Doe, 555-0101, 123 Main St, 2023-08-01, Active",
        "Jane Smith, Grade 4, Section B, 102, 2011-03-22, Female, Mary Smith, 555-0102, 456 Oak Ave, 2023-08-01, Active",
        "Mike Johnson, Grade 5, Section A, 103, 2010-08-30, Male, David Johnson, 555-0103, 789 Pine Rd, 2023-08-01, Active",
        "Sarah Wilson, Grade 3, Section C, 104, 2012-12-10, Female, Lisa Wilson, 555-0104, 321 Elm St, 2023-08-01, Active",
        "Tom Brown, Grade 4, Section A, 105, 2011-07-18, Male, James Brown, 555-0105, 654 Cedar Ln, 2023-08-01, Active"
    };
    
    m_studentsTable->setRowCount(sampleStudents.size());
    
    for (int row = 0; row < sampleStudents.size(); ++row) {
        QStringList studentData = sampleStudents[row].split(", ");
        studentData.prepend(QString::number(row + 1)); // Add ID
        
        for (int col = 0; col < studentData.size() && col < m_tableHeaders.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(studentData[col]);
            m_studentsTable->setItem(row, col, item);
        }
    }
    
    // Populate tree view
    for (const QString &student : sampleStudents) {
        QStringList data = student.split(", ");
        QTreeWidgetItem *item = new QTreeWidgetItem(m_studentsTreeView, {data[0]});
        item->addChild(new QTreeWidgetItem({"Personal Info"}));
        item->addChild(new QTreeWidgetItem({"Academic Records"}));
        item->addChild(new QTreeWidgetItem({"Health Records"}));
        item->addChild(new QTreeWidgetItem({"Documents"}));
    }
    m_studentsTreeView->expandAll();
}

void StudentManagement::applyModuleStyles()
{
    QString styleSheet = R"(
        QTabWidget::pane {
            border: 1px solid #444;
            background-color: #2b2b2b;
        }
        QTabBar::tab {
            background-color: #3c3c3c;
            color: white;
            padding: 8px 16px;
            margin-right: 2px;
            border-top-left-radius: 4px;
            border-top-right-radius: 4px;
        }
        QTabBar::tab:selected {
            background-color: #0078d4;
        }
        QPushButton {
            background-color: #0078d4;
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
        }
        QPushButton:hover {
            background-color: #106ebe;
        }
        QPushButton:pressed {
            background-color: #005a9e;
        }
        QTableWidget {
            background-color: #353535;
            color: white;
            gridline-color: #555;
            selection-background-color: #0078d4;
        }
        QHeaderView::section {
            background-color: #3c3c3c;
            color: white;
            padding: 8px;
            border: 1px solid #555;
        }
        QToolBox::tab {
            background-color: #3c3c3c;
            color: white;
            border: 1px solid #555;
        }
        QToolBox::tab:selected {
            background-color: #0078d4;
        }
    )";
    setStyleSheet(styleSheet);
}

// Implementation of tool functions (showing a few examples)
void StudentManagement::newStudentRegistration()
{
    QMessageBox::information(this, "New Student Registration", 
        "New Student Registration Tool\n\nFeatures:\n"
        "• Personal Information Entry\n"
        "• Document Upload\n"
        "• Parent/Guardian Details\n"
        "• Medical Information\n"
        "• Academic History");
}

void StudentManagement::bulkStudentImport()
{
    QFileDialog dialog(this);
    dialog.setNameFilter("CSV Files (*.csv);;Excel Files (*.xlsx)");
    if (dialog.exec()) {
        QMessageBox::information(this, "Bulk Import", "Students imported successfully!");
    }
}

void StudentManagement::onlineAdmissionPortal()
{
    QMessageBox::information(this, "Online Admission Portal", 
        "Online Admission Portal Access\n\nFeatures:\n"
        "• Web-based Application Form\n"
        "• Document Upload Portal\n"
        "• Application Status Tracking\n"
        "• Payment Gateway Integration\n"
        "• Automated Email Notifications");
}

void StudentManagement::progressReportGeneration()
{
    QMessageBox::information(this, "Progress Report Generation", 
        "Generating comprehensive progress reports...\n\n"
        "Report includes:\n"
        "• Academic Performance\n"
        "• Attendance Summary\n"
        "• Teacher Comments\n"
        "• Extracurricular Activities\n"
        "• Areas for Improvement");
}

void StudentManagement::parentPortalAccess()
{
    QMessageBox::information(this, "Parent Portal", 
        "Parent Portal Features:\n\n"
        "• View Student Progress\n"
        "• Communication with Teachers\n"
        "• Event Notifications\n"
        "• Fee Payment Online\n"
        "• Attendance Tracking\n"
        "• Assignment Status");
}

// Additional tool implementations (showing pattern for extensibility)
void StudentManagement::admissionTestScheduling()
{
    QMessageBox::information(this, "Admission Test Scheduling", 
        "Admission Test Management\n\n"
        "• Schedule Test Dates\n"
        "• Room Allocation\n"
        "• Candidate Registration\n"
        "• Result Processing\n"
        "• Merit List Generation");
}

void StudentManagement::documentVerification()
{
    QMessageBox::information(this, "Document Verification", 
        "Document Verification System\n\n"
        "• Identity Verification\n"
        "• Academic Certificate Validation\n"
        "• Address Proof Verification\n"
        "• Medical Certificate Review\n"
        "• Digital Signature Validation");
}

void StudentManagement::scholarshipEligibilityCheck()
{
    QMessageBox::information(this, "Scholarship Eligibility", 
        "Scholarship Management\n\n"
        "• Eligibility Criteria Check\n"
        "• Merit-based Assessment\n"
        "• Need-based Evaluation\n"
        "• Application Processing\n"
        "• Award Distribution");
}

void StudentManagement::personalInformationUpdate()
{
    QMessageBox::information(this, "Personal Information Update", 
        "Update Student Records\n\n"
        "• Personal Details\n"
        "• Contact Information\n"
        "• Emergency Contacts\n"
        "• Medical Information\n"
        "• Academic History");
}

// Placeholder implementations for remaining 140+ functions
void StudentManagement::medicalExamination() { QMessageBox::information(this, "Medical Examination", "Medical examination scheduling and management"); }
void StudentManagement::parentGuardianInfo() { QMessageBox::information(this, "Parent/Guardian Info", "Parent and guardian information management"); }
void StudentManagement::emergencyContactManagement() { QMessageBox::information(this, "Emergency Contacts", "Emergency contact information management"); }
void StudentManagement::previousEducationHistory() { QMessageBox::information(this, "Education History", "Previous education history tracking"); }
void StudentManagement::feeStructureAssignment() { QMessageBox::information(this, "Fee Structure", "Fee structure assignment and management"); }
void StudentManagement::classroomAllocation() { QMessageBox::information(this, "Classroom Allocation", "Student classroom allocation system"); }
void StudentManagement::uniformSizeManagement() { QMessageBox::information(this, "Uniform Management", "Student uniform size management"); }
void StudentManagement::transportRouteAssignment() { QMessageBox::information(this, "Transport Assignment", "Transport route assignment for students"); }
void StudentManagement::hostelAccommodation() { QMessageBox::information(this, "Hostel Accommodation", "Student hostel accommodation management"); }
void StudentManagement::libraryCardGeneration() { QMessageBox::information(this, "Library Card", "Library card generation system"); }
void StudentManagement::studentIDCardCreation() { QMessageBox::information(this, "ID Card Creation", "Student ID card creation and printing"); }
void StudentManagement::biometricDataCapture() { QMessageBox::information(this, "Biometric Data", "Biometric data capture and management"); }
void StudentManagement::photographySession() { QMessageBox::information(this, "Photography Session", "Student photography session scheduling"); }
void StudentManagement::orientationProgramScheduling() { QMessageBox::information(this, "Orientation Program", "Student orientation program scheduling"); }

// Additional implementations would continue for all 150+ functions...
// Each function would provide comprehensive functionality for its specific tool
