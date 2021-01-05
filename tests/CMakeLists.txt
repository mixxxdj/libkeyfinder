add_executable(keyfinder-tests
    main.cpp
    _testhelpers.cpp
    audiodatatest.cpp
    binodetest.cpp
    chromagramtest.cpp
    chromatransformtest.cpp
    chromatransformfactorytest.cpp
    constantstest.cpp
    downsamplershortcuttest.cpp
    fftadaptertest.cpp
    keyclassifiertest.cpp
    keyfindertest.cpp
    lowpassfiltertest.cpp
    lowpassfilterfactorytest.cpp
    spectrumanalysertest.cpp
    temporalwindowfactorytest.cpp
    toneprofilestest.cpp
    windowfunctiontest.cpp
    workspacetest.cpp)
target_include_directories(keyfinder-tests PRIVATE ../src)
target_link_libraries(keyfinder-tests PRIVATE keyfinder)
find_package(Catch2 CONFIG)
if(NOT TARGET Catch2::Catch2)
    message(STATUS "Fetching Catch2 from GitHub")
    include(FetchContent)
    FetchContent_Declare(
      Catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG        v2.13.4)
    FetchContent_MakeAvailable(Catch2)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
endif()
target_link_libraries(keyfinder-tests PRIVATE Catch2::Catch2)
include(Catch)
catch_discover_tests(keyfinder-tests)
