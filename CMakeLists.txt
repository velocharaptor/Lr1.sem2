cmake_minimum_required(VERSION 3.21)
project(lr2)

set(CMAKE_CXX_STANDARD 23)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(lr2 DynamicArray.h LinkedList.h ArraySequence.h ListSequence.h Sequence.h tests.h tests.cpp
        cmake-build-debug/
        ISort.cpp ISort.h Presenter.cpp Presenter.h MainFrame.cpp MainFrame.h App.cpp App.h
        Chartcontrol.cpp Chartcontrol.h)
target_link_libraries(lr2 ${wxWidgets_LIBRARIES})