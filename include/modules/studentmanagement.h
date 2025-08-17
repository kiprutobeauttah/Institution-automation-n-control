#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTabWidget>
#include <QTableWidget>
#include <QTreeWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QGroupBox>
#include <QLabel>
#include <QFrame>
#include <QScrollArea>
#include <QProgressBar>
#include <QSlider>
#include <QDial>
#include <QCalendarWidget>
#include <QSplitter>
#include <QStackedWidget>
#include <QToolBox>
#include <QDialog>
#include <QWizard>
#include <QFileDialog>
#include <QColorDialog>
#include <QPrintDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QProgressDialog>
#include <QErrorMessage>

class StudentManagement : public QWidget
{
    Q_OBJECT

public:
    explicit StudentManagement(QWidget *parent = nullptr);

private slots:
    // Student Registration & Admission (30+ tools)
    void newStudentRegistration();
    void bulkStudentImport();
    void onlineAdmissionPortal();
    void admissionTestScheduling();
    void documentVerification();
    void medicalExamination();
    void parentGuardianInfo();
    void emergencyContactManagement();
    void previousEducationHistory();
    void scholarshipEligibilityCheck();
    void feeStructureAssignment();
    void classroomAllocation();
    void uniformSizeManagement();
    void transportRouteAssignment();
    void hostelAccommodation();
    void libraryCardGeneration();
    void studentIDCardCreation();
    void biometricDataCapture();
    void photographySession();
    void orientationProgramScheduling();
    void parentOrientationMeeting();
    void studentHandbookDistribution();
    void academicCalendarAssignment();
    void extracurricularInterests();
    void specialNeedsAssessment();
    void languagePreferenceSettings();
    void culturalBackgroundInfo();
    void behavioralAssessment();
    void aptitudeTestResults();
    void counselingSessionScheduling();

    // Student Records Management (30+ tools)
    void personalInformationUpdate();
    void contactDetailsManagement();
    void familyInformationTracking();
    void academicRecordsManagement();
    void attendanceHistoryView();
    void disciplinaryRecordsTracking();
    void healthRecordsManagement();
    void vaccinationStatusTracking();
    void allergyInformationManagement();
    void medicationTrackingSystem();
    void psychologicalEvaluationRecords();
    void specialEducationNeeds();
    void talentIdentificationRecords();
    void achievementPortfolio();
    void extracurricularParticipation();
    void leadershipRolesTracking();
    void communityServiceRecords();
    void internshipExperienceTracking();
    void skillDevelopmentPrograms();
    void certificationManagement();
    void competitionParticipation();
    void scholarshipRecordsManagement();
    void financialAssistanceTracking();
    void parentFeedbackCollection();
    void teacherRecommendations();
    void peerEvaluationRecords();
    void selfAssessmentTools();
    void careerGuidanceSessions();
    void collegeApplicationTracking();
    void graduationRequirements();

    // Academic Performance Tracking (30+ tools)
    void gradeBookManagement();
    void examResultsTracking();
    void assignmentSubmissionSystem();
    void projectEvaluationTools();
    void continuousAssessmentTracking();
    void skillBasedEvaluation();
    void competencyMapping();
    void learningOutcomeAssessment();
    void progressReportGeneration();
    void parentReportCards();
    void teacherEvaluationForms();
    void subjectWisePerformance();
    void termWiseAnalysis();
    void yearlyProgressTracking();
    void comparativePerformanceAnalysis();
    void classRankingSystem();
    void gradePointAverageCalculation();
    void academicProbationTracking();
    void honorsListManagement();
    void deansList();
    void meritBadgeSystem();
    void improvementPlanCreation();
    void parentTeacherConferences();
    void studyGroupFormation();
    void tutoringNeedsAssessment();
    void remedialClassScheduling();
    void advancedLearnerPrograms();
    void giftedeEducationTracking();
    void specialProjectsManagement();
    void researchOpportunities();

    // Student Communication & Engagement (30+ tools)
    void parentPortalAccess();
    void studentEmailSystem();
    void smsNotificationService();
    void mobilePushNotifications();
    void announcementBroadcasting();
    void eventInvitationSystem();
    void meetingSchedulingTools();
    void appointmentBookingSystem();
    void parentTeacherCommunication();
    void counselorCommunication();
    void principalOfficeAppointments();
    void grievanceManagementSystem();
    void feedbackCollectionPortal();
    void surveyCreationTools();
    void pollConductionSystem();
    void discussionForumManagement();
    void studentBlogPlatform();
    void socialMediaIntegration();
    void newsletterManagement();
    void photographGallerySharing();
    void videoConferencingSetup();
    void virtualClassroomAccess();
    void onlineTutoringPlatform();
    void peerConnectionNetwork();
    void mentorshipProgramMatching();
    void alumniNetworkAccess();
    void careerCounselingPortal();
    void collegeAdmissionGuidance();
    void internshipOpportunityPortal();
    void jobPlacementAssistance();

