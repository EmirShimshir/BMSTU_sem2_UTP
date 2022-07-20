# BMSTU_sem2_UTP
Тестирование, отладка и профилирование ПО. Обработка матриц.



# График зависимости времени выполнения программы от размера матриц при их преремножении

График зависимости времени выполнения программы в микросекундах от размера матрицы для всех 15 вариантов программы:

**transpose no** - умножение квадратных матриц без транспонирования  

**transpose first** - транспонирование только первой матрицы перед умножением

**transpose second**  - транспонирование только второй матрицы перед умножением

C уровнями оптимизации **Os O1 O2 O3 O0** для каждого алгоритма

<img width="854" alt="Снимок экрана 2022-07-20 в 12 21 43" src="https://user-images.githubusercontent.com/88317896/179946986-1c28c3ef-64ff-4573-9195-05619a171bab.png">

Количество экспериментов, по которым был построен график равно 1000 (для каждого случая, для каждого размера матрицы). 

Мы видим, что при оптимизации **O0** самым долгим алгоритмом является **transpose first**. Это происходит, так как при транспонировании первой матрицы умножение производится по солбцам обоих матриц. 
Матрицы в памяти хранятся последовательно одномерно по строкам, следовательно, обращение к элементам матриц по столбцам происходит дольше, чем при обращении по строкам. 
В свою очередь **transpose no** и **transpose second** работают проктически одинаково, хотя  **transpose second** выглядит более эффективным методом, так как при транспонировании второй матрицы умножениепроизводится по строкам. 
Можно сделать вывод, что время  **transpose second** увеличилось за счёт двукратного транспонирования матрицы.

При включенной оптимизации наиболее быстрым методом явлется **transpose second**, так как производится умножение по строкам, происходит обращение к ячейкам памяти, находящимся рядом друг с другом.

## Таблицы данных к графикам

Таблицы данных, по которым были построены графики, с точностью до десятых:



### Таблица 1: Таблица значений для графика (без транспонирования)

**размер** **среднее значение (мкс)**

**без транспонирования**
|**O0**|**O1**|**O2**|**O3**|**Os**|
|------|------|------|------|------|
|1  |1,1   |1,1|1,1|3,2|1,1|
|5  |1,5   |1,3|1,3|2,3|1,3|
|10 |4,3   |3,0|2,6|3,8|2,8|
|15 |8,8   |4,4|3,6|4,8|4,1|
|20 |18,3  |8,2|5,9|7,3|7,5|
|25 |32,5  |15,3|7,7|8,9|11,4|
|30 |54,5  |20,4|12,3|13,4|18,4|
|35 |83,7  |33,7|15,5|17,1|31,1|
|40 |132,6 |48,3|20,5|22,2|44,9|
|45 |171,0 |64,8|29,0|30,7|52,7|
|50 |232,4 |74,6|36,6|38,6|70,3|
|55 |310,0 |109,1|48,5|50,0|90,8|
|60 |399,0 |138,9|59,0|60,8|116,5|
|65 |502,2 |172,5|70,5|72,8|146,2|
|70 |635,2 |211,9|93,4|93,6|183,7|
|75 |807,1 |252,8|106,4|108,0|247,8|
|80 |968,9 |304,6|123,0|125,6|308,2|
|85 |1167,0|364,8|154,3|155,3|362,1|
|90 |1325,4|427,4|175,6|177,1|428,5|
|95 |1593,3|499,9|212,0|214,9|485,5|
|100|1881,2|568,7|238,3|242,2|554,7|
*Таблица 2: Таблица значений для графика  (транспонирование второй матрицы)*



|**размер**|**среднее значение (мкс)**|
| - | - |
||**транспонирование второй матрицы**|
||**O0**|**O1**|**O2**|**O3**|**Os**|
|1|1,2|1,2|1,1|3,3|1,1|
|5|1,7|1,3|1,4|2,4|1,4|
|10|4,8|2,9|2,8|4,0|2,8|
|15|9,5|4,0|3,8|5,1|3,9|
|20|20,0|7,1|5,8|7,1|7,2|
|25|34,6|10,3|7,0|7,9|10,2|
|30|56,9|15,7|11,0|12,4|16,1|
|35|86,5|29,7|12,8|13,9|29,5|
|40|135,0|45,2|16,0|17,0|44,6|
|45|175,5|43,0|22,2|24,1|42,5|
|50|240,0|57,7|26,1|27,4|57,7|
|55|312,4|73,3|35,5|38,2|73,8|
|60|401,9|95,9|40,7|42,0|93,3|
|65|516,9|118,5|45,4|46,3|118,1|
|70|637,0|145,2|60,8|64,6|144,4|
|75|809,5|205,9|68,0|67,6|203,5|
|80|983,2|244,0|73,6|71,9|245,7|
|85|1177,1|286,3|95,8|98,8|289,0|
|90|1357,9|342,5|109,4|110,3|346,0|
|95|1648,1|383,4|133,5|137,9|389,4|
|100|1922,9|447,2|141,5|144,1|443,7|
*Таблица 3: Таблица значений для графика 1 (транспонирование первой матрицы)*



