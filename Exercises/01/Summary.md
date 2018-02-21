# Структури

## Дефиниране на структура

```c++
struct <Тип структура>
{
  <тип на поле 1> <име на поле 1>;
  <тип на поле 2> <име на поле 2>;
  ................................
  <тип на поле n> <име на поле n>;
};
```

*Пример:*
```c++
struct Student
{
  char* name;
  int facultyNumber;
};
```
Полетата на структурата могат да бъдат както от вградени типове, така и от други потребителски дефинирани типове (в частност структури).

## Деклариране на промепливи

```c++
<Тип структура> <име на променлива>;
```

*Пример:*
```c++
Student student;
```

## Указатели към обекти от тип структура
Както и към вградените типове, можем да имаме указатели към обекти от всеки тип структура.
```c++
Student student;
Student* studentPointer = &student;
```

## Достъпване на полетата
Полетата на даден обект достъпваме чрез оператора точка (`.`), а когато имаме указател към обект, можем да достъпим полетата на обекта с оператор стрелка (`->`)
```c++
Student student;
cin >> student.facultyNumber;

Student* studentPointer = &student;
cout << studentPointer->name;
```

## Масиви от обекти от тип структура
Можем да създаваме масиви и да работим с тях по познатия начин.

*Пример:*
```c++
Student students[10];

for(size_t i = 0; i < 10; ++i)
{
	cout << students[i].name << ' ' << students[i].facultyNumber << endl;
}
```

## Структури и функции
Обекти, псевдоними на обекти и указатели към обекти могат да се подават като параметри на функции, както и да бъдат тип на връщане на функция.

*Примери:*
```c++
void function(Student s);
void function(Student& s);
void function(const Student& s);
void function(Student* sp);
void function(const Student* s);
void function(Student* arr, size_t count); //масив като параметър 
void function(Student[] arr, size_t count); //масив като параметър
...

Student function();
Student& function();
Student* function();
...
```