    // Student Services & Support (30+ tools)
    void counselingServiceBooking();
    void psychologicalSupportServices();
    void careerGuidanceSessions();
    void academicAdvisingMeetings();
    void studentWelfarePrograms();
    void financialAidApplications();
    void scholarshipApplicationTracking();
    void loanApplicationProcessing();
    void workStudyProgramManagement();
    void emergencyAssistancePrograms();
    void healthInsuranceManagement();
    void medicalAppointmentScheduling();
    void nutritionProgramTracking();
    void fitnessAssessmentTools();
    void sportsParticipationManagement();
    void clubMembershipTracking();
    void volunteerOpportunityMatching();
    void communityServiceVerification();
    void leadershipDevelopmentPrograms();
    void conflictResolutionServices();
    void peerMediationPrograms();
    void antibullyingInitiatives();
    void diversityInclusionPrograms();
    void culturalCelebrationPlanning();
    void religiousAccommodationServices();
    void disabilityServicesCoordination();
    void languageSupportServices();
    void immigrationStatusAssistance();
    void legalAidReferralServices();
    void housingAssistancePrograms();

private:
    void setupUI();
    void setupStudentRegistration();
    void setupStudentRecords();
    void setupAcademicPerformance();
    void setupCommunicationTools();
    void setupStudentServices();
    void connectSignalsSlots();
    void populateSampleData();
    void applyModuleStyles();

    // UI Components
    QTabWidget *m_mainTabs;
    QVBoxLayout *m_mainLayout;
    
    // Student Registration Tab
    QWidget *m_registrationTab;
    QToolBox *m_registrationToolBox;
    QStackedWidget *m_registrationStack;
    QTableWidget *m_studentsTable;
    QPushButton *m_addStudentBtn;
    QPushButton *m_editStudentBtn;
    QPushButton *m_deleteStudentBtn;
    QPushButton *m_searchStudentBtn;
    QPushButton *m_exportStudentsBtn;
    QPushButton *m_importStudentsBtn;
    QLineEdit *m_studentSearchBox;
    QComboBox *m_classFilterCombo;
    QComboBox *m_sectionFilterCombo;
    
    // Student Records Tab
    QWidget *m_recordsTab;
    QSplitter *m_recordsSplitter;
    QTreeWidget *m_studentsTreeView;
    QStackedWidget *m_recordDetailsStack;
    QPushButton *m_updateRecordBtn;
    QPushButton *m_printRecordBtn;
    QPushButton *m_emailRecordBtn;
    QTextEdit *m_notesTextEdit;
    QTableWidget *m_documentsTable;
    
    // Academic Performance Tab
    QWidget *m_performanceTab;
    QTabWidget *m_performanceSubTabs;
    QTableWidget *m_gradesTable;
    QTableWidget *m_examsTable;
    QTableWidget *m_assignmentsTable;
    QPushButton *m_generateReportBtn;
    QPushButton *m_emailReportBtn;
    QPushButton *m_printReportBtn;
    QProgressBar *m_overallProgressBar;
    QComboBox *m_termCombo;
    QComboBox *m_subjectCombo;
    
    // Communication Tab
    QWidget *m_communicationTab;
    QTabWidget *m_communicationSubTabs;
    QListWidget *m_messagesList;
    QTextEdit *m_messageComposer;
    QPushButton *m_sendMessageBtn;
    QPushButton *m_broadcastBtn;
    QPushButton *m_scheduleMessageBtn;
    QTableWidget *m_parentContactsTable;
    QCalendarWidget *m_communicationCalendar;
    
    // Student Services Tab
    QWidget *m_servicesTab;
    QGridLayout *m_servicesGrid;
    QScrollArea *m_servicesScrollArea;
    QGroupBox *m_counselingGroup;
    QGroupBox *m_healthGroup;
    QGroupBox *m_extracurricularGroup;
    QGroupBox *m_supportGroup;
    
    // Data storage
    QList<QStringList> m_studentsData;
    QStringList m_tableHeaders;
    
    // Settings
    QString m_currentStudent;
    int m_selectedStudentId;
    bool m_isEditMode;
};

#endif // STUDENTMANAGEMENT_H
