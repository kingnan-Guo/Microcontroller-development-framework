
# Select the heap port.  values between 1-4 will pick a heap.
set(FREERTOS_HEAP "4" CACHE STRING "" FORCE)

# Select the native compile PORT
set(FREERTOS_PORT "TEMPLATE" CACHE STRING "" FORCE)

ADD_EXECUTABLE(main main.cpp)

ADD_SUBDIRECTORY(evolution)
# #制定头文件 位置
# # PUBLIC  PRIVATE I
# target_include_directories(main 
# PUBLIC 
#     ${PROJECT_BINARY_DIR}
#     # ${PROJECT_BINARY_DIR}/lib
#     # ${PROJECT_SOURCE_DIR}/lib
#     # ${EXTRA_INCLUDES}
# )

# set(FREERTOS_HEAP "4" CACHE STRING "" FORCE)

# Select the native compile PORT


# target_link_libraries(${PROJECT_NAME} freertos_kernel freertos_config)

target_link_libraries(main
    evolution
)