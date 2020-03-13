// ==============================================================
// File generated on Mon Oct 21 09:45:33 +0800 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xequalizehist.h"

extern XEqualizehist_Config XEqualizehist_ConfigTable[];

XEqualizehist_Config *XEqualizehist_LookupConfig(u16 DeviceId) {
	XEqualizehist_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XEQUALIZEHIST_NUM_INSTANCES; Index++) {
		if (XEqualizehist_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XEqualizehist_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XEqualizehist_Initialize(XEqualizehist *InstancePtr, u16 DeviceId) {
	XEqualizehist_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XEqualizehist_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XEqualizehist_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

