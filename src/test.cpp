#include "vec.hpp"
#define WIDTH 4
#define HEIGHT 3
#define DIMENION WIDTH * HEIGHT
int main(){
    for (int i = 0; i < DIMENION/2; ++i){
        printf("*");
        if (i%WIDTH/2 == WIDTH/2){
            printf("\n");
        }
    }
}
