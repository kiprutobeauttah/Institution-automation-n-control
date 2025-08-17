#!/usr/bin/env python3
"""
Institution Automation & Control System v2.0
Architecture Diagram Generator

This script generates visual architecture diagrams for the project.
Requirements: pip install matplotlib seaborn

Usage: python generate_architecture_diagram.py
"""

import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from matplotlib.patches import FancyBboxPatch, Rectangle
import seaborn as sns

def create_architecture_diagram():
    """Create and save the system architecture diagram"""
    
    # Set up the figure with dark theme
    plt.style.use('dark_background')
    fig, ax = plt.subplots(figsize=(16, 12))
    fig.suptitle('Institution Automation & Control System v2.0\nSystem Architecture', 
                 fontsize=20, fontweight='bold', color='white', y=0.98)
    
    # Define colors
    colors = {
        'presentation': '#2E86AB',
        'business': '#A23B72',
        'data': '#F18F01',
        'integration': '#C73E1D',
        'student': '#4CAF50',
        'other_modules': '#FF9800',
        'background': '#1e1e1e',
        'text': 'white',
        'border': '#555555'
    }
    
    # Layer heights
    layers = {
        'presentation': 0.8,
        'business': 0.6,
        'data': 0.4,
        'integration': 0.2
    }
    
    # Draw layer backgrounds
    for layer, y_pos in layers.items():
        rect = FancyBboxPatch((0.05, y_pos-0.08), 0.9, 0.15, 
                             boxstyle="round,pad=0.01",
                             facecolor=colors[layer], alpha=0.3,
                             edgecolor=colors['border'], linewidth=2)
        ax.add_patch(rect)
    
    # Presentation Layer
    ax.text(0.5, 0.87, 'PRESENTATION LAYER', ha='center', va='center',
            fontsize=16, fontweight='bold', color=colors['text'])
    
    # Main Window Components
    components_pres = [
        'Main Window\n(QMainWindow)', 'Navigation Tree\n(QTreeWidget)', 
        'System Tray\n(QSystemTrayIcon)', 'Menu & Toolbar\n(QMenuBar/QToolBar)'
    ]
    
    x_positions = [0.15, 0.35, 0.55, 0.75]
    for i, comp in enumerate(components_pres):
        rect = FancyBboxPatch((x_positions[i]-0.06, 0.82), 0.12, 0.04,
                             boxstyle="round,pad=0.005",
                             facecolor=colors['presentation'], alpha=0.8,
                             edgecolor='white', linewidth=1)
        ax.add_patch(rect)
        ax.text(x_positions[i], 0.84, comp, ha='center', va='center',
                fontsize=9, color='white', fontweight='bold')
    
    # Business Layer
    ax.text(0.5, 0.67, 'BUSINESS LAYER', ha='center', va='center',
            fontsize=16, fontweight='bold', color=colors['text'])
    
    # Student Management (Highlighted as main module)
    student_rect = FancyBboxPatch((0.1, 0.6), 0.35, 0.06,
                                 boxstyle="round,pad=0.01",
                                 facecolor=colors['student'], alpha=0.9,
                                 edgecolor='white', linewidth=2)
    ax.add_patch(student_rect)
    ax.text(0.275, 0.63, 'STUDENT MANAGEMENT\n150+ Tools (5 Categories)', 
            ha='center', va='center', fontsize=11, color='white', fontweight='bold')
    
    # Other Business Modules
    other_modules = [
        'Teacher\nManagement\n(90+ Tools)',
        'Finance & Fees\nManagement\n(75+ Tools)',
        'Attendance\nManagement\n(60+ Tools)',
        'Inventory\nManagement\n(45+ Tools)'
    ]
    
    x_positions_business = [0.55, 0.7, 0.85, 0.55]
    y_positions_business = [0.62, 0.62, 0.62, 0.56]
    widths = [0.12, 0.12, 0.12, 0.37]
    
    for i, module in enumerate(other_modules):
        if i < 3:  # First row
            rect = FancyBboxPatch((x_positions_business[i]-0.06, y_positions_business[i]), 
                                 widths[i], 0.04,
                                 boxstyle="round,pad=0.005",
                                 facecolor=colors['other_modules'], alpha=0.8,
                                 edgecolor='white', linewidth=1)
            ax.add_patch(rect)
            ax.text(x_positions_business[i], y_positions_business[i]+0.02, module,
                   ha='center', va='center', fontsize=9, color='white', fontweight='bold')
        else:  # Second row - combined remaining modules
            rect = FancyBboxPatch((0.55, 0.56), 0.37, 0.04,
                                 boxstyle="round,pad=0.005",
                                 facecolor=colors['other_modules'], alpha=0.8,
                                 edgecolor='white', linewidth=1)
            ax.add_patch(rect)
            ax.text(0.735, 0.58, 'Future Modules: Exam, Library, Transport, Hostel,\nEvents, Communication, Reports, Security, HR', 
                   ha='center', va='center', fontsize=9, color='white', fontweight='bold')
            break
    
    # Data Layer
    ax.text(0.5, 0.47, 'DATA LAYER', ha='center', va='center',
            fontsize=16, fontweight='bold', color=colors['text'])
    
    data_components = [
        'Data Models\n(Qt Containers)', 'File I/O\n(CSV/Excel/PDF)', 
        'Settings\n(QSettings)', 'Future Database\n(MySQL/PostgreSQL)'
    ]
    
    x_positions_data = [0.18, 0.38, 0.58, 0.78]
    for i, comp in enumerate(data_components):
        rect = FancyBboxPatch((x_positions_data[i]-0.06, 0.42), 0.12, 0.04,
                             boxstyle="round,pad=0.005",
                             facecolor=colors['data'], alpha=0.8,
                             edgecolor='white', linewidth=1)
        ax.add_patch(rect)
        ax.text(x_positions_data[i], 0.44, comp, ha='center', va='center',
                fontsize=9, color='white', fontweight='bold')
    
    # Integration Layer
    ax.text(0.5, 0.27, 'INTEGRATION LAYER', ha='center', va='center',
            fontsize=16, fontweight='bold', color=colors['text'])
    
    integration_components = [
        'Email\nServices', 'SMS\nGateway', 'Biometric\nDevices', 
        'Payment\nGateway', 'Cloud\nBackup'
    ]
    
    x_positions_int = [0.15, 0.28, 0.41, 0.54, 0.67, 0.8]
    for i, comp in enumerate(integration_components):
        rect = FancyBboxPatch((x_positions_int[i]-0.05, 0.22), 0.1, 0.04,
                             boxstyle="round,pad=0.005",
                             facecolor=colors['integration'], alpha=0.8,
                             edgecolor='white', linewidth=1)
        ax.add_patch(rect)
        ax.text(x_positions_int[i], 0.24, comp, ha='center', va='center',
                fontsize=9, color='white', fontweight='bold')
    
    # Add technology stack info
    tech_info = """Technology Stack:
• Qt6 C++ Framework
• CMake Build System
• C++17 Standards
• Cross-platform Support
• Professional Dark UI Theme"""
    
    ax.text(0.02, 0.15, tech_info, fontsize=10, color=colors['text'],
            verticalalignment='top', fontfamily='monospace',
            bbox=dict(boxstyle="round,pad=0.5", facecolor='#2d2d2d', alpha=0.8))
    
    # Add module statistics
    stats_info = """Module Statistics:
• Student Management: 150+ tools
• Teacher Management: 90+ tools  
• Finance Management: 75+ tools
• Attendance System: 60+ tools
• Inventory Control: 45+ tools
• Total: 420+ specialized tools"""
    
    ax.text(0.98, 0.15, stats_info, fontsize=10, color=colors['text'],
            verticalalignment='top', horizontalalignment='right', fontfamily='monospace',
            bbox=dict(boxstyle="round,pad=0.5", facecolor='#2d2d2d', alpha=0.8))
    
    # Add arrows showing data flow
    # Presentation to Business
    ax.annotate('', xy=(0.5, 0.6), xytext=(0.5, 0.8),
                arrowprops=dict(arrowstyle='<->', color='#4CAF50', lw=2))
    
    # Business to Data
    ax.annotate('', xy=(0.5, 0.4), xytext=(0.5, 0.6),
                arrowprops=dict(arrowstyle='<->', color='#FF9800', lw=2))
    
    # Data to Integration
    ax.annotate('', xy=(0.5, 0.2), xytext=(0.5, 0.4),
                arrowprops=dict(arrowstyle='<->', color='#F44336', lw=2))
    
    # Remove axes and set limits
    ax.set_xlim(0, 1)
    ax.set_ylim(0, 1)
    ax.axis('off')
    
    # Add legend
    legend_elements = [
        mpatches.Rectangle((0, 0), 1, 1, facecolor=colors['presentation'], alpha=0.8, label='Presentation Layer'),
        mpatches.Rectangle((0, 0), 1, 1, facecolor=colors['student'], alpha=0.9, label='Student Management'),
        mpatches.Rectangle((0, 0), 1, 1, facecolor=colors['other_modules'], alpha=0.8, label='Other Modules'),
        mpatches.Rectangle((0, 0), 1, 1, facecolor=colors['data'], alpha=0.8, label='Data Layer'),
        mpatches.Rectangle((0, 0), 1, 1, facecolor=colors['integration'], alpha=0.8, label='Integration Layer')
    ]
    
    ax.legend(handles=legend_elements, loc='upper right', bbox_to_anchor=(0.98, 0.98),
             framealpha=0.9, facecolor='#2d2d2d', edgecolor='white')
    
    # Save the diagram
    plt.tight_layout()
    plt.savefig('Institution_Architecture_Diagram.png', dpi=300, bbox_inches='tight',
                facecolor='#1e1e1e', edgecolor='none')
    plt.savefig('Institution_Architecture_Diagram.pdf', bbox_inches='tight',
                facecolor='#1e1e1e', edgecolor='none')
    
    print("✅ Architecture diagrams saved:")
    print("   📊 Institution_Architecture_Diagram.png")
    print("   📊 Institution_Architecture_Diagram.pdf")
    
    return fig

