project(pi)

add_executable(pi main.cpp)

install(TARGETS pi RUNTIME DESTINATION bin)
