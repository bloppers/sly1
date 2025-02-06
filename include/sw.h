/**
 * @file sw.h
 *
 * @brief Scene world?
 */
#ifndef SW_H
#define SW_H

#include "common.h"
#include <lo.h>
#include <mq.h>

// todo Implement struct.
struct SW : public LO
{
    undefined1 padding1[0x8];
    DL dlRoot;
    DL dlChild;
    undefined1 padding2[0x1bff];
    DL dlDprize;
};

extern SW *g_psw;

MQ *PmqAllocSw(SW *psw);
void IncrementSwHandsOff(SW *psw);
void FreeSwMqList(SW *psw, MQ *pmq);

#endif // SW_H
