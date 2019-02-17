#include <stdio.h>
#include <stdlib.h>

struct Scan {
    char *input;
    int pos;
};

char *p;
struct Scan *s;

void init() {
    p = malloc(sizeof(char) * 30000);

    s = malloc(sizeof(struct Scan));
    s->input = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+.+.>++++++++++.";
    s->pos = 0;
}

void read_char() {
    switch (s->input[s->pos]) {
        case '+':
            *p += 1; break;
        case '.':
            putchar(*p); break;
        case '>':
            p++; break;
        case '<':
            p--; break;
    }
}

void read() {
    while(s->input[s->pos] != '\0'){
        read_char();
        s->pos++;
    }
}

int main() {
    init();
    read();

    return 0;
}
