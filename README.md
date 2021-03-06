# Vernam cipher
### Vernam cipher implementation in C++ with time measurement
### Шифр Вернама ("одноразовый блокнот")
Шифр Вернама основывается на операции XOR случайного секретного ключа и исходного текста.
И при шифровании, и при дешифровании используется один и тот же ключ и одна и та же функция.
Для работы алгоритма шифрования необходим одноразовый ключ, равный по размеру исходному файлу, для этого
программа сначала считывает размер файла в байтах, затем генерирует случайную последовательность такой же длины
с последующей записью в созданный файл key.bin. В функции main показана демонстрация работы алгоритма формирования
секретного ключа и самого процесса шифрования и дешифрования, все три операции замеряются по времени выполнения, результат в мс выводится на консоль.
Вместо "sample.pdf" можно вставить путь к любому произвольному файлу. Ключевой файл и результат шифрования сохраняются в директории с исполняемым файлом программы.

<img width="306" alt="image" src="https://user-images.githubusercontent.com/46458667/174833688-955b7466-eaaa-43f0-9d2d-ba2b14be88db.png">

Замеры времени производились для PDF-файла размером 2.2 МБ.

В дальнейшем планируется усовершенствовать метод генерации случайного ключа, сделав тем самым его более безопасным (криптостойким). Например, с помощью алгоритма MD5.
