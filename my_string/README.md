# MyString

Собственная реализация строкового класса на C++ — аналог `std::string`.

Цель проекта — практическое освоение современного C++:
- RAII
- Правило пяти (Rule of Five)
- Управление динамической памятью
- Move-семантика
- Перегрузка операторов

## Структура
\`\`\`
my-string/
├── CMakeLists.txt
├── README.md
├── include/
│   └── MyString.h
├── src/
│   ├── MyString.cpp
│   └── main.cpp
└── tests/
\`\`\`

## Как собрать
\`\`\`bash
cmake -B build
cmake --build build
./build/my_string
\`\`\`

## Возможности
*(будет дополнено по мере реализации)*