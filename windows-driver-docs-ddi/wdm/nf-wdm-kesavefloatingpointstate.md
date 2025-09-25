# KeSaveFloatingPointState function

## Description

The **KeSaveFloatingPointState** routine saves the nonvolatile floating-point context so the caller can carry out floating-point operations.

## Parameters

### `FloatSave` [out]

Pointer to a caller-allocated resident buffer, which must be at least **sizeof**([KFLOATING_SAVE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)).

## Return value

**KeSaveFloatingPointState** returns STATUS_SUCCESS if it saved the current thread's floating-point context and set up a fresh floating-point context for the caller. Otherwise, it returns one of the following error status codes.

| Return code | Description |
| --- | --- |
| **STATUS_ILLEGAL_FLOAT_CONTEXT** | The system is configured to use floating-point emulation, rather than doing floating-point operations in the processors. |
| **STATUS_INSUFFICIENT_RESOURCES** | **KeSaveFloatingPointState** could not allocate sufficient memory to save the current thread's floating-point context. |

## Remarks

A successful call to **KeSaveFloatingPointState** allows the caller to carry out floating-point operations of its own, but such a caller must restore the previous nonvolatile floating-point context as soon as its floating-point operations are done. Any routine that calls **KeSaveFloatingPointState** must call [KeRestoreFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kerestorefloatingpointstate) before that routine returns control.

If the call to **KeSaveFloatingPointState** is successful, the data at *FloatSave* is opaque to the caller. The caller should not release the memory that it allocated for this data until after the call to [KeRestoreFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kerestorefloatingpointstate).

In Windows Vista and earlier versions of Windows, a **KeSaveFloatingPointState** call and the corresponding **KeRestoreFloatingPointState** call must occur in a guarded region. That is, the [KeEnterGuardedRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keenterguardedregion) routine must be called before **KeSaveFloatingPointState** is called, and the [KeLeaveGuardedRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleaveguardedregion) routine must be called after **KeRestoreFloatingPointState** is called. No such requirement exists in Windows 7 and later versions of Windows.

For performance reasons, drivers should avoid doing any floating-point operations unless absolutely necessary. The overhead of saving and restoring the current thread's nonvolatile floating-point state degrades the performance of any driver that does floating-point operations.

## See also

[KeEnterGuardedRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keenterguardedregion)

[KeGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentthread)

[KeLeaveGuardedRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleaveguardedregion)

[KeRestoreFloatingPointState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kerestorefloatingpointstate)

[PsCreateSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread)