# Два простых C++ сервиса под Docker Compose

## Запуск
```bash
docker compose up --build
```

### Что произойдет
- `api` поднимет HTTP-сервер на `:8080`.
- `reporter` дождется, пока API станет здоровым, и сделает к нему два запроса:
  - `/health`
  - `/sum?a=5&b=7`

Вывод:
```
Health: {"status":"ok"}
Sum: {"sum":12}
```
