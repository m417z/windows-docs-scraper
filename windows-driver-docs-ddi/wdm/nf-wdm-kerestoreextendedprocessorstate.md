# KeRestoreExtendedProcessorState function

## Description

The **KeRestoreExtendedProcessorState** routine restores extended processor state information that was previously saved.

## Parameters

### `XStateSave` [in]

A pointer to an [XSTATE_SAVE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that contains the extended processor state information to restore. The contents of this structure must have been previously saved by the [KeSaveExtendedProcessorState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesaveextendedprocessorstate) routine.

## Remarks

Kernel-mode driver code must ensure that calls to **KeSaveExtendedProcessorState** and **KeRestoreExtendedProcessorState** are properly nested. This is required so that, at each nesting level, the state that was restored by the **KeRestoreExtendedProcessorState** call is the same state that was saved by the corresponding **KeSaveExtendedProcessorState** call. To ensure proper nesting, kernel-mode driver code must follow these rules:

* A **KeRestoreExtendedProcessorState** call that restores a saved state must be running at the same IRQL as the **KeSaveExtendedProcessorState** call that saved the state.
* If a pair of **KeSaveExtendedProcessorState** and **KeRestoreExtendedProcessorState** calls is nested within a pair of surrounding **KeSaveExtendedProcessorState** and **KeRestoreExtendedProcessorState** calls, the IRQL for the nested calls must not be lower than the IRQL for the surrounding calls.
* Typically, the caller-allocated **XSTATE_SAVE** structure that contains the state that was saved by **KeSaveExtendedProcessorState** resides on the stack. The stack naturally preserves the nesting of saved state information. If driver code stores the state in a location other than the stack, the driver writer must take special care to preserve the nesting of the **KeSaveExtendedProcessorState** and **KeRestoreExtendedProcessorState** calls.
* The **KeRestoreExtendedProcessorState** call that restores a saved state must be running in the same thread as the **KeSaveExtendedProcessorState** call that saved the state.

A similar set of rules apply to the [KeSaveFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesavefloatingpointstate) and [KeRestoreFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kerestorefloatingpointstate) routines.

## See also

[KeRestoreFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kerestorefloatingpointstate)

[KeSaveExtendedProcessorState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesaveextendedprocessorstate)

[KeSaveFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesavefloatingpointstate)

[XSTATE_SAVE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)