|**размер**|**среднее значение (мкс)**|
| - | - |
||**транспонирование первой матрицы**|
||**O0**|**O1**|**O2**|**O3**|**Os**|
|1|1.2|1.2|1.1|2.2|1.1|
|5|1.6|1.4|1.4|2.4|1.4|
|10|4.8|2.9|3.1|3.9|3.1|
|15|10.0|3.9|4.5|4.9|4.4|
|20|20.7|6.7|8.4|7.8|8.1|
|25|36.0|9.6|12.3|11.0|12.1|
|30|60.0|14.9|19.5|16.4|18.8|
|35|91.7|28.2|27.9|22.7|33.5|
|40|141.5|43.6|41.4|32.0|48.6|
|45|187.0|38.1|53.9|41.9|53.2|
|50|254.0|50.9|73.4|55.5|72.2|
|55|339.4|65.5|95.0|70.9|91.0|
|60|431.4|83.4|122.6|90.6|118.4|
|65|545.1|103.4|150.5|111.3|145.7|
|70|677.2|130.8|190.1|138.1|180.9|
|75|869.9|196.1|226.8|168.0|248.8|
|80|1051.1|230.4|275.5|200.4|300.7|
|85|1250.2|270.3|324.9|241.2|355.5|
|90|1445.9|318.3|390.4|281.8|415.8|
|95|1716.9|349.4|447.5|323.7|481.0|
|100|1990.2|405.6|521.7|381.4|556.4|
2. **Таблица значений с формулами**

*t*1 - время работы метода **transpose first** при уровне оптимизации **O2**

*n*

*t*2 **-** время работы метода **transpose no** при уровне оптимизации **O2**

*n*

*t*3 **-** время работы метода **transpose second** при уровне оптимизации **O2**

*n*

ln(*t j* )− ln(*t j*)

*f j* **=**  (*i*+1) *i*

ln(*nj* )− ln(*nj*)

(*i*+1) *i*

*Таблица 4: Таблица с формулами*



|**размер**|<p>1 *n*</p><p>*t*</p>|<p>2 *n*</p><p>*t*</p>|<p>3 *n*</p><p>*t*</p>|<p>1</p><p>*f*</p>|<p>2</p><p>*f*</p>|<p>3</p><p>*f*</p>|
| - | - | - | - | - | - | - |
|1|1,1|1,1|1,1|0,14|0,10|0,11|
|5|1,4|1,3|1,4|1,16|1,02|1,04|
|10|3,1|2,6|2,8|0,89|0,75|0,76|
|15|4,5|3,6|3,8|2,19|1,76|1,43|
|20|8,4|5,9|5,8|1,75|1,18|0,82|
|25|12,3|7,7|7,0|2,50|2,58|2,52|
|30|19,5|12,3|11,0|2,33|1,50|0,99|
|35|27,9|15,5|12,8|2,96|2,10|1,64|
|40|41,4|20,5|16,0|2,24|2,94|2,79|
|45|53,9|29,0|22,2|2,94|2,21|1,55|
|50|73,4|36,6|26,1|2,70|2,94|3,22|
|55|95,0|48,5|35,5|2,93|2,27|1,58|
|60|122,6|59,0|40,7|2,56|2,21|1,37|
|65|150,5|70,5|45,4|3,15|3,80|3,92|
|70|190,1|93,4|60,8|2,56|1,89|1,63|
|75|226,8|106,4|68,0|3,01|2,25|1,22|
|80|275,5|123,0|73,6|2,72|3,74|4,35|
|85|324,9|154,3|95,8|3,21|2,25|2,33|
|90|390,4|175,6|109,4|2,52|3,49|3,68|
|95|447,5|212,0|133,5|2,99|2,27|1,13|
|100|521,7|238,3|141,5|-|-|-|