CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(Final-Project)

ADD_SUBDIRECTORY(googletest)
 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin") # This makes "make" build the executables into the bin folder
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

ADD_EXECUTABLE(blackjack
    src/blackjack.cpp
    src/card.cpp
    tests/blackjackTest.cpp
)

TARGET_LINK_LIBRARIES(blackjack gtest)
TARGET_COMPILE_DEFINITIONS(blackjack PRIVATE gtest_disable_pthreads=ON)

ADD_EXECUTABLE(connect4Test
    tests/connect4Test.cpp
    src/connect4.cpp
)

TARGET_LINK_LIBRARIES(connect4Test gtest)
TARGET_COMPILE_DEFINITIONS(connect4Test PRIVATE gtest_disable_pthreads=ON)

ADD_EXECUTABLE(tictactoeTest
    src/tictactoe.cpp
    tests/tictactoeTest.cpp
)

TARGET_LINK_LIBRARIES(tictactoeTest gtest)
TARGET_COMPILE_DEFINITIONS(tictactoeTest PRIVATE gtest_disable_pthreads=ON)


ADD_EXECUTABLE(rockpaperscissorsTest
    src/rockpaperscissors.cpp
    tests/rockpaperscissorsTest.cpp
)

TARGET_LINK_LIBRARIES(rockpaperscissorsTest gtest)
TARGET_COMPILE_DEFINITIONS(rockpaperscissorsTest PRIVATE gtest_disable_pthreads=ON)

ADD_EXECUTABLE(virtualPet
    src/virtualPet.cpp 
    tests/virtualPetTest.cpp
)

TARGET_LINK_LIBRARIES(virtualPet gtest)
TARGET_COMPILE_DEFINITIONS(virtualPet PRIVATE gtest_disable_pthreads=ON)

ADD_EXECUTABLE(gameManager
    src/gameManager.cpp 
    tests/gameManagerTest.cpp
    src/virtualPet.cpp
    src/blackjack.cpp 
    src/card.cpp 
    src/connect4.cpp 
    src/tictactoe.cpp 
    src/rockpaperscissors.cpp 
)

TARGET_LINK_LIBRARIES(gameManager gtest)
TARGET_COMPILE_DEFINITIONS(gameManager PRIVATE gtest_disable_pthreads=ON)