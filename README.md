**Терехов Николай задача A001**

#### Взаимодействеие
вводите либо word, лиюо text, либо letters (в зависимости от запроса)
потом вводите строку запроса


#### Реализация
У меня все реализованно для английского языка

К сожалению я не сделал оптимизацию для добавления новых символов(у меня заново будет проходить поиск как будто это новый запрос)

Есть три класса 

Autocompleter - реализованна основная логика работы программы

UserConsole - работа с консолью

WordStorage - контейнер со словами

Для решения использую бор с подсчетом вхождения каждой строки

Поиск подсказки реализую через рекурскивный обход сыновей в боре и нахождения самой часто встречающейся строки. 