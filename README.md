OzComp
======

![title](Keyboard+Case/ComputerCase/pic.jpg)



### Общее описание

+ Все вычисления производятся в арифметике с плавающей запятой одинарной точности.
+ Регистры хранят числа с плавающей запятой одинарной точности.
+ Есть инструкции окгругления, вывода целых чисел, сохранения байтов в памяти.
+ Операнд-источник справа, операнд-приемник справа.
+ Доступно 16 регистров с именами R0-R15.
+ Все регистры 32-битные.
+ Некоторые из регистров используются для неявного сохранения в них результатов работы инструкций.


##### Память и системные регистры

Память реализована как SD-карта (в эмуляторе файл 'memory'). Программа стартует с нулевого байта.
SP это внутренний указатель На вершину стека. Размер стека 2147483648 байт (2 ГБ),
все что выше стека так же доступно для изменения, в таком случае большой стек не повредит данные.
Размер стека в 2 ГБ влечет за собой ограничение на размер программы, так как растет вниз.
IP это внутренний указатель на текущую инструкцию. При исполнении комады CALL его значение
кладется на вершину стека, уменьшая значение SP на 4. После выполнения инструкции RET,
значение со стека снимается увеличивая SP на 4.
FLAGS это внутренний регистр состояния, состоит из 3 битов Equal, Great, Less (E, G, L).
Служит для основания условного перехода, изменяется арифметическими и логическими операциями


##### Экран

Экран имеет разрешение 48*84 пикселя, это 6 рядов по 84 колонки. Каждый зажженый пиксель
в колонке n от правого верхнего угла последовательно - слева направо, сверху вниз,
означает установленный бит сверху вниз n-го байта в памяти экрана. При исполнении
инструкции SETC, устанавливается номер колонки, которая будет изменена первой следующей
инструкцией DRAW (которая отправляет 504 байта из памяти по указателю в память экрана)
Экран не позволяет узнать содержимое своей памяти, поэтому она хранится в основной памяти,
сразу после всех данных программы, в области доступной стеку. 


##### Клавиатура

Встроенная таблица символов, считавыние клавиши происходит с помощью инструкции
GKEY, которая неявно использует регистр R15 для сохранения байта, полученного от 
клавиатуры. Клавиатура может питать компьютер, если имеет встроенный источник
питания.


##### Обозначения

R - регистр
C - константа
L - метка
E, G, L - флаги регистра состояния (равно, больше, меньше - соответственно)
N/A - нет аргументов
M - ячейка памяти, варианты записи один из [L], [L+R]


##### Арифметические операции

|Название 	| Аргументы |	Описание
|-:|:-:|:-
ADD 		| R/(R,C)	| 	Сложение
SUB 		| R/(R,C)	| 	Вычитание
MUL 		| R/(R,C)	| 	Умножение
DIV 		| R/(R,C)	| 	Деление
MOD		 	| R/(R,C)	| 	Остаток от деления
POW			| R/(R,C)	| 	Возведение в степень
CMP			| R/(R,C)	| 	Изменить флаги вычитанием


##### Логические операции

|Название 	| Аргументы |	Описание
|-:|:-:|:-
AND 	| R/(R,C)	|	Побитовое И целых частей операндов
OR  	| R/(R,C)	|	Побитовое ИЛИ целых частей операндов
XOR 	| R/(R,C)	|	Побитовое исключающее ИЛИ целых частей операндов

***Общий пример для этих групп команд.***

+ ADD R0, R1
+ ADD R0, 1


##### Переходы

|Название 	| Аргументы |	Описание
|-:|:-:|:-
JMP		| L			| 	Безусловный переход
J{E,G,L}| L			| 	Условный переход, где C  E, G, L
LOOP	| L			| 	Условный переход пока R14 больше 0
CALL	| L			| 	Безусловный переход с сохранением IP в стек 
RET		| N/A		| 	Извлечение IP из стека

***Общий пример для этой группы команд.***

+ JNE my_label
+ CALL my_func
+ RET


##### Работа со стеком

|Название 	| Аргументы |	Описание
|-:|:-:|:-
+ PUSH	| R 		|	Положить на стек
+ POP		| R			|	Снять со стека

***Примеры***

+ PUSH R0
+ POP R1

##### Экран и клавиатура

|Название 	| Аргументы |	Описание
|-:|:-:|:-
PRINT 	| (R,L) 	| 	Печать, числа или строки, оканчивающейся нулем.
IPRINT	| (R,L) 	| 	Аналогична PRINT только число печатает целым.
SETC	| R/R, C/C 	| 	Установка курсора на позицию X, Y.
SEND	| (R,C)		| 	Отправка байта на экран в текущую позицию курсора. 
DRAW	| L			| 	Отправить 504 байта в память экрана из памяти с адреса L.
GKEY	| N/A		| 	Получить символ клавиатуры, 0 если нет.

***Примеры***

+ PRINT my_str
+ IPRINT R0
+ SETC R0, R5
+ SETC 10, 20
+ SEND R0 (<256)
+ SEND 85
+ DRAW my_pic
+ GKEY


##### Макрокоманды MCASM

|Название 	| Аргументы |	Описание
|-:|:-:|:-
DATA	| C1/C2 		|	Повторить С2 раз число С1
DD		| C1, C2, ...	|	Создать дамп данных в памяти

***Примеры***

+ DATA 0xff, 100500
+ DATA 2.718281828, 3
+ DD 3.1415926535, 3, "hello world", 0xffffffffffffffffffffff


##### Другие

|Название 	| Аргументы |	Описание
|-:|:-:|:-
MOV 	| R/(R,C,M),M/R | 	Перемещение данных во float
MOVB	| R/M,M/R 		|	Перемещение байтов в ячейки памяти
INT		| R				|	Округление
DELAY	| (R,C)			|	Задержка в милисекундах
RND		| N/A			| 	Случайное целое в промежутке [0, 1024), результат в R13

***Примеры***

+ MOV [my_var], R0
+ MOV R0, [my_var+R1]
+ INT R0
+ DELAY R1
+ DELAY 100
+ RND
