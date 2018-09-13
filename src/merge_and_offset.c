#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

float mergeoff(int* pointer2, int choice)
{

    int i = 0, j = 0, k = -1, power = 0;
    float plus = 0.0, score = 0.0;
    int n = 4; // Для простоты внесения изменений отностительно размеров поля (вдруг)
    int right = -1, left = -1, up = -1, down = -1;
    int changes = -1;

    switch (choice) {
        case 6: //вправо

            for (i = 0; i < n; i++) {
                right = -1;
                for (j = n - 1; j >= 0; j--) {
                    if (*(pointer2 + j + (n * i)) != 0) {
                        if (*(pointer2 + j + (n * i)) == right) {
                            *(pointer2 + j + (n * i)) = 0;
                            *(pointer2 + k + (n * i)) += 1;
                            changes = 1;
                            power = *(pointer2 + k + (i * n));
                            plus = pow(2.0, power);
                            score += plus;
                            right = -1;
                            k = -1;
                        } else {
                            right = *(pointer2 + j + (n * i));
                            k = j;
                        }
                    }
                }

                k = -1;
                for (j = n - 1; j >= 0; j--) {
                    if (*(pointer2 + j + (n * i)) == 0) {
                        if (k == -1) {
                            k = j;
                        }
                    } else if (k != -1) {
                        *(pointer2 + k + (n * i)) = *(pointer2 + j + (n * i));
                        changes = 1;
                        *(pointer2 + j + (n * i)) = 0;
                        k--;
                    }
                }
            }
            break;
        case 4: //влево

            for (i = 0; i < n; i++) {
                left = -1;
                for (j = 0; j < n; j++) {
                    if (*(pointer2 + j + (n * i)) != 0) {
                        if (*(pointer2 + j + (n * i)) == left) {
                            *(pointer2 + j + (n * i)) = 0;
                            *(pointer2 + k + (n * i)) += 1;
                            changes = 1;
                            power = *(pointer2 + k + (i * n));
                            plus = pow(2.0, power);
                            score += plus;
                            left = -1;
                            k = -1;
                        } else {
                            left = *(pointer2 + j + (n * i));
                            k = j;
                        }
                    }
                }

                k = -1;
                for (j = 0; j < n; j++) {
                    if (*(pointer2 + j + (n * i)) == 0) {
                        if (k == -1) {
                            k = j;
                        }
                    } else if (k != -1) {
                        *(pointer2 + k + (n * i)) = *(pointer2 + j + (n * i));
                        changes = 1;
                        *(pointer2 + j + (n * i)) = 0;
                        k++;
                    }
                }
            }
            break;
        case 2: //вниз

            for (j = 0; j < n; j++) {
                down = -1;
                for (i = n - 1; i >= 0; i--) {
                    if (*(pointer2 + j + (n * i)) != 0) {
                        if (*(pointer2 + j + (n * i)) == down) {
                            *(pointer2 + j + (n * i)) = 0;
                            *(pointer2 + j + (n * k)) += 1;
                            changes = 1;
                            power = *(pointer2 + j + (n * k));
                            plus = pow(2.0, power);
                            score += plus;
                            down = -1;
                            k = -1;
                        } else {
                            down = *(pointer2 + j + (n * i));
                            k = i;
                        }
                    }
                }

                k = -1;
                for (i = n - 1; i >= 0; i--) {
                    if (*(pointer2 + j + (n * i)) == 0) {
                        if (k == -1) {
                            k = i;
                        }
                    } else if (k != -1) {
                        *(pointer2 + j + (n * k)) = *(pointer2 + j + (n * i));
                        changes = 1;
                        *(pointer2 + j + (n * i)) = 0;
                        k--;
                    }
                }
            }
            break;
        case 8: //вверх

            for (j = 0; j < n; j++) {
                up = -1;
                for (i = 0; i < n; i++) {
                    if (*(pointer2 + j + (n * i)) != 0) {
                        if (*(pointer2 + j + (n * i)) == up) {
                            *(pointer2 + j + (n * i)) = 0;
                            *(pointer2 + j + (n * k)) += 1;
                            changes = 1;
                            power = *(pointer2 + j + (n * k));
                            plus = pow(2.0, power);
                            score += plus;
                            up = -1;
                            k = -1;
                        } else {
                            up = *(pointer2 + j + (n * i));
                            k = i;
                        }
                    }
                }

                k = -1;
                for (i = 0; i < n; i++) {
                    if (*(pointer2 + j + (n * i)) == 0) {
                        if (k == -1) {
                            k = i;
                        }
                    } else if (k != -1) {
                        *(pointer2 + j + (n * k)) = *(pointer2 + j + (n * i));
                        changes = 1;
                        *(pointer2 + j + (n * i)) = 0;
                        k++;
                    }
                }
            }
            break;
    }
    
    if (changes == -1) score = -1;
    return score;
}
