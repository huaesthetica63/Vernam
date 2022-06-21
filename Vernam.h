#ifndef Vernam_h
#define Vernam_h
#include <iostream>
#include <fstream>
#include <chrono>//замеры времени исполнения кода
//прототипы всех используемых функций
bool VernamCipher(char*filename1,char*filename2,char*key);//сам алгоритм шифрования Вернама (одноразовый блокнот)
long long getSizeFile(char*filename);//функция получение размера файла в байтах
void printBinaryFile(char*filename);//печать бинарного файла в виде последовательности битов
void generateKey(char*filename, long long size);//генерация случайного ключа с последюущим сохранением в файле
#endif
