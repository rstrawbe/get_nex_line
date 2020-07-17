# get_next_line

Функция для построчного чтения из fd

Максимальный размер файла 100000000 байт, задается в MEM_SIZE

Размер буфера чтения по умолчанию 32 байта

Изменить размер буфера можно при компиляции с флагом -D

```$ gcc -D BUFFER_SIZE=хх get_next_line.c get_next_line_utils.c main.c```

Функция работает эфективнее всего с размером BUFFER_SIZE=2 байта

Пример использования функции описан в test/test.c

```$ cd tests```

```$ gcc test.c ../srcs/get_next_line*.c -I ../srcs/get_next_line.h -D BUFFER_SIZE=2```

```$ time ./a.out```

Программа разбивает на предложения большой тексовый файл
