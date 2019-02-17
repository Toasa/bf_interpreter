#include <stdio.h>
#include <stdlib.h>

struct Scan {
    char *input;
    int pos;
};

char *p;
char *p_org;
struct Scan *s;

void init() {
    p = malloc(sizeof(char) * 30000);

    s = malloc(sizeof(struct Scan));
    //s->input = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+.+.>++++++++++.";
    s->input = "+++++++++[>++++++++>+++++++++++>+++>+<<<<-]>.>++.+++++++..+++.>+++++.<<+++++++++++++++.>.+++.------.--------.>+.>+.";
    //s->input = "+++[-]";
    s->pos = 0;
}

void read_char();

int read_until(char c) {
    s->pos++;
    while (s->input[s->pos] != c) {
        read_char();
        s->pos++;
    }
    return s->pos;
}

int get_pos(char c) {
    int pos = 0;
    while (s->input[s->pos + pos] != c) {
        pos++;
    }
    return s->pos + pos;
}

// for debug
void check_p() {
    printf("\n ");
    for (int i = 0; i < 20; i++) {
        printf("%3d ", p_org[i] - '\0');
    }

    printf("\n");
    int p_pos = p - p_org;
    for (int i = 0; i < 4 * p_pos; i++) {
        putchar(' ');
    }
    printf("   ^\n");
}

void read_char() {
    //check_p();
    int src, dst;
    switch (s->input[s->pos]) {
        case '+':
            *p += 1; break;
        case '-':
            *p -= 1; break;
        case '.':
            putchar(*p); break;
        case '>':
            p++; break;
        case '<':
            p--; break;
        case '[':
            src = s->pos;
            dst = get_pos(']');
            while(*p) {
                dst = read_until(']');
                s->pos = src;
            }
            s->pos = dst;
            break;
        case ']':
            break;
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
    p_org = p;
    read();

    return 0;
}
