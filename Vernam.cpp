#include "Vernam.h"
using namespace std;
bool VernamCipher(char*filename1,char*filename2,char*key){//шифр Вернама, функция принимает три аргумента -
    //путь к исходному файлу, путь к файлу с шифротекстом, путь к файлу с ключевой последовательностью
    ifstream file(filename1, ios::binary|ios::in);
    ofstream cipherfile(filename2,ios::binary|ios::out);
    ifstream keyfile(key, ios::binary|ios::in);
    if((!file.is_open())||(!cipherfile.is_open())||(!keyfile.is_open()))
        return false;//ошибка с файлами -  возвращаем false как неудачное завершение функции
    short byte;//очередной считываемый байт из исходного текста
    short keybyte;//очередной считываемый байт из ключа
    while(file.read((char *)&byte,sizeof(short))){
        keyfile.read((char *)&keybyte, sizeof(short));
        short resbyte = keybyte^byte;//результирующий байт равен сумме по модулю 2 байта ключа и текста
        cipherfile.write((char *)&resbyte, sizeof(short));//записываем результирующий байт в шифротекст
    }
    file.close();
    cipherfile.close();
    keyfile.close();
    return true;//успешно завершили шифрование
}
long long getSizeFile(char*filename){//получаем размер файла в байтах
    ifstream file(filename, ios::binary);
    file.seekg(0,file.end);//ставим указатель для считывания файла в конец файла
    long long res = file.tellg();//узнаем размер
    file.seekg(0,file.beg);//снова ставим указатель в начало
    file.close();
    return res;
}
void printBinaryFile(char*filename){//вывод файла в бите последовательности байтов (может использоваться для отладки)
    ifstream file(filename, ios::binary);
    short byte;
    while(file.read((char *)&byte,sizeof(short))){
        cout<<bitset<8>(byte)<<" ";//каждый байт файла выводим в виде 8 бит (например, 01010001)
    }
    file.close();
}
void generateKey(char*filename, long long size){//генерируем рандомный ключ заданного размера и записываем в файл с названием filename
    ofstream keyfile(filename,ios::binary|ios::out);
    while(size>0){
        short byte = rand()%256;//генерируем случайный байт (число от 0 до 255)
        keyfile.write((char *)&byte, sizeof(short));
        size--;
    }
    keyfile.close();
}

