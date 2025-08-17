#include "../../include/modules/attendancemanagement.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

AttendanceManagement::AttendanceManagement(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Attendance Management Module"));
    layout->addWidget(new QPushButton("Daily Attendance"));
    layout->addWidget(new QPushButton("Attendance Reports"));
    layout->addWidget(new QPushButton("Biometric Integration"));
    layout->addWidget(new QPushButton("Leave Management"));
    layout->addStretch();
    
    setStyleSheet("QLabel { color: white; font-size: 16px; font-weight: bold; } QPushButton { background-color: #0078d4; color: white; padding: 8px; border-radius: 4px; }");
}
