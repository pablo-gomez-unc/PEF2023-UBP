int main(void){
    const int C = 1024;
    int s = 0;
    for (unsigned int i=0; i<C; ++i) {
        s += i;
    }
    return s;
}