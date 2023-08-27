void reuso(float x, float y, float z, float *u, float *v, float *w) {
        float a;
        a = x + y + z;
        *u = a;
        a = y * z;
        *v = a;
        a = x * z;
        *w = a;
}
