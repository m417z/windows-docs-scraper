# KeSaveExtendedProcessorState function

## Description

The **KeSaveExtendedProcessorState** routine saves extended processor state information.

## Parameters

### `Mask` [in]

A 64-bit feature mask. The bits in this mask identify the extended processor feature states to save. If a mask bit is one, the routine saves the state of the feature that is identified by this bit. If a mask bit is zero, the state for the corresponding feature is not saved. This mask must not identify extended processor features that the operating system has not enabled. To obtain a mask of the enabled features, call the [RtlGetEnabledExtendedFeatures](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetenabledextendedfeatures) routine.

A caller can set this parameter to the bitwise OR of one or more of the following **XSTATE_MASK_*XXX*** flag bits:

|Value|Meaning|
|--- |--- |
|**XSTATE_MASK_LEGACY_FLOATING_POINT**|The floating-point extension (x87/MMX).|
|**XSTATE_MASK_LEGACY_SSE**|The streaming SIMD extension (SSE).|
|**XSTATE_MASK_LEGACY**|Both the x87/MMX and SSE extensions.|
|**XSTATE_MASK_GSSE**|The Intel Sandy Bridge (formerly Gesher) SSE extension.|
|**XSTATE_MASK_AVX512**|AVX-512 extension|
|**XSTATE_MASK_MPX**|MPX extension|
|**XSTATE_MASK_AMX_TILE_CONFIG**|AMX extension (configuration)|
|**XSTATE_MASK_AMX_TILE_DATA**|AMX extension (data)|

### `XStateSave` [out]

A pointer to a caller-allocated buffer into which the routine writes an [XSTATE_SAVE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure. This structure contains the saved state information for the extended processor features indicated by the *Mask* parameter. The buffer must be large enough to contain this structure.

## Return value

**KeSaveExtendedProcessorState** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory allocation operation failed. |

## Remarks

On x86-based processors that support the XSAVE and XRSTOR instructions, these instructions provide a flexible mechanism to save and restore extended processor state information. **KeSaveExtendedProcessorState** uses these instructions if they are available.

To restore the extended processor state that was saved by **KeSaveExtendedProcessorState**, call the [KeRestoreExtendedProcessorState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kerestoreextendedprocessorstate) routine.

The *Mask* parameter specifies the extended processor features whose state is to be saved. A **KeRestoreExtendedProcessorState** call restores only the extended processor state that was saved by the **KeSaveExtendedProcessorState** call that saved the state.

Kernel-mode code must save the state of an extended processor feature before it uses that feature, and it must restore the state before it exits.

Interrupt service routines (ISRs) run under severe time constraints that typically prevent them from using extended processor features. However, an ISR can schedule a deferred procedure call (DPC) that uses one or more extended processor features. The DPC routine must save and restore the state of the extended features to preserve the context of the interrupted program in whose process address space the routine runs.

The [KeSaveFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesavefloatingpointstate) and [KeRestoreFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kerestorefloatingpointstate) routines save and restore just the floating-point state (the x87/MMX registers) and the SSE state.

## See also

[KeRestoreExtendedProcessorState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kerestoreextendedprocessorstate)

[KeRestoreFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kerestorefloatingpointstate)

[KeSaveFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesavefloatingpointstate)

[RtlGetEnabledExtendedFeatures](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetenabledextendedfeatures)

[XSTATE_SAVE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)