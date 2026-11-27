CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT (TENIS)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# Ejecutable del servidor (incluye su mundo, componentes y la librería de hilos pthread)
ADD_EXECUTABLE(servidor src/servidor.cpp src/MundoServidor.cpp src/Esfera.cpp src/Plano.cpp src/Raqueta.cpp src/Vector2D.cpp)
TARGET_LINK_LIBRARIES(servidor pthread glut GL GLU)

# Ejecutable del cliente (incluye su mundo y los componentes gráficos)
ADD_EXECUTABLE(cliente src/cliente.cpp src/MundoCliente.cpp src/Esfera.cpp src/Plano.cpp src/Raqueta.cpp src/Vector2D.cpp)
TARGET_LINK_LIBRARIES(cliente glut GL GLU)

# Ejecutables auxiliares
ADD_EXECUTABLE(logger src/logger.cpp)
ADD_EXECUTABLE(bot src/bot.cpp)
