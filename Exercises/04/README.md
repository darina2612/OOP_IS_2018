# Упражнение 04 - Динамичен масив и шаблони

Време за задача!

Ползвали сте масиви, нали?

Знаете, че понякога са... неприятни... за използване. Неприятно е как веднъж създадени с определен размер, той не може да бъде променен. А когато това ни трябва? Дали не може да се направи нещо по въпроса?

Е, в стандартната библиотека (STL) има нещо, което решава този проблем... vector!

Първо, разгледайте в интернет как се използва. Това е клас, който представлява "безкраен" масив - когато неговото място свърши, той се уголемява.
http://en.cppreference.com/w/cpp/container/vector

Второ, опитайте се да направите негова много проста версия. На първо време, от нашия вектор искаме:

* Да можем да създаваме вектори, в които да се съхраняват цели числа (int)
e.g. MyIntVector v; // hint: конструктор по подразбиране

* Да можем да добавяме елементи в него
e.g. v.push_back(3); v.push_back(5);
Ако няма достатъчно място в него, той трябва да се преоразмери!

* Да можем да взимаме неговата дължина и капацитет
e.g. v.size(); v.capacity();

* Да можем да проверяваме дали векторът е празен
e.g. v.empty(); // when size is 0

* Да можем да взимаме негов елемент по индекс
e.g. v[0]; // 3, hint: operator[]

* Да можем да го инициализираме с определена дължина, тоест втори конструктор, така че да можем да изпълним
e.g. MyIntVector vectorWithCapacity(10);

* Да можем да го инициализираме с определена дължина и определена начална стойност
e.g. MyIntVector coolVector(10, 5); // вектор със стойности 5 5 5 5 5 5 5 5 5 5

* Да можем да премахваме последния елемент от него
e.g. v.pop_back();

* Да не е MyIntVector, а MyVector - да го направим шаблонен клас, за да работи с всякакви типове данни
e.g. MyVector<int> v2;
Всичко досега трябва да продължи да работи!

* Да помислим какво ще стане, ако напишем MyVector<int> v3 = v2;
Какъв тип копие (deep, shallow) ще се получи? Това ли искаме?
Ако не, не забравяйте да дефинирате копиращ конструктор и оператор за присвояване!

* Да разделим написания код досега в .h и .cpp файл

* Да се радваме на добре свършената работа

По желание, имплементирайте и други от методите на класа std::vector

ПС: Да не забравите да си освободите паметта!