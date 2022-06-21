#include "Vernam.h"
using namespace std;

int main(){//код для демонстрации шифровки и расшифровки произвольного файла методом "одноразового блокнота"
    srand(time(0));//инциализация генератора случайных чисел2
    long long sizeFile = getSizeFile((char*)"sample.pdf");//считываем размер файла в байтах
    if(sizeFile==-1){
        cout<<"Error!"<<endl;
        return -1;
    }
    cout<<"Size of file: "<<sizeFile<<" bytes"<<endl;
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();//отдельный замер времени для генерации ключа
    generateKey((char*)"key.bin", sizeFile);//сохраняем новый ключ в файле key.bin - он должен быть по размеру строго равен самому файлу
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time of generating key: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds" << endl;
    begin = chrono::steady_clock::now();//теперь замеряем отдельно время для куска с самим шифрованием
    bool resOperation=VernamCipher((char*)"sample.pdf", (char*)"res.pdf", (char*)"key.bin");
    end = chrono::steady_clock::now();
    if(resOperation)
        cout << "Time of encryption: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds" << endl;
    else{
        cout<<"Error!"<<endl;
        return -1;
    }
    begin = chrono::steady_clock::now();//теперь обратно расшифровываем
    resOperation=VernamCipher((char*)"res.pdf", (char*)"deciph_sample.pdf", (char*)"key.bin");//если алгоритм сработал правильно, файл расшифровки будет эквивалентен исходному
    end = chrono::steady_clock::now();
    if(resOperation)
        cout << "Time of decryption: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds" << endl;
    else{
        cout<<"Error!"<<endl;
        return -1;
    }
    return 0;
}
