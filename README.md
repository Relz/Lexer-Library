# Lexer
## Токены
### Общая информация
|Группа токена          |Токен               |Наименование                                             |Код                           |
|-----------------------|--------------------|---------------------------------------------------------|------------------------------|
|По умолчанию           |UNKNOWN             |Неизвестный токен                                        |```$```                       |
|Арифметическая операция|PLUS                |Оператор сложения                                        |```+```                       |
|                       |MINUS               |Оператор вычитания                                       |```-```                       |
|                       |MULTIPLY            |Оператор умножения                                       |```*```                       |
|                       |DIVISION            |Оператор деления                                         |```/```                       |
|Операция присваивания  |ASSIGNMENT          |Оператор присваивания                                    |```=```                       |
|                       |PLUS_ASSIGNMENT     |Оператор суммирующего присваивания                       |```+=```                      |
|                       |MINUS_ASSIGNMENT    |Оператор вычитающего присваивания                        |```-=```                      |
|                       |MULTIPLY_ASSIGNMENT |Оператор умножающего присваивания                        |```*=```                      |
|                       |DIVISION_ASSIGNMENT |Оператор делящего присваивания                           |```/=```                      |
|Операция сравнивания   |EQUIVALENCE         |Оператор эквивалентности                                 |```==```                      |
|                       |NOT_EQUIVALENCE     |Оператор неэквивалентности                               |```!=```                      |
|                       |MORE_OR_EQUIVALENCE |Оператор "больше или равно"                              |```>=```                      |
|                       |LESS_OR_EQUIVALENCE |Оператор "меньше или равно"                              |```<=```                      |
|                       |MORE                |Оператор "больше"                                        |```>```                       |
|                       |LESS                |Оператор "меньше"                                        |```<```                       |
|Ключевое слово         |CLASS               |Ключевое слово класса                                    |```class```                   |
|                       |EXTENDS             |Ключевое слово расширения                                |```extends```                 |
|                       |IMPLEMENTS          |Ключевое слово реализации                                |```implements```              |
|                       |CONSTRUCTOR         |Ключевое слово конструктора класса                       |```Constructor```             |
|                       |NOT_INITIALIZED     |Ключевое слово неинициализированной переменной           |```NULL```                    |
|                       |PRIVATE             |Ключевое слово приватного доступа                        |```private```                 |
|                       |PUBLIC              |Ключевое слово публичного доступа                        |```public```                  |
|                       |GET                 |Ключевое слово получения поля класса                     |```get```                     |
|                       |SET                 |Ключевое слово установки значения поля класса            |```set```                     |
|                       |FOR                 |Ключевое слово цикла с переменной                        |```for```                     |
|                       |WHILE               |Ключевое слово цикла с предусловием                      |```while```                   |
|                       |DO                  |Ключевое слово цикла с постусловием                      |```do```                      |
|                       |RETURN              |Ключевое слово возврата значения                         |```return```                  |
|                       |IF                  |Ключевое слово условия                                   |```if```                      |
|                       |ELSE                |Ключевое слово противного действия по условию            |```else```                    |
|Число                  |INTEGER             |Значение целого числа                                    |```0```, ```16_A1BF```        |
|                       |FLOAT               |Значение числа с фиксированной запятой                   |```0.1```                     |
|                       |EXPONENTIAL         |Значение экспоненциального числа                         |```0.1_E+1```, ```0.1_E-2.3```|
|Разделитель            |COLON               |Разделяющее двоеточие                                    |```:```                       |
|                       |COMMA               |Разделяющая запятая                                      |```,```                       |
|                       |DOT                 |Резделяющая точка                                        |```.```                       |
|                       |SEMICOLON           |Разделяющая точка с запятой                              |```;```                       |
|Скобка                 |LEFT_SQUARE_BRACKET |Левая квадратная скобка                                  |```[```                       |
|                       |RIGHT_SQUARE_BRACKET|Правая квадратная скобка                                 |```]```                       |
|                       |LEFT_ROUND_BRACKET  |Левая круглая скобка                                     |```(```                       |
|                       |RIGHT_ROUND_BRACKET |Правая круглая скобка                                    |```)```                       |
|                       |LEFT_CURLY_BRACKET  |Левая фигурная скобка                                    |```{```                       |
|                       |RIGHT_CURLY_BRACKET |Правая фигурная скобка                                   |```}```                       |
|Другое                 |TYPE                |Тип данных                                               |```Integer```                 |
|                       |IDENTIFIER          |Идентификатор                                            |```identifier0```             |
|                       |STRING_LITERAL      |Строковый литерал                                        |```"string"```                |
|                       |CHARACTER_LITERAL   |Символьный литерал                                       |```'a'```                     |
|                       |END_OF_FILE         |Конец файла                                              |``````                        |

### Разделители

|Наименование             |Код       |
|-------------------------|----------|
|Начало блока комментария |```/*```  |
|Начало строки комментария|```//```  |
|Пробел                   |``` ```   |
|Табуляция                |```\t```  |
|Конец строки Windows     |```\r\n```|
|Конец строки Unix        |```\n```  |
|Конец строки Macintosh   |```\r```  |
|Эквивалентность          |```==```  |
|Неэквивалентность        |```!=```  |
|Больше или эквивалентно  |```>=```  |
|Меньше или эквивалентно  |```<=```  |
|Больше                   |```>```   |
|Меньше                   |```<```   |
|Присваивание             |```=```   |
|Складывающее присваивание|```+=```  |
|Вычитающее присваивание  |```-=```  |
|Умножающее присваивание  |```*=```  |
|Делящее присваивание     |```/=```  |
|Сложение                 |```+```   |
|Вычитание                |```-```   |
|Умножение                |```*```   |
|Деление                  |```/```   |
|Двоеточие                |```:```   |
|Запятая                  |```,```   |
|Точка                    |```.```   |
|Точка с запятой          |```;```   |
|Кавычка                  |```'```   |
|Двойная кавычка          |```"```   |
|Левая квадратная скобка  |```[```   |
|Правая квадратная скобка |```]```   |
|Левая круглая скобка     |```(```   |
|Правая круглая скобка    |```)```   |
|Левая фигурная скобка    |```{```   |
|Правая фигурная скобка   |```}```   |

Приоритетность разделителя описана порядком в таблице: чем выше, тем приоритетнее

