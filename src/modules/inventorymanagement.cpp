#include "../../include/modules/inventorymanagement.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

InventoryManagement::InventoryManagement(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Inventory Management Module"));
    layout->addWidget(new QPushButton("Asset Tracking"));
    layout->addWidget(new QPushButton("Procurement Management"));
    layout->addWidget(new QPushButton("Equipment Maintenance"));
    layout->addWidget(new QPushButton("Stock Management"));
    layout->addStretch();
    
    setStyleSheet("QLabel { color: white; font-size: 16px; font-weight: bold; } QPushButton { background-color: #0078d4; color: white; padding: 8px; border-radius: 4px; }");
}
