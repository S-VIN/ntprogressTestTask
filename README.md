# ntprogressTestTask

![Optional](../master/documents/0.png)

Программа собирается с помощью cmake. Для тестов используется библиотека catch2.
![Optional](../master/documents/1.png)



Для установки выполните:
```bash
git clone https://github.com/S-VIN/ntprogressTestTask.git
cmake ./
make
./ntprogressTestTask
```
![Optional](../master/documents/2.png)
![Optional](../master/documents/3.png)
После этого введите ваше выражение


Для запуска тестов зайдите в директорию `tests` и запустите cmake в ней. 
![Optional](../master/documents/4.png)

```bash
cd tests
cmake ./
make
./tests
```


Программа выполняет простейшую обработку ошибок в выражении. Неправильный порядок скобок не обрабатывается.

Алгоритм обработки выражений такой:
 - проверка строки на правильность
 - нормализация строки (очистка от пробелов, замена запятых)
 - преобразование строкового выражения в массив отдельных элементов
 - вычленение из массива выражений в скобках (вычленение происходит по закрывающей скобке)
 - решение скобочного выражения и замена ответом выражения (этот пункт выполняется до получения ответа)

Некторые функции в программе излишне раздуты. Сделано это специально, чтобы не прегружать маленькую программу множеством функций и классов.
