## Description

The **ExTryToAcquireFastMutex** routine acquires the given fast mutex, if possible, with APCs to the current thread disabled.

## Parameters

### `FastMutex`

[in, out] A pointer to the fast mutex to be acquired if it is not currently owned by another thread.

## Return value

**ExTryToAcquireFastMutex** returns **TRUE** if the current thread is given ownership of the fast mutex.

## Remarks

If the given fast mutex is currently unowned, **ExTryToAcquireFastMutex** gives the caller ownership with APCs to the current thread disabled until it releases the fast mutex.

Use [**ExAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutex) if the current thread must wait for the acquisition of the given mutex before it can do useful work.

Any fast mutex that is acquired with **ExTryToAcquireFastMutex** or [**ExAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutex) must be released with [**ExReleaseFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasefastmutex).

For more information about fast mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

Callers of **ExTryToAcquireFastMutex** must be running at IRQL \<= APC\_LEVEL. **ExTryToAcquireFastMutex** sets the IRQL to APC\_LEVEL if the mutex is acquired, and the caller continues to run at APC\_LEVEL after **ExTryToAcquireFastMutex** returns. **ExTryToAcquireFastMutex** saves the caller's previous IRQL in the mutex if successful, however, and that IRQL is restored when the caller calls **ExReleaseFastMutex**.

## See also

[**FAST\_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes#fast-mutexes)

[**ExAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutex)

[**ExInitializeFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[**ExReleaseFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasefastmutex)