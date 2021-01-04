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
