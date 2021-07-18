#include <cstdio>
#include <cstring>

bool func(char* str, int n) {
    for (int i = 0; i < n; i++) {
        if (str[i] == ')') {
            for (int j = i - 1; j >= 0; j--) {
                if (str[j] == '(') {
                    str[i] = str[j] = '*';
                    break;
                    func(str, n);
                }
                if (str[j] == '{') {
                    printf("ERROR");
                    return false;
                }
            }
        }
        if (str[i] == '}') {
            for (int j = i - 1; j >= 0; j--) {
                if (str[j] == '{') {
                    str[i] = str[j] = '*';
                    break;
                    func(str, n);
                }
                if (str[j] == '(') {
                    printf("ERROR");
                    return false;
                }
            }
        }
        if (str[i] == ']') {
            for (int j = i - 1; j >= 0; j--) {
                if (str[j] == '[') {
                    str[i] = str[j] = '*';
                    break;
                    func(str, n);
                }
                if (str[j] == '(') {
                    printf("ERROR");
                    return false;
                }
            }
        }
    }
}

int main() {
    char test[] = "(a[i] if(0) [14[],5] [{}])";
    printf("%s", (func(test, strlen(test))) ? "OK" : "FAIL");
    return 0;
}
