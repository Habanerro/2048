#define CTEST_MAIN
#include "../src/header.h"
#include "../thirdparty/ctest.h"

CTEST(t_end, out_f1) {
    int i = 0, j = 0, expect = 1;
    int false[4][4];

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            false[i][j] = 14;
        }
    }

    int *pointer = &false[0][0];
    int result = endgame(pointer);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_end, out_t2) {
    int i = 0, j = 0, expect = 0;
    int true[4][4];

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            true[i][j] = 13;
        }
    }

    int *pointer = &true[0][0];
    int result = endgame(pointer);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_end, out_t3) {
    int i = 0, j = 0, expect = 0;
    int true[4][4];

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            true[i][j] = 3;
        }
    }

    int *pointer = &true[0][0];
    int result = endgame(pointer);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_end, out_f4) {
    int i = 0, j = 0, expect = 1;
    int false[4][4];

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            false[i][j] = (4 * i) + j;
        }
    }

    int *pointer = &false[0][0];
    int result = endgame(pointer);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_end, out_t5) {
    int i = 0, j = 0, expect = 0;
    int true[4][4];

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            true[i][j] = 2;
        }
    }
    true[2][3] = 0;

    int *pointer = &true[0][0];
    int result = endgame(pointer);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_merge_and_offset, res_right1) {
    int i = 0, j = 0;
    int arr[4][4];
    float expect = 36;

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 1;
    arr[1][0] = 2; arr[1][1] = 1; arr[1][2] = 1;
    arr[2][0] = 3; arr[2][1] = 3;
    arr[3][0] = 3;                arr[3][2] = 3;

    int *pointer = &arr[0][0];
    float result = mergeoff(pointer, 6);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_merge_and_offset, res_right2) {
    int i = 0, j = 0;
    int arr[4][4];
    float expect = 40;

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 1;
    arr[1][0] = 1; arr[1][1] = 1; arr[1][2] = 1; arr[1][3] = 1;
    arr[2][0] = 3; arr[2][1] = 3;
    arr[3][0] = 3;                arr[3][2] = 3;

    int *pointer = &arr[0][0];
    float result = mergeoff(pointer, 6);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_merge_and_offset, res_left1) {
    int i = 0, j = 0;
    int arr[4][4];
    float expect = 36;

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 1;
    arr[1][0] = 2; arr[1][1] = 1; arr[1][2] = 1;
    arr[2][0] = 3; arr[2][1] = 3;
    arr[3][0] = 3;                arr[3][2] = 3;

    int *pointer = &arr[0][0];
    float result = mergeoff(pointer, 4);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_merge_and_offset, res_left2) {
    int i = 0, j = 0;
    int arr[4][4];
    float expect = 40;

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 1;
    arr[1][0] = 1; arr[1][1] = 1; arr[1][2] = 1; arr[1][3] = 1;
    arr[2][0] = 3; arr[2][1] = 3;
    arr[3][0] = 3;                arr[3][2] = 3;

    int *pointer = &arr[0][0];
    float result = mergeoff(pointer, 4);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_merge_and_offset, res_up1) {
    int i = 0, j = 0;
    int arr[4][4];
    float expect = 20;

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 1;
    arr[1][0] = 2; arr[1][1] = 1; arr[1][2] = 1;
    arr[2][0] = 3; arr[2][1] = 3;
    arr[3][0] = 3;                arr[3][2] = 3;

    int *pointer = &arr[0][0];
    float result = mergeoff(pointer, 8);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_merge_and_offset, res_up2) {
    int i = 0, j = 0;
    int arr[4][4];
    float expect = 24;

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 1;
    arr[1][0] = 1; arr[1][1] = 1; arr[1][2] = 1; arr[1][3] = 1;
    arr[2][0] = 3; arr[2][1] = 3;
    arr[3][0] = 3;                arr[3][2] = 3;

    int *pointer = &arr[0][0];
    float result = mergeoff(pointer, 8);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_merge_and_offset, res_bottom1) {
    int i = 0, j = 0;
    int arr[4][4];
    float expect = 20;

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 1;
    arr[1][0] = 2; arr[1][1] = 1; arr[1][2] = 1;
    arr[2][0] = 3; arr[2][1] = 3;
    arr[3][0] = 3;                arr[3][2] = 3;

    int *pointer = &arr[0][0];
    float result = mergeoff(pointer, 2);
    ASSERT_EQUAL(expect, result);
}

CTEST(t_merge_and_offset, res_bottom2) {
    int i = 0, j = 0;
    int arr[4][4];
    float expect = 24;

   for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 1;
    arr[1][0] = 1; arr[1][1] = 1; arr[1][2] = 1; arr[1][3] = 1;
    arr[2][0] = 3; arr[2][1] = 3;
    arr[3][0] = 3;                arr[3][2] = 3;

    int *pointer = &arr[0][0];
    float result = mergeoff(pointer, 2);
    ASSERT_EQUAL(expect, result);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
