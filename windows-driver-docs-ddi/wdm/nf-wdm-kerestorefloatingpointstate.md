# KeRestoreFloatingPointState function

## Description

The **KeRestoreFloatingPointState** routine restores the nonvolatile floating-point context saved by the preceding call to [KeSaveFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesavefloatingpointstate).

## Parameters

### `FloatSave` [in]

A pointer to the [KFLOATING_SAVE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that was passed in the preceding call to [KeSaveFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesavefloatingpointstate).

## Return value

**KeRestoreFloatingPointState** returns STATUS_SUCCESS.

## Remarks

**KeRestoreFloatingPointState** is the reciprocal of **KeSaveFloatingPointState**.

Any routine that calls **KeSaveFloatingPointState** *must* call **KeRestoreFloatingPointState** before that routine returns control, and it must be running at the same IRQL as that from which the preceding call to **KeSaveFloatingPointState** occurred. Failure to meet either of these conditions causes a system bug check.

Kernel-mode driver code must ensure that calls to **KeSaveFloatingPointState** and **KeRestoreFloatingPointState** are properly nested. This is required so that, at each nesting level, the state that was restored by the **KeRestoreFloatingPointState** call is the same state that was saved by the corresponding **KeSaveFloatingPointState** call. To ensure proper nesting, kernel-mode driver code must follow these rules:

* A **KeRestoreFloatingPointState** call that restores a saved state must be running at the same IRQL as the **KeSaveFloatingPointState** call that saved the state.
* If a pair of **KeSaveFloatingPointState** and **KeRestoreFloatingPointState** calls is nested within a pair of surrounding **KeSaveFloatingPointState** and **KeRestoreFloatingPointState** calls, the IRQL for the nested calls must not be lower than the IRQL for the surrounding calls.
* Typically, the caller-allocated **KFLOATING_SAVE** structure that contains the state that was saved by **KeSaveFloatingPointState** resides on the stack. The stack naturally preserves the nesting of saved state information. If driver code stores the state in a location other than the stack, the driver writer must take special care to preserve the nesting of the **KeSaveFloatingPointState** and **KeRestoreFloatingPointState** calls.
* The **KeRestoreFloatingPointState** call that restores a saved state must be running in the same thread as the **KeSaveFloatingPointState** call that saved the state.

## See also

[KFLOATING_SAVE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeSaveFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesavefloatingpointstate)