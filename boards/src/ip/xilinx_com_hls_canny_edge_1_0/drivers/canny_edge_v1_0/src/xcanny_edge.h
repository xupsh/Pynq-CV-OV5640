// ==============================================================
// File generated on Mon Oct 28 13:17:19 +0800 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XCANNY_EDGE_H
#define XCANNY_EDGE_H

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
#include "xcanny_edge_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XCanny_edge_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XCanny_edge;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XCanny_edge_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XCanny_edge_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XCanny_edge_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XCanny_edge_ReadReg(BaseAddress, RegOffset) \
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
int XCanny_edge_Initialize(XCanny_edge *InstancePtr, u16 DeviceId);
XCanny_edge_Config* XCanny_edge_LookupConfig(u16 DeviceId);
int XCanny_edge_CfgInitialize(XCanny_edge *InstancePtr, XCanny_edge_Config *ConfigPtr);
#else
int XCanny_edge_Initialize(XCanny_edge *InstancePtr, const char* InstanceName);
int XCanny_edge_Release(XCanny_edge *InstancePtr);
#endif

void XCanny_edge_Start(XCanny_edge *InstancePtr);
u32 XCanny_edge_IsDone(XCanny_edge *InstancePtr);
u32 XCanny_edge_IsIdle(XCanny_edge *InstancePtr);
u32 XCanny_edge_IsReady(XCanny_edge *InstancePtr);
void XCanny_edge_EnableAutoRestart(XCanny_edge *InstancePtr);
void XCanny_edge_DisableAutoRestart(XCanny_edge *InstancePtr);

void XCanny_edge_Set_rows(XCanny_edge *InstancePtr, u32 Data);
u32 XCanny_edge_Get_rows(XCanny_edge *InstancePtr);
void XCanny_edge_Set_cols(XCanny_edge *InstancePtr, u32 Data);
u32 XCanny_edge_Get_cols(XCanny_edge *InstancePtr);
void XCanny_edge_Set_low_threshold(XCanny_edge *InstancePtr, u32 Data);
u32 XCanny_edge_Get_low_threshold(XCanny_edge *InstancePtr);
void XCanny_edge_Set_high_threshold(XCanny_edge *InstancePtr, u32 Data);
u32 XCanny_edge_Get_high_threshold(XCanny_edge *InstancePtr);

void XCanny_edge_InterruptGlobalEnable(XCanny_edge *InstancePtr);
void XCanny_edge_InterruptGlobalDisable(XCanny_edge *InstancePtr);
void XCanny_edge_InterruptEnable(XCanny_edge *InstancePtr, u32 Mask);
void XCanny_edge_InterruptDisable(XCanny_edge *InstancePtr, u32 Mask);
void XCanny_edge_InterruptClear(XCanny_edge *InstancePtr, u32 Mask);
u32 XCanny_edge_InterruptGetEnabled(XCanny_edge *InstancePtr);
u32 XCanny_edge_InterruptGetStatus(XCanny_edge *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
