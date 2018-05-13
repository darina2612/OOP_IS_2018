# Упражнение 10 - Шаблони на типове и функции от високо ниво

## Задача 1

Използвайки разгледаните на лекции тип 

```c++
template <typename T>
using mapFn = T (*) (T);
```
и функция 

```c++
template <typename T>
void map (T arr[], int arrsize, mapFn<T> f)
{
    for(int i = 0; i < arrsize; i++)
        arr[i] = f(arr[i]);
}
```

реализирайте
* повдигане на квадврат на елементите на подаден целочислен масив
* преобразуване на даден масив с елелементи от тип float до масив, съдържащ само неотрицателни елементи,
като за целта всеки отрицателен елемент се приравнява на 0.0.

## Задача 2

Използвайки разгледаните на лекции тип 

```c++
template <typename ResT, typename ElemT>
using reduceFn = ResT (*) (ResT, ElemT);
```
и функция 

```c++
template <typename ResT, typename ElemT>
ResT reduce (ElemT arr[], int arrsize, reduceFn<ResT, ElemT> f, ResT init)
{
    ResT result = init;
    
    for(int i = 0; i < arrsize; i++)
        result = f(result, arr[i]);
        
    return result;
}
```
реализирайте
* сумиране на елементите на масив от тип float
* сумиране само на нечетните елементи на масив от цели числа
* проверка дали в даден масив от цели числа има число, което представлява точен квадрат
* проверка дали всички елементи в даден масив от цели числа се делят на 5.

## Задача 3

Да се реализира функция
```c++
void transformArray(int arr[], int arrSize, int (*function) (int), bool (*predicate) (int))
```
която премахва от `arr` всички елементи, за които не е изпълнен `predicate`,
а стойността на всеки от останалите заменя с резултата от извикването на `function` с аргумент съответния елемент.
