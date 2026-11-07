// copied from the internet... 
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void patch_bytes(fstream* fs, int offset, const char* bytes){
    fs->seekg(offset, ios::beg);
    fs->write(bytes, strlen(bytes));
}

void read_bytes(fstream *fs, int offset, int length){
    fs->seekg(offset, ios::beg);
    char* buffer = new char[length + 1];
    buffer[length] = '\0';
    fs->read(buffer, length);
    cout << buffer << endl;

    delete[] buffer;
}

int main(){
    fstream file_stream;

    file_stream.open("schedgs.obj", ios::in | ios::out | ios::binary);

    cout << "Original: ";
    read_bytes(&file_stream, 0x2009, 5);

    const char* new_string = "\x42\x72\x69\x61\x6e";
    patch_bytes(&file_stream, 0x2009, new_string);
    cout << "Patched: ";
    read_bytes(&file_stream, 0x2009, 5);

    file_stream.close();
    return 0;
}
