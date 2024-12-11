#include <iostream>
#include <cstring>
using namespace std;

void substring(char *text, const char *search, const char *replace) {
    int textLen = strlen(text);
    int searchLen = strlen(search);
    int replaceLen = strlen(replace);
    char result[200] = "";

    int i = 0, j = 0;
    while (i < textLen) {
        if (strncmp(&text[i], search, searchLen) == 0) {
            if (j + replaceLen >= 200) {
                cout << "������: ������������ ����� � �������������� �������." << endl;
                return;
            }
            for (int k = 0; k < replaceLen; ++k) {
                result[j++] = replace[k];
            }
            i += searchLen;
        }
        else {
            if (j + 1 >= 200) {
                cout << "������: ������������ ����� � �������������� �������." << endl;
                return;
            }
            result[j++] = text[i++];
        }
    }
    result[j] = '\0';
    strcpy(text, result);
}

int main() {
    setlocale(LC_ALL, "");

    char text[200];
    char search[100];
    char replace[100];

    cout << "������� �����: ";
    cin.getline(text, 200);
    cout << "������� ������ ��� ������: ";
    cin.getline(search, 100);
    cout << "������� ������ ��� ������: ";
    cin.getline(replace, 100);

    substring(text, search, replace);
    cout << "����� ����� ������: " << text << endl;

    return 0;
}
