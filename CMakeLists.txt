cmake_minimum_required(VERSION 3.16)
project(kwin-3fingerswipe4alttab VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(QT_MAJOR_VERSION 6)
set(QT_DEFAULT_MAJOR_VERSION 6)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH})

include(KDEInstallDirs6)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

find_package(Qt6 REQUIRED COMPONENTS Core DBus Widgets)
find_package(KWin REQUIRED)

add_library(kwin_effect_3fingerswipe4alttab MODULE
    src/main.cpp
    src/effect.cpp
)

target_link_libraries(kwin_effect_3fingerswipe4alttab
    PRIVATE
    KWin::kwin
    Qt6::DBus
)

install(TARGETS kwin_effect_3fingerswipe4alttab
    DESTINATION ${KDE_INSTALL_PLUGINDIR}/kwin/effects/plugins
)

