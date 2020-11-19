cmake_minimum_required(VERSION 3.13)

project(GeeksForGeeks VERSION 0.1 LANGUAGES CXX)

enable_testing()


function(add_geek_example NO)
    add_executable(Geek_${NO})
    target_sources(Geek_${NO}
        PRIVATE ${NO}.cpp
    )
    target_link_libraries(Geek_${NO})
    target_include_directories(Geek_${NO} PRIVATE ../Common)
    add_test(NAME Geek_${NO} COMMAND Geek_${NO})
endfunction()

add_geek_example(prime_number)
add_geek_example(prime_factors_of_a_number)
