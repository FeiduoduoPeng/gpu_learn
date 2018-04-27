#include<stdio.h>
#include<time.h>

#define N 65534
void add(int* a, int* b, int* c){
    for(int i=0; i<N; i++)
        c[i] = a[i]*3 - b[i]*2%2 + 111;
}

int main(void){
    int a[N], b[N], c[N];
    //int *dev_a, *dev_b, *dev_c;
    //cudaMalloc((void**) &dev_a, N*sizeof(int));
    //cudaMalloc((void**) &dev_b, N*sizeof(int));
    //cudaMalloc((void**) &dev_c, N*sizeof(int));

    for(int i=0; i<N ; i++){
        a[i] = i;
        b[i] = i;
    }
    //cudaMemcpy(dev_a, a, N*sizeof(int), cudaMemcpyHostToDevice);
    //cudaMemcpy(dev_b, b, N*sizeof(int), cudaMemcpyHostToDevice);

    //add<<<N,1>>>(dev_a, dev_b, dev_c);

    //cudaMemcpy(c, dev_c, N*sizeof(int), cudaMemcpyDeviceToHost);
    clock_t start, end;
    double duration;
    start = clock();
    add(a,b,c);
    end = clock();
    duration = (double)(end - start);
    printf("elapsed: %f", duration);
    //printf("vactor sum is:\n");
    //for(int i=0; i<N; i++){
    //    printf("%d  ", c[i]);

    //}
    //cudaFree(dev_a);
    //cudaFree(dev_b);
    //cudaFree(dev_c);
    return 0;
}
