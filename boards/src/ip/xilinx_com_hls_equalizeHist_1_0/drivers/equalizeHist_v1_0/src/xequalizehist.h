// ==============================================================
// File generated on Mon Oct 21 09:45:33 +0800 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XEQUALIZEHIST_H
#define XEQUALIZEHIST_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xequalizehist_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XEqualizehist_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XEqualizehist;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XEqualizehist_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XEqualizehist_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XEqualizehist_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XEqualizehist_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XEqualizehist_Initialize(XEqualizehist *InstancePtr, u16 DeviceId);
XEqualizehist_Config* XEqualizehist_LookupConfig(u16 DeviceId);
int XEqualizehist_CfgInitialize(XEqualizehist *InstancePtr, XEqualizehist_Config *ConfigPtr);
#else
int XEqualizehist_Initialize(XEqualizehist *InstancePtr, const char* InstanceName);
int XEqualizehist_Release(XEqualizehist *InstancePtr);
#endif

void XEqualizehist_Start(XEqualizehist *InstancePtr);
u32 XEqualizehist_IsDone(XEqualizehist *InstancePtr);
u32 XEqualizehist_IsIdle(XEqualizehist *InstancePtr);
u32 XEqualizehist_IsReady(XEqualizehist *InstancePtr);
void XEqualizehist_EnableAutoRestart(XEqualizehist *InstancePtr);
void XEqualizehist_DisableAutoRestart(XEqualizehist *InstancePtr);

void XEqualizehist_Set_rows(XEqualizehist *InstancePtr, u32 Data);
u32 XEqualizehist_Get_rows(XEqualizehist *InstancePtr);
void XEqualizehist_Set_cols(XEqualizehist *InstancePtr, u32 Data);
u32 XEqualizehist_Get_cols(XEqualizehist *InstancePtr);

void XEqualizehist_InterruptGlobalEnable(XEqualizehist *InstancePtr);
void XEqualizehist_InterruptGlobalDisable(XEqualizehist *InstancePtr);
void XEqualizehist_InterruptEnable(XEqualizehist *InstancePtr, u32 Mask);
void XEqualizehist_InterruptDisable(XEqualizehist *InstancePtr, u32 Mask);
void XEqualizehist_InterruptClear(XEqualizehist *InstancePtr, u32 Mask);
u32 XEqualizehist_InterruptGetEnabled(XEqualizehist *InstancePtr);
u32 XEqualizehist_InterruptGetStatus(XEqualizehist *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
