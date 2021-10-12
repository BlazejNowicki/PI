#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void divide(int m[], int res[], int size) {
    int i = 0, r = 0;
    while (m[i] == 0) {
        i++;
    }

    while (i < size) {
        int a = m[i] + 10 * r;
        if (a % 2 == 0) {
            res[i] = a / 2;
            r = 0;
        } else {

            a = a * 10 + m[i + 1];
            if (a % 2 == 0) {
                res[i] = (a / 2) / 10;
                res[i + 1] = (a / 2) % 10;
                r = 0;

            } else {
                a -= 1;
                res[i] = (a / 2) / 10;
                res[i + 1] = (a / 2) % 10;
                r = 1;
                //i++;
            }
            //
            i++;
        }
        i++;
    }


}

int main() {
    char *s = (char *) malloc((size_t) (30) * sizeof(char));
    scanf("%s", s);
    int len = (int) (strlen(s));
    int *n = (int *) calloc(sizeof(int), (size_t) 30);
    int *m = (int *) calloc(sizeof(int), (size_t) 30);
    int *in = (int *) malloc((size_t) (100) * sizeof(int));
    int *out = (int *) malloc((size_t) (100) * sizeof(int));
    for(int i=30-len; i<30; ++i){
        n[i] = s[i]-'0';
        m[i] = n[i];
    }

    //int can_in = 0;//, can_out = 0;
    for (int i = 0; i < 100; i++) {
        in[i] = 0;
        out[i] = 0;
    }

    for (int j = 0; j < 30; j++) {
        //flag = 1;
        printf("%d ", m[j]);
//            if (m[i] != 0){
//                flag = 0;
//                break;
//            }
    }



//    int i = 0, r = 0;
//    while (i < len) {
//        int a = m[i] + 10 * r;
//        if (a % 2 == 0) {
//            temp[i] = a / 2;
//            r = 0;
//        } else {
//
//            a = a * 10 + m[i + 1];
//            if (a % 2 == 0) {
//                temp[i] = (a / 2) / 10;
//                temp[i + 1] = (a / 2) % 10;
//                r = 0;
//
//            } else {
//                a -= 1;
//                temp[i] = (a / 2) / 10;
//                temp[i + 1] = (a / 2) % 10;
//                r = 1;
//                //i++;
//            }
//            //
//            i++;
//        }
//        i++;
//    }

//    int i = 0, r;//, flag=0;
//    while(i < 5){
//        r = (m[30-1])%2;
//        in[i] = abs(r);
//        m[30-1] -= r;
//        int *temp = (int *) malloc((size_t) (30) * sizeof(int));
//
//        for(int j = 0; j < 30; j++){
//            divide(m, temp, 30);
//            if(i%2==1){
//                m[j] = -temp[j];
//            }
//
//        }
////        for(int j = 0; j < 30; j++){
////            //flag = 1;
////            printf("%d ", m[j]);
//////            if (m[i] != 0){
//////                flag = 0;
//////                break;
//////            }
//        //}
//        //printf("\n");
////        if(flag){
////            can_in = 1;
////            break;
////        }
//        i++;
//    }



//    int j = 0;
//    m = -n;
//    while (j < 100) {
//        out[j] = abs(m % 2);
//        m = (m - out[j]) / (-2);
//        if (m == 0) {
//            can_out = 1;
//            break;
//        }
//        j++;
//    }

//    if (can_in == 1) {
//        for (i = 0; i < 100; i++) {
//            if (in[i] != 0) {
//                printf("%d ", i);
//            }
//        }
//        printf("\n");
//
//    } else {
//        printf("NO\n");
//    }

//    if (can_out == 1) {
//        for (i = 0; i < 100; i++) {
//            if (out[i] != 0) {
//                printf("%d ", i);
//            }
//        }
//    } else {
//        printf("NO");
//    }

    return 0;
}