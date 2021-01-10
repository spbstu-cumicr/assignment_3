Написать программу, переключающую светодиоды по нажатию на кнопку в порядке, который соответствует варианту из таблицы 1. За одно нажатие должно происходить одно срабатывание (переключение на другой светодиод). Время реакции на кнопку не должно превышать 0,02 секунды.

Борьба с дребезгом реализуется в бесконечном цикле.

Таблица 1 — Варианты задания
|Вариант|Последовательность загорания светодиодов|
|:-----:|:--------------------------------------:|
|  №00  |         B->Y->G->B->R->B->R->Y         |
|  №01  |         R->G->R->B->G->Y->R->B         |
|  №02  |         G->Y->G->R->G->R->B->Y         |
|  №03  |         B->Y->R->B->R->B->R->G         |
|  №04  |         R->G->B->Y->B->R->B->Y         |
|  №05  |         B->G->B->Y->R->Y->B->G         |
|  №06  |         Y->R->Y->G->B->R->Y->G         |
|  №07  |         Y->R->Y->B->G->Y->R->G         |
|  №08  |         Y->G->B->G->R->B->Y->B         |
|  №09  |         Y->G->R->B->G->R->B->G         |
|  №10  |         R->G->B->G->Y->B->R->Y         |
|  №11  |         B->G->Y->G->R->G->Y->G         |
|  №12  |         R->G->Y->G->B->G->B->Y         |
|  №13  |         G->Y->R->B->Y->G->B->Y         |
|  №14  |         B->G->Y->B->G->R->B->G         |
|  №15  |         B->R->B->R->G->R->Y->R         |
|  №16  |         R->G->B->R->G->R->Y->B         |
|  №17  |         Y->B->R->B->Y->G->R->G         |
|  №18  |         B->G->R->G->B->G->R->Y         |
|  №19  |         G->Y->G->B->G->Y->G->B         |
|  №20  |         G->Y->G->Y->B->R->Y->B         |
|  №21  |         G->Y->R->G->B->G->Y->B         |
|  №22  |         R->G->R->Y->G->R->Y->B         |
|  №23  |         G->B->R->B->R->B->G->Y         |
|  №24  |         G->R->Y->G->B->R->G->Y         |
|  №25  |         G->Y->G->B->G->Y->G->R         |
|  №26  |         G->B->R->Y->B->G->R->Y         |
|  №27  |         G->B->G->Y->G->Y->B->Y         |
|  №28  |         B->R->B->R->Y->R->G->R         |
|  №29  |         B->R->G->B->Y->B->R->Y         |