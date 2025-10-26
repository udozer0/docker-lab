FROM alpine:3.20

# Билд-зависимости и рантайм
RUN apk add --no-cache --virtual .build-deps g++ cmake make \
    && apk add --no-cache libstdc++ wget

WORKDIR /app

COPY CMakeLists.txt .
COPY src ./src
COPY include ./include

# Сборка
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    && cmake --build build -j \
    # после сборки удаляем тяжёлые тулзы
    && apk del .build-deps

# Запуск
EXPOSE 8080

HEALTHCHECK --interval=3s --timeout=1s --retries=10 \
    CMD wget -qO- http://localhost:8080/health | grep -q ok || exit 1
CMD ["./build/service_a"]
