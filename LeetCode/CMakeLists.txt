cmake_minimum_required(VERSION 3.13)

project(LeetCode VERSION 0.1 LANGUAGES CXX)

enable_testing()


function(add_leet_example NO)
    add_executable(Leet_${NO})
    target_sources(Leet_001
        PRIVATE ${NO}.cpp
    )
    target_link_libraries(Leet_${NO})
    add_test(NAME Leet_${NO} COMMAND Leet_${NO})
endfunction()

add_leet_example(001)
