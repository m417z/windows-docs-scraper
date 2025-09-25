# KeInitializeMutex function

## Description

The **KeInitializeMutex** routine initializes a mutex object, setting it to a signaled state.

## Parameters

### `Mutex` [out]

Pointer to a mutex object, for which the caller provides the storage. The storage must be 4-byte aligned on 32-bit platforms, and 8-byte aligned on 64-bit platforms.

### `Level` [in]

Reserved. Drivers set this to zero.

## Remarks

For better performance, use fast mutexes or guarded mutexes. For more information, see [Alternatives to Mutex Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/alternatives-to-mutex-objects).

The mutex object is initialized with an initial state of signaled.

Storage for a mutex object must be resident: in the device extension of a driver-created device object, in the controller extension of a driver-created controller object, or in nonpaged pool allocated by the caller.

For more information about mutex objects, see [Mutex Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-mutex-objects).

## See also

[ExInitializeFastMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[KeReadStateMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstatemutex)

[KeReleaseMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasemutex)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)