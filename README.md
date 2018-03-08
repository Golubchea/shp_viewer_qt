# ESRI shape viewer on Qt with QML
===================
	
![вид приложения](/images/1.jpg)


Приложение для просмотра 
ESRI shape файлов 
[вики](https://ru.wikipedia.org/wiki/Shapefile)


##Достоинства 
--------

* Кроссплатформенное приложение, запустися в windows linux (при упаковке ресурсов на андроиде и ios)
* Реализованы события перемещения мыши и отдаления\Приближения камеры
* Современный OpenGL для отрисовки карт и QML для пользовательского интерфейса
* С библиотека для быстрой загрузки shape файлов


##Компилирование
---------
Qt creator .pro файл для проекта

##Зависимости
---------
Проект использует Си библиотеку [shapelib](http://shapelib.maptools.org/)  

##запуск
-------
exe и dll файлы лежат в build/release

##Недостатки 
-------
* Перемещение камеры реализовано для галочки
* Пока рендерит замкнутые линии shape файлов, нет текста, точек
* Грязьненький код в 100>строк в одной функции

Использование / Contributing 
--------------------
[qt]( https://www1.qt.io/ru/licensing/) 
[shapelib](http://shapelib.maptools.org/license.html) 
Использован код из 
[GLRenderSHP](https://github.com/tiiago11/GLRenderSHP) 
А также пример из библиотеки qt 
openglwindow
OpenGLunderQML
Мой код можно использовать как угодно с ссылкой на этот репозиторий.