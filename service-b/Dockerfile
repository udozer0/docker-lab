FROM alpine:3.20

RUN apk add --no-cache --virtual .build-deps g++ cmake make \
    && apk add --no-cache libstdc++

WORKDIR /app
COPY CMakeLists.txt .
COPY src ./src
COPY include ./include

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
 && cmake --build build -j \
 && apk del .build-deps

ENV API_HOST=api
CMD ["./build/service_b"]
