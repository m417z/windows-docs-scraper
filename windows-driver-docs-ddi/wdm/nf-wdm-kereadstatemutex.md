# KeReadStateMutex function

## Description

The **KeReadStateMutex** routine returns the current state, signaled or not-signaled, of the specified mutex object.

## Parameters

### `Mutex` [in]

Pointer to an initialized mutex object for which the caller provides the storage.

## Return value

If the return value is 1, the state of the mutex object is signaled.

## Remarks

This routine provides an efficient way to poll the signal state of a mutex. **KeReadStateMutex** reads the state of the mutex without synchronizing its access to the mutex. Do not assume that accesses of a mutex state by **KeReadStateMutex** are mutually exclusive of accesses by routines, such as [KeReleaseMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasemutex) and [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject), that do synchronize their access to the mutex state.

For more information about mutex objects, see [Mutex Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/mutex-objects).

## See also

[ExInitializeFastMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[KeInitializeMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializemutex)

[KeReleaseMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasemutex)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)