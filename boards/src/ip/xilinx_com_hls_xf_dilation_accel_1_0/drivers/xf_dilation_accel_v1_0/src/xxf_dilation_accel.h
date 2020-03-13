// ==============================================================
// File generated on Fri Nov 22 15:18:28 +0800 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XXF_DILATION_ACCEL_H
#define XXF_DILATION_ACCEL_H

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
#include "xxf_dilation_accel_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XXf_dilation_accel_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XXf_dilation_accel;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XXf_dilation_accel_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XXf_dilation_accel_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XXf_dilation_accel_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XXf_dilation_accel_ReadReg(BaseAddress, RegOffset) \
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
int XXf_dilation_accel_Initialize(XXf_dilation_accel *InstancePtr, u16 DeviceId);
XXf_dilation_accel_Config* XXf_dilation_accel_LookupConfig(u16 DeviceId);
int XXf_dilation_accel_CfgInitialize(XXf_dilation_accel *InstancePtr, XXf_dilation_accel_Config *ConfigPtr);
#else
int XXf_dilation_accel_Initialize(XXf_dilation_accel *InstancePtr, const char* InstanceName);
int XXf_dilation_accel_Release(XXf_dilation_accel *InstancePtr);
#endif

void XXf_dilation_accel_Start(XXf_dilation_accel *InstancePtr);
u32 XXf_dilation_accel_IsDone(XXf_dilation_accel *InstancePtr);
u32 XXf_dilation_accel_IsIdle(XXf_dilation_accel *InstancePtr);
u32 XXf_dilation_accel_IsReady(XXf_dilation_accel *InstancePtr);
void XXf_dilation_accel_EnableAutoRestart(XXf_dilation_accel *InstancePtr);
void XXf_dilation_accel_DisableAutoRestart(XXf_dilation_accel *InstancePtr);

void XXf_dilation_accel_Set_height(XXf_dilation_accel *InstancePtr, u32 Data);
u32 XXf_dilation_accel_Get_height(XXf_dilation_accel *InstancePtr);
void XXf_dilation_accel_Set_width(XXf_dilation_accel *InstancePtr, u32 Data);
u32 XXf_dilation_accel_Get_width(XXf_dilation_accel *InstancePtr);

void XXf_dilation_accel_InterruptGlobalEnable(XXf_dilation_accel *InstancePtr);
void XXf_dilation_accel_InterruptGlobalDisable(XXf_dilation_accel *InstancePtr);
void XXf_dilation_accel_InterruptEnable(XXf_dilation_accel *InstancePtr, u32 Mask);
void XXf_dilation_accel_InterruptDisable(XXf_dilation_accel *InstancePtr, u32 Mask);
void XXf_dilation_accel_InterruptClear(XXf_dilation_accel *InstancePtr, u32 Mask);
u32 XXf_dilation_accel_InterruptGetEnabled(XXf_dilation_accel *InstancePtr);
u32 XXf_dilation_accel_InterruptGetStatus(XXf_dilation_accel *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
