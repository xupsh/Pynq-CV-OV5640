// ==============================================================
// File generated on Fri Nov 22 15:14:42 +0800 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xxf_erosion_accel.h"

extern XXf_erosion_accel_Config XXf_erosion_accel_ConfigTable[];

XXf_erosion_accel_Config *XXf_erosion_accel_LookupConfig(u16 DeviceId) {
	XXf_erosion_accel_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XXF_EROSION_ACCEL_NUM_INSTANCES; Index++) {
		if (XXf_erosion_accel_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XXf_erosion_accel_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XXf_erosion_accel_Initialize(XXf_erosion_accel *InstancePtr, u16 DeviceId) {
	XXf_erosion_accel_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XXf_erosion_accel_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XXf_erosion_accel_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

