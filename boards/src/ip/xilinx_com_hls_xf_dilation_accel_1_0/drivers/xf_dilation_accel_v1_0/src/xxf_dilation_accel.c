// ==============================================================
// File generated on Fri Nov 22 15:18:28 +0800 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xxf_dilation_accel.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XXf_dilation_accel_CfgInitialize(XXf_dilation_accel *InstancePtr, XXf_dilation_accel_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XXf_dilation_accel_Start(XXf_dilation_accel *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XXf_dilation_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_AP_CTRL) & 0x80;
    XXf_dilation_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XXf_dilation_accel_IsDone(XXf_dilation_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XXf_dilation_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XXf_dilation_accel_IsIdle(XXf_dilation_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XXf_dilation_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XXf_dilation_accel_IsReady(XXf_dilation_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XXf_dilation_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XXf_dilation_accel_EnableAutoRestart(XXf_dilation_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XXf_dilation_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XXf_dilation_accel_DisableAutoRestart(XXf_dilation_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XXf_dilation_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_AP_CTRL, 0);
}

void XXf_dilation_accel_Set_height(XXf_dilation_accel *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XXf_dilation_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_HEIGHT_DATA, Data);
}

u32 XXf_dilation_accel_Get_height(XXf_dilation_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XXf_dilation_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_HEIGHT_DATA);
    return Data;
}

void XXf_dilation_accel_Set_width(XXf_dilation_accel *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XXf_dilation_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_WIDTH_DATA, Data);
}

u32 XXf_dilation_accel_Get_width(XXf_dilation_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XXf_dilation_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_WIDTH_DATA);
    return Data;
}

void XXf_dilation_accel_InterruptGlobalEnable(XXf_dilation_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XXf_dilation_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_GIE, 1);
}

void XXf_dilation_accel_InterruptGlobalDisable(XXf_dilation_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XXf_dilation_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_GIE, 0);
}

void XXf_dilation_accel_InterruptEnable(XXf_dilation_accel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XXf_dilation_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_IER);
    XXf_dilation_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_IER, Register | Mask);
}

void XXf_dilation_accel_InterruptDisable(XXf_dilation_accel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XXf_dilation_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_IER);
    XXf_dilation_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_IER, Register & (~Mask));
}

void XXf_dilation_accel_InterruptClear(XXf_dilation_accel *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XXf_dilation_accel_WriteReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_ISR, Mask);
}

u32 XXf_dilation_accel_InterruptGetEnabled(XXf_dilation_accel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XXf_dilation_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_IER);
}

u32 XXf_dilation_accel_InterruptGetStatus(XXf_dilation_accel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XXf_dilation_accel_ReadReg(InstancePtr->Axilites_BaseAddress, XXF_DILATION_ACCEL_AXILITES_ADDR_ISR);
}

