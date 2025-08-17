#include "../../include/modules/feesfinancemanagement.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

FeesFinanceManagement::FeesFinanceManagement(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Fees & Finance Management Module"));
    layout->addWidget(new QPushButton("Fee Collection"));
    layout->addWidget(new QPushButton("Payment Processing"));
    layout->addWidget(new QPushButton("Financial Reports"));
    layout->addWidget(new QPushButton("Scholarship Management"));
    layout->addStretch();
    
    setStyleSheet("QLabel { color: white; font-size: 16px; font-weight: bold; } QPushButton { background-color: #0078d4; color: white; padding: 8px; border-radius: 4px; }");
}
