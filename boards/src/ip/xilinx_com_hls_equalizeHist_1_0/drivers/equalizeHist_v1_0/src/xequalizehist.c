// ==============================================================
// File generated on Mon Oct 21 09:45:33 +0800 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xequalizehist.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XEqualizehist_CfgInitialize(XEqualizehist *InstancePtr, XEqualizehist_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XEqualizehist_Start(XEqualizehist *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEqualizehist_ReadReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_AP_CTRL) & 0x80;
    XEqualizehist_WriteReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XEqualizehist_IsDone(XEqualizehist *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEqualizehist_ReadReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XEqualizehist_IsIdle(XEqualizehist *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEqualizehist_ReadReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XEqualizehist_IsReady(XEqualizehist *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEqualizehist_ReadReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XEqualizehist_EnableAutoRestart(XEqualizehist *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEqualizehist_WriteReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XEqualizehist_DisableAutoRestart(XEqualizehist *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEqualizehist_WriteReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_AP_CTRL, 0);
}

void XEqualizehist_Set_rows(XEqualizehist *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEqualizehist_WriteReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_ROWS_DATA, Data);
}

u32 XEqualizehist_Get_rows(XEqualizehist *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEqualizehist_ReadReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_ROWS_DATA);
    return Data;
}

void XEqualizehist_Set_cols(XEqualizehist *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEqualizehist_WriteReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_COLS_DATA, Data);
}

u32 XEqualizehist_Get_cols(XEqualizehist *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XEqualizehist_ReadReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_COLS_DATA);
    return Data;
}

void XEqualizehist_InterruptGlobalEnable(XEqualizehist *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEqualizehist_WriteReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_GIE, 1);
}

void XEqualizehist_InterruptGlobalDisable(XEqualizehist *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEqualizehist_WriteReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_GIE, 0);
}

void XEqualizehist_InterruptEnable(XEqualizehist *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XEqualizehist_ReadReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_IER);
    XEqualizehist_WriteReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_IER, Register | Mask);
}

void XEqualizehist_InterruptDisable(XEqualizehist *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XEqualizehist_ReadReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_IER);
    XEqualizehist_WriteReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_IER, Register & (~Mask));
}

void XEqualizehist_InterruptClear(XEqualizehist *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XEqualizehist_WriteReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_ISR, Mask);
}

u32 XEqualizehist_InterruptGetEnabled(XEqualizehist *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEqualizehist_ReadReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_IER);
}

u32 XEqualizehist_InterruptGetStatus(XEqualizehist *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XEqualizehist_ReadReg(InstancePtr->Axilites_BaseAddress, XEQUALIZEHIST_AXILITES_ADDR_ISR);
}

