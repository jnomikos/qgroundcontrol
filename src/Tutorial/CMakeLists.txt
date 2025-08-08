find_package(Qt6 REQUIRED COMPONENTS Core Gui Positioning Qml)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        POIManager.cc
        POIManager.h
        POI.cc
        POI.h
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
        Qt6::Qml
    PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Positioning
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})