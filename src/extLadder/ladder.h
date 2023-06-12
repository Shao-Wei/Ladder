#ifndef ABC__ext__ladder_h
#define ABC__ext__ladder_h

#include "base/abc/abc.h"

ABC_NAMESPACE_HEADER_START

typedef struct LadderSize_ LadderSize_t;
struct LadderSize_ {
    int ladder24, ladder42, ladder33, ladder52, ladder34, ladder43, ladder62, ladder53, ladder44, ladder63, ladder54, ladder64;
};

// ladder.c
extern LadderSize_t * ladderSizeStart();
extern void ladderSizeStop(LadderSize_t * ls);
extern void ladderSizeInc(LadderSize_t * ls, int cubeSize, int litSize);
extern void ladderSizePrint(LadderSize_t * ls, int objSize, int fVeryVerbose);

ABC_NAMESPACE_HEADER_END
#endif