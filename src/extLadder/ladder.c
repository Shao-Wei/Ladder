#include "ladder.h"

ABC_NAMESPACE_IMPL_START

LadderSize_t * ladderSizeStart() {
    LadderSize_t * ls;
    ls = ABC_ALLOC(LadderSize_t, 1);
    ls->ladder24 = ls->ladder42 = ls->ladder33 = ls->ladder52 = ls->ladder34 = ls->ladder43 = ls->ladder62 = ls->ladder53 = ls->ladder44 = ls->ladder63 = ls->ladder54 = ls->ladder64 = 0;
    return ls;
}

void ladderSizeStop(LadderSize_t * ls) {
    ABC_FREE(ls);
}

void ladderSizeInc(LadderSize_t * ls, int cubeSize, int litSize) {
    int m[7][5];
    int c, l;
    for( c=0; c<7; c++ )
        for( l=0; l<5; l++)
            m[c][l] = 0;
    for( c=cubeSize; c<7; c++ )
        for( l=litSize; l<5; l++ )
            m[c][l] = 1;
    if(m[2][4]) { ls->ladder24++; }
    if(m[4][2]) { ls->ladder42++; }
    if(m[3][3]) { ls->ladder33++; }
    if(m[5][2]) { ls->ladder52++; }
    if(m[3][4]) { ls->ladder34++; }
    if(m[4][3]) { ls->ladder43++; }
    if(m[6][2]) { ls->ladder62++; }
    if(m[5][3]) { ls->ladder53++; }
    if(m[4][4]) { ls->ladder44++; }
    if(m[6][3]) { ls->ladder63++; }
    if(m[5][4]) { ls->ladder54++; }
    if(m[6][4]) { ls->ladder64++; }
}

void ladderSizePrint(LadderSize_t * ls, int objSize, int fVeryVerbose) {
    if(fVeryVerbose) {
    printf("ladder size stats:\n");
    printf("    ladder24 %.2f%%\n", 100* ls->ladder24/(double)objSize);
    printf("    ladder42 %.2f%%\n", 100* ls->ladder42/(double)objSize);
    printf("    ladder33 %.2f%%\n", 100* ls->ladder33/(double)objSize);
    printf("    ladder52 %.2f%%\n", 100* ls->ladder52/(double)objSize);
    printf("    ladder34 %.2f%%\n", 100* ls->ladder34/(double)objSize);
    printf("    ladder43 %.2f%%\n", 100* ls->ladder43/(double)objSize);
    printf("    ladder62 %.2f%%\n", 100* ls->ladder62/(double)objSize);
    printf("    ladder53 %.2f%%\n", 100* ls->ladder53/(double)objSize);
    printf("    ladder44 %.2f%%\n", 100* ls->ladder44/(double)objSize);
    printf("    ladder63 %.2f%%\n", 100* ls->ladder63/(double)objSize);
    printf("    ladder54 %.2f%%\n", 100* ls->ladder54/(double)objSize);
    printf("    ladder64 %.2f%%\n", 100* ls->ladder64/(double)objSize);
    }
    /**
    FILE * fp = fopen("laddersize.csv", "a");
    fprintf(fp, "%.2f%%,", 100* ls->ladder24/(double)objSize);
    fprintf(fp, "%.2f%%,", 100* ls->ladder42/(double)objSize);
    fprintf(fp, "%.2f%%,", 100* ls->ladder33/(double)objSize);
    fprintf(fp, "%.2f%%,", 100* ls->ladder52/(double)objSize);
    fprintf(fp, "%.2f%%,", 100* ls->ladder34/(double)objSize);
    fprintf(fp, "%.2f%%,", 100* ls->ladder43/(double)objSize);
    fprintf(fp, "%.2f%%,", 100* ls->ladder62/(double)objSize);
    fprintf(fp, "%.2f%%,", 100* ls->ladder53/(double)objSize);
    fprintf(fp, "%.2f%%,", 100* ls->ladder44/(double)objSize);
    fprintf(fp, "%.2f%%,", 100* ls->ladder63/(double)objSize);
    fprintf(fp, "%.2f%%,", 100* ls->ladder54/(double)objSize);
    fprintf(fp, "%.2f%%\n", 100* ls->ladder64/(double)objSize);
    fclose(fp);
    */
}

ABC_NAMESPACE_IMPL_END