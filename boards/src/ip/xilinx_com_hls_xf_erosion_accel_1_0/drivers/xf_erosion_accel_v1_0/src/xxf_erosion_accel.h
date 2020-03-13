// ==============================================================
// File generated on Fri Nov 22 15:14:42 +0800 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XXF_EROSION_ACCEL_H
#define XXF_EROSION_ACCEL_H

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
#include "xxf_erosion_accel_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XXf_erosion_accel_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XXf_erosion_accel;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XXf_erosion_accel_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XXf_erosion_accel_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XXf_erosion_accel_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XXf_erosion_accel_ReadReg(BaseAddress, RegOffset) \
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
int XXf_erosion_accel_Initialize(XXf_erosion_accel *InstancePtr, u16 DeviceId);
XXf_erosion_accel_Config* XXf_erosion_accel_LookupConfig(u16 DeviceId);
int XXf_erosion_accel_CfgInitialize(XXf_erosion_accel *InstancePtr, XXf_erosion_accel_Config *ConfigPtr);
#else
int XXf_erosion_accel_Initialize(XXf_erosion_accel *InstancePtr, const char* InstanceName);
int XXf_erosion_accel_Release(XXf_erosion_accel *InstancePtr);
#endif

void XXf_erosion_accel_Start(XXf_erosion_accel *InstancePtr);
u32 XXf_erosion_accel_IsDone(XXf_erosion_accel *InstancePtr);
u32 XXf_erosion_accel_IsIdle(XXf_erosion_accel *InstancePtr);
u32 XXf_erosion_accel_IsReady(XXf_erosion_accel *InstancePtr);
void XXf_erosion_accel_EnableAutoRestart(XXf_erosion_accel *InstancePtr);
void XXf_erosion_accel_DisableAutoRestart(XXf_erosion_accel *InstancePtr);

void XXf_erosion_accel_Set_height(XXf_erosion_accel *InstancePtr, u32 Data);
u32 XXf_erosion_accel_Get_height(XXf_erosion_accel *InstancePtr);
void XXf_erosion_accel_Set_width(XXf_erosion_accel *InstancePtr, u32 Data);
u32 XXf_erosion_accel_Get_width(XXf_erosion_accel *InstancePtr);

void XXf_erosion_accel_InterruptGlobalEnable(XXf_erosion_accel *InstancePtr);
void XXf_erosion_accel_InterruptGlobalDisable(XXf_erosion_accel *InstancePtr);
void XXf_erosion_accel_InterruptEnable(XXf_erosion_accel *InstancePtr, u32 Mask);
void XXf_erosion_accel_InterruptDisable(XXf_erosion_accel *InstancePtr, u32 Mask);
void XXf_erosion_accel_InterruptClear(XXf_erosion_accel *InstancePtr, u32 Mask);
u32 XXf_erosion_accel_InterruptGetEnabled(XXf_erosion_accel *InstancePtr);
u32 XXf_erosion_accel_InterruptGetStatus(XXf_erosion_accel *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
