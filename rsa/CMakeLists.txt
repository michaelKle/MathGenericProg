add_executable(rsa
    main.cpp
)
target_include_directories(rsa PRIVATE ../Common)
target_link_libraries(rsa)