### Правила
|Токен               |Правило                                                                                                                                                                                                                                    |
|--------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|UNKNOWN             |Строка, не удовлетворившая ниодному правилу                                                                                                                                                                                                |
|PLUS                |Символ '+', не имеющий впереди символ '=' и не являющийся частью строкового или символьного литерала, комментария или экспоненциального числа                                                                                              |
|MINUS               |Символ '-', не имеющий впереди символ '=' и не являющийся частью строкового или символьного литерала, комментария или экпоненциального числа                                                                                               |
|MULTIPLY            |Символ '*', не имеющий впереди символ '=' и не являющийся частью строкового или символьного литерала или комментария                                                                                                                       |
|DIVISION            |Символ '/', не имеющий впереди символ '=' и не являющийся частью строкового или символьного литерала или комментария                                                                                                                       |
|ASSIGNMENT          |Символ '=', не имеющий впереди символ '=', не имеющий сзади символы '+', '-', '*', '/' и не являющийся частью строкового литерала или комментария                                                                                          |
|PLUS_ASSIGNMENT     |Строка "+=", не являющаяся частью строкового литерала или комментария                                                                                                                                                                      |
|MINUS_ASSIGNMENT    |Строка "-=", не являющаяся частью строкового литерала или комментария                                                                                                                                                                      |
|MULTIPLY_ASSIGNMENT |Строка "*=", не являющаяся частью строкового литерала или комментария                                                                                                                                                                      |
|DIVISION_ASSIGNMENT |Строка "/=", не являющаяся частью строкового литерала или комментария                                                                                                                                                                      |
|EQUIVALENCE         |Строка "==", не являющаяся частью строкового литерала или комментария                                                                                                                                                                      |
|NOT_EQUIVALENCE     |Строка "!=", не являющаяся частью строкового литерала или комментария                                                                                                                                                                      |
|MORE_OR_EQUIVALENCE |Строка ">=", не являющаяся частью строкового литерала или комментария                                                                                                                                                                      |
|LESS_OR_EQUIVALENCE |Строка "<=", не являющаяся частью строкового литерала или комментария                                                                                                                                                                      |
|CLASS               |Строка "class", не являющаяся частью строкового литерала или комментария                                                                                                                                                                   |
|MORE                |Символ '>', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|LESS                |Символ '<', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|EXTENDS             |Строка "extends", не являющаяся частью строкового литерала или комментария                                                                                                                                                                 |
|IMPLEMENTS          |Строка "implements", не являющаяся частью строкового литерала или комментария                                                                                                                                                              |
|CONSTRUCTOR         |Строка "Constructor", не являющаяся частью строкового литерала или комментария                                                                                                                                                             |
|NOT_INITIALIZED     |Строка "NULL", не являющаяся частью строкового литерала или комментария                                                                                                                                                                    |
|PRIVATE             |Строка "private", не являющаяся частью строкового литерала или комментария                                                                                                                                                                 |
|PUBLIC              |Строка "public", не являющаяся частью строкового литерала или комментария                                                                                                                                                                  |
|GET                 |Строка "get", не являющаяся частью строкового литерала или комментария                                                                                                                                                                     |
|SET                 |Строка "set", не являющаяся частью строкового литерала или комментария                                                                                                                                                                     |
|FOR                 |Строка "for", не являющаяся частью строкового литерала или комментария                                                                                                                                                                     |
|WHILE               |Строка "while", не являющаяся частью строкового литерала или комментария                                                                                                                                                                   |
|DO                  |Строка "do", не являющаяся частью строкового литерала или комментария                                                                                                                                                                      |
|RETURN              |Строка "return", не являющаяся частью строкового литерала или комментария                                                                                                                                                                  |
|IF                  |Строка "if", не являющаяся частью строкового литерала или комментария                                                                                                                                                                      |
|ELSE                |Строка "else", не являющаяся частью строкового литерала или комментария                                                                                                                                                                    |
|INTEGER             |Последовательность цифр, не заканичивающаяся символом '.' или строкой "_E", не являющаяся частью строкового литерала или комментария. Может начинаться с последовательности цифр, заканчивающейся символом '_', обозначая систему счисления|
|FLOAT               |Последовательность цифр, разделённая символом '.', не являющаяся частью строкового литерала или комментария                                                                                                                                |
|EXPONENTIAL         |Последовательность цифр, возможно разделённая символом '.', затем разделённая строкой "_E", после которой следует знак '+' или '-' с последующей последовательностью цифр, не являющаяся частью строкового литерала или комментария        |
|COLON               |Символ ':', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|COMMA               |Символ ',', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|DOT                 |Символ '.', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|SEMICOLON           |Символ ';', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|LEFT_SQUARE_BRACKET |Символ '[', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|RIGHT_SQUARE_BRACKET|Символ ']', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|LEFT_ROUND_BRACKET  |Символ '(', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|RIGHT_ROUND_BRACKET |Символ ')', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|LEFT_CURLY_BRACKET  |Символ '{', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|RIGHT_CURLY_BRACKET |Символ '}', не являющийся частью строкового или символьного литерала или комментария                                                                                                                                                       |
|TYPE                |Строки "Integer", "Float", "String", "Void", "Array", не являющиеся частью строкового литерала или комментария                                                                                                                             |
|IDENTIFIER          |Последовательность букв и цифр, а также символа '_', начинающаяся с буквы или символа '_', не являющаяся частью строкового литерала или комментария                                                                                        |
|STRING_LITERAL      |Строка, обрамлённая двойными кавычками, не являющаяся частью комментария                                                                                                                                                                   |
|CHARACTER_LITERAL   |Символ, обрамлённый кавычками, не являющийся частью строкового литерала или комментария                                                                                                                                                    |

*Последовательность цифр - это последовательность символов '0', '1', ..., '9', а также символов 'A', 'B', ... 'Z'. Последний доступный символ последовательности определяется системой счисления.
