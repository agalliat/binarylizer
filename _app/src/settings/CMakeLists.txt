set(NAME "Settings")

configure_file(Settings/Project.cpp.in Settings/Project.cpp @ONLY)

add_library(${NAME} STATIC Settings/Project.hpp Settings/Project.cpp)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${NAME} PRIVATE cxx_std_20)
target_link_libraries(${NAME} PRIVATE project_warnings)
