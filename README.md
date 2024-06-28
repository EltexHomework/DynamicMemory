# Задание №6 - Динамическая память
## Сборщик проекта
В качестве сборщика проекта используется Makefile. Для компиляции проекта необходимо ввести следующую команду в корне проекта:
``` bash
make
```

Для очистки бинарных файлов можно воспользоваться командой:
``` bash
make clean
```

## Задание
Переписать справочник абонентов (задание на структуры) со статического массива структур на динамический. При запуске программы массив пуст, при добавлении первого абонента выделяется память только под один элемент. По мере добавления абонентов массив увеличивается по одному элементу. При удалении, элемент, который удаляется, перемещается в конец массива и размер массива уменьшается на один элемент. По завершению программы память под массив высвобождается. В остальном функционал, как и в предыдущем задании.
## Результаты тестирования программы
- Создание абонента
```
___MENU___
1) Add abonent
2) Delete abonent
3) Find abonent by name
4) Print all abonents
5) Exit
Enter option: 1
Enter name: danil
Enter second name: gorshkov
Enter tel: 222
```
- Удаление абонента
```
___MENU___
1) Add abonent
2) Delete abonent
3) Find abonent by name
4) Print all abonents
5) Exit
Enter option: 2
Enter name: danil


___MENU___
1) Add abonent
2) Delete abonent
3) Find abonent by name
4) Print all abonents
5) Exit
Enter option: 4
```
- Поиск абонента
```
___MENU___
1) Add abonent
2) Delete abonent
3) Find abonent by name
4) Print all abonents
5) Exit
Enter option: 3
Enter name: danil

___Abonent___
Abonent name: danil
Abonent second_name: gorshkov
Abonent tel: 222
```
- Вывод всех записей
```
___MENU___
1) Add abonent
2) Delete abonent
3) Find abonent by name
4) Print all abonents
5) Exit
Enter option: 4

___Abonent___
Abonent name: danil
Abonent second_name: gorshkov
Abonent tel: 222

___Abonent___
Abonent name: danil
Abonent second_name: petrow
Abonent tel: 333
```
- Выход
```
___MENU___
1) Add abonent
2) Delete abonent
3) Find abonent by name
4) Print all abonents
5) Exit
Enter option: 5 
```
## Демонстрация работы программ
![image](https://github.com/EltexHomework/DynamicMemory/assets/70006380/95777e3a-3dbd-46c9-af4f-db812d4c284f)

