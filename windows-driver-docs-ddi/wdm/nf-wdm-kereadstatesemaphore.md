# KeReadStateSemaphore function

## Description

The **KeReadStateSemaphore** routine returns the current state, signaled or not-signaled, of the specified semaphore object.

## Parameters

### `Semaphore` [in]

Pointer to an initialized semaphore object for which the caller provides the storage.

## Return value

If the return value is zero, the semaphore object is set to a not-signaled state.

## Remarks

This routine provides an efficient way to poll the signal state of a semaphore. **KeReadStateSemaphore** reads the state of the semaphore without synchronizing its access to the semaphore. Do not assume that accesses of a semaphore state by **KeReadStateSemaphore** are mutually exclusive of accesses by routines, such as [KeReleaseSemaphore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasesemaphore) and [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject), that do synchronize their access to the semaphore state.

For more information about semaphore objects, see [Semaphore Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/semaphore-objects).

## See also

[KeInitializeSemaphore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializesemaphore)

[KeReleaseSemaphore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasesemaphore)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)