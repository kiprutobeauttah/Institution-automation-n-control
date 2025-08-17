cmake_minimum_required(VERSION 3.16)

# Project name and version
project(InstitutionAutomationControl VERSION 2.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required Qt components
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Charts)

# Enable Qt MOC (Meta-Object Compiler)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/modules)

# Source files
set(SOURCES
    main.cpp
    src/mainwindow.cpp
    src/modules/studentmanagement.cpp
    src/modules/teachermanagement.cpp
    src/modules/feesfinancemanagement.cpp
    src/modules/attendancemanagement.cpp
    src/modules/inventorymanagement.cpp
)

# Header files
set(HEADERS
    include/mainwindow.h
    include/modules/studentmanagement.h
    include/modules/teachermanagement.h
    include/modules/feesfinancemanagement.h
    include/modules/attendancemanagement.h
    include/modules/inventorymanagement.h
)

# Create executable
add_executable(InstitutionManager ${SOURCES} ${HEADERS})

# Link Qt libraries
target_link_libraries(InstitutionManager 
    Qt6::Core 
    Qt6::Widgets
    Qt6::Charts
)

# Compiler-specific options
if(MSVC)
    target_compile_options(InstitutionManager PRIVATE /W4)
    set_property(TARGET InstitutionManager PROPERTY WIN32_EXECUTABLE TRUE)
else()
    target_compile_options(InstitutionManager PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Set output directory
set_target_properties(InstitutionManager PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    OUTPUT_NAME "Institution-Automation-Control"
)

# Install rules
install(TARGETS InstitutionManager
    RUNTIME DESTINATION bin
)

# CPack configuration for packaging
set(CPACK_PACKAGE_NAME "Institution Automation Control System")
set(CPACK_PACKAGE_VERSION "2.0.0")
set(CPACK_PACKAGE_DESCRIPTION "Comprehensive Educational Institution Management System")
set(CPACK_PACKAGE_CONTACT "Educational Solutions Inc.")
include(CPack)
