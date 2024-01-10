# src 
#生成应用程序 main
ADD_EXECUTABLE(mdf main.c)

# 添加头文件搜索路径
# INCLUDE_DIRECTORIES(${MDF}/include)




# 添加链接库  连接src下的main.c 与 lib文件夹下的print.cpp  
target_link_libraries(mdf PUBLIC ${PROJECT_BINARY_DIR}/lib/print)
# # target_link_libraries(mdf PUBLIC libBin)

# # target_link_libraries(mdf PUBLIC ${PROJECT_BINARY_DIR}/libBin/lib)
# # target_link_libraries(mdf PUBLIC lib)




# #制定头文件 位置
# # PUBLIC  PRIVATE I
target_include_directories(mdf PUBLIC 
                                        ${PROJECT_BINARY_DIR}
                                        ${PROJECT_BINARY_DIR}/lib
                                        ${PROJECT_SOURCE_DIR}/lib
                          )

