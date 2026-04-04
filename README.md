# grep_clone

[Русская версия](#русская-версия) | [English Version](#english-version)

## Русская версия

Учебный CLI-проект на C++, реализующий упрощенный аналог `grep`.

Программа ищет совпадения в текстовом файле, поддерживает обычный поиск по подстроке и поиск по регулярному выражению, а также может выводить результаты в консоль и в файл.

### Возможности

- поиск по подстроке
- поиск по регулярному выражению
- поиск без учета регистра
- вывод номеров строк
- вывод результата в файл
- отключение вывода в консоль
- встроенная команда `--help`

### Требования

- C++20
- CMake 4.1+

### Сборка

```bash
cmake -S . -B build
cmake --build build
```

После сборки исполняемый файл будет находиться в build-директории. Имя зависит от конфигурации CMake и платформы.

### Использование

Общий формат команды:

```text
search "<pattern>" <file> [flags] [>output_file]
```

### Флаги

- `--help` - показать справку
- `--ignore-case` - игнорировать регистр
- `--regex` - интерпретировать паттерн как регулярное выражение
- `--line-number` - выводить номер строки перед совпадением
- `--no-cmd` - не выводить результат в консоль

### Примеры

Обычный поиск:

```text
search "error" logs.txt
```

Поиск без учета регистра:

```text
search "error" logs.txt --ignore-case
```

Поиск по регулярному выражению:

```text
search "^WARN.*timeout$" logs.txt --regex
```

Вывод с номерами строк:

```text
search "error" logs.txt --line-number
```

Сохранение результата в файл:

```text
search "error" logs.txt >result.txt
```

Запись только в файл без вывода в консоль:

```text
search "error" logs.txt --no-cmd >result.txt
```

### Структура проекта

- `src/main.cpp` - точка входа и цикл CLI
- `src/Parser.cpp` - разбор пользовательской команды
- `src/CommandExecutor.cpp` - выполнение команды
- `src/Grep.cpp` - логика поиска
- `src/FileReader.cpp` - чтение данных из файла
- `src/Output.cpp` - вывод результата в консоль и файл
- `include/` - заголовочные файлы проекта

### Идея проекта

Проект сделан как учебная реализация grep-подобной утилиты с упором на:

- практику работы с CMake
- разбиение логики на отдельные модули
- использование STL
- обработку пользовательского ввода в CLI

### Планы на развитие

- улучшить парсинг CLI
- добавить тесты
- улучшить обработку ошибок
- оптимизировать чтение больших файлов
- расширить набор поддерживаемых флагов

## English Version

An educational C++ CLI project that implements a simplified `grep` clone.

The program searches for matches in a text file, supports plain substring search and regular-expression search, and can print results both to the console and to a file.

### Features

- substring search
- regular expression search
- case-insensitive search
- line number output
- file output
- disabled console output
- built-in `--help` command

### Requirements

- C++20
- CMake 4.1+

### Build

```bash
cmake -S . -B build
cmake --build build
```

After building, the executable will be located in the build directory. Its exact name depends on the selected CMake configuration and platform.

### Usage

General command format:

```text
search "<pattern>" <file> [flags] [>output_file]
```

### Flags

- `--help` - show help information
- `--ignore-case` - perform case-insensitive search
- `--regex` - treat the pattern as a regular expression
- `--line-number` - print line numbers before matched lines
- `--no-cmd` - do not print results to the console

### Examples

Basic search:

```text
search "error" logs.txt
```

Case-insensitive search:

```text
search "error" logs.txt --ignore-case
```

Regular expression search:

```text
search "^WARN.*timeout$" logs.txt --regex
```

Search with line numbers:

```text
search "error" logs.txt --line-number
```

Write results to a file:

```text
search "error" logs.txt >result.txt
```

Write only to a file without console output:

```text
search "error" logs.txt --no-cmd >result.txt
```

### Project Structure

- `src/main.cpp` - entry point and CLI loop
- `src/Parser.cpp` - user command parsing
- `src/CommandExecutor.cpp` - command execution
- `src/Grep.cpp` - search logic
- `src/FileReader.cpp` - file reading
- `src/Output.cpp` - console and file output
- `include/` - project headers

### Project Idea

This project was created as a learning implementation of a grep-like utility with a focus on:

- practicing CMake
- separating logic into modules
- using the STL
- handling user input in a CLI application

### Future Improvements

- improve CLI parsing
- add tests
- improve error handling
- optimize processing of large files
- support more flags