def create_student_module_diagram():
    """Create detailed Student Management module architecture"""
    
    plt.style.use('dark_background')
    fig, ax = plt.subplots(figsize=(14, 10))
    fig.suptitle('Student Management Module - Detailed Architecture\n150+ Tools across 5 Categories', 
                 fontsize=18, fontweight='bold', color='white', y=0.95)
    
    # Colors for different tool categories
    category_colors = {
        'registration': '#4CAF50',
        'records': '#2196F3',
        'performance': '#FF9800',
        'communication': '#9C27B0',
        'services': '#F44336'
    }
    
    # Tool categories with their tools
    categories = {
        'Registration & Admission\n(30+ Tools)': {
            'color': category_colors['registration'],
            'position': (0.1, 0.75),
            'tools': ['New Student Registration', 'Bulk Import', 'Online Portal', 
                     'Document Verification', 'Medical Exam', 'Scholarship Check', '...24+ more']
        },
        'Records Management\n(30+ Tools)': {
            'color': category_colors['records'],
            'position': (0.55, 0.75),
            'tools': ['Personal Info Update', 'Academic Records', 'Health Records',
                     'Achievement Portfolio', 'Family Tracking', 'Documents', '...24+ more']
        },
        'Performance Tracking\n(30+ Tools)': {
            'color': category_colors['performance'],
            'position': (0.1, 0.45),
            'tools': ['Grade Book', 'Progress Reports', 'Exam Results',
                     'Competency Mapping', 'Analytics', 'Ranking', '...24+ more']
        },
        'Communication & Engagement\n(30+ Tools)': {
            'color': category_colors['communication'],
            'position': (0.55, 0.45),
            'tools': ['Parent Portal', 'Email System', 'SMS Service',
                     'Virtual Classroom', 'Messaging', 'Notifications', '...24+ more']
        },
        'Student Services & Support\n(30+ Tools)': {
            'color': category_colors['services'],
            'position': (0.325, 0.15),
            'tools': ['Counseling Services', 'Financial Aid', 'Health Insurance',
                     'Disability Support', 'Career Guidance', 'Emergency Aid', '...24+ more']
        }
    }
    
    # Draw category boxes
    for category, info in categories.items():
        x, y = info['position']
        
        # Main category box
        if category.startswith('Student Services'):
            width, height = 0.35, 0.2
        else:
            width, height = 0.35, 0.2
            
        rect = FancyBboxPatch((x, y), width, height,
                             boxstyle="round,pad=0.01",
                             facecolor=info['color'], alpha=0.8,
                             edgecolor='white', linewidth=2)
        ax.add_patch(rect)
        
        # Category title
        ax.text(x + width/2, y + height - 0.03, category,
                ha='center', va='center', fontsize=12, color='white', fontweight='bold')
        
        # Tools list
        tools_text = '\n'.join([f"• {tool}" for tool in info['tools']])
        ax.text(x + 0.02, y + height - 0.08, tools_text,
                ha='left', va='top', fontsize=9, color='white')
    
    # Add UI Components section
    ui_rect = FancyBboxPatch((0.05, 0.02), 0.9, 0.08,
                           boxstyle="round,pad=0.01",
                           facecolor='#607D8B', alpha=0.8,
                           edgecolor='white', linewidth=2)
    ax.add_patch(ui_rect)
    
    ax.text(0.5, 0.08, 'UI COMPONENTS LAYER', ha='center', va='center',
            fontsize=14, fontweight='bold', color='white')
    
    ui_components = ['QTabWidget (Main Tabs)', 'QToolBox (150+ Tools)', 
                    'QTableWidget (Student Data)', 'QStackedWidget (Content)',
                    'QTreeWidget (Navigation)', 'Various Dialogs & Forms']
    
    ui_text = ' • '.join(ui_components)
    ax.text(0.5, 0.04, ui_text, ha='center', va='center',
            fontsize=10, color='white')
    
    # Add connecting arrows
    # Center connections
    center_x, center_y = 0.5, 0.35
    
    for category, info in categories.items():
        x, y = info['position']
        if not category.startswith('Student Services'):
            start_x = x + 0.175  # Center of box
            start_y = y
            ax.annotate('', xy=(center_x, center_y), xytext=(start_x, start_y),
                       arrowprops=dict(arrowstyle='->', color=info['color'], lw=2))
    
    # Remove axes
    ax.set_xlim(0, 1)
    ax.set_ylim(0, 1)
    ax.axis('off')
    
    # Save the diagram
    plt.tight_layout()
    plt.savefig('Student_Module_Architecture.png', dpi=300, bbox_inches='tight',
                facecolor='#1e1e1e', edgecolor='none')
    plt.savefig('Student_Module_Architecture.pdf', bbox_inches='tight',
                facecolor='#1e1e1e', edgecolor='none')
    
    print("✅ Student module diagrams saved:")
    print("   📊 Student_Module_Architecture.png")
    print("   📊 Student_Module_Architecture.pdf")
    
    return fig

if __name__ == "__main__":
    print("🎨 Generating Institution Management System Architecture Diagrams...")
    print("=" * 60)
    
    try:
        # Generate main architecture diagram
        fig1 = create_architecture_diagram()
        
        # Generate student module diagram
        fig2 = create_student_module_diagram()
        
        print("\n🎉 All architecture diagrams generated successfully!")
        print("\n📁 Files created:")
        print("   • Institution_Architecture_Diagram.png")
        print("   • Institution_Architecture_Diagram.pdf") 
        print("   • Student_Module_Architecture.png")
        print("   • Student_Module_Architecture.pdf")
        
        # Show the diagrams
        plt.show()
        
    except ImportError as e:
        print(f"❌ Missing required libraries: {e}")
        print("\n💡 To install required libraries, run:")
        print("   pip install matplotlib seaborn")
    except Exception as e:
        print(f"❌ Error generating diagrams: {e}")
