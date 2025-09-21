cmake_minimum_required(VERSION 4.0)
project(apicaller C)

set(CMAKE_C_STANDARD 23)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk4)


add_executable(${PROJECT_NAME} src/actions.c src/application.c src/project.c src/main.c)
target_include_directories(${PROJECT_NAME} PRIVATE src/include)
target_include_directories(${PROJECT_NAME} PRIVATE PkgConfig::GTK)
target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::GTK)
