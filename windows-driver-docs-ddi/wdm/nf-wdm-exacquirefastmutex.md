## Description

The **ExAcquireFastMutex** routine acquires the given fast mutex with APCs to the current thread disabled.

## Parameters

### `FastMutex`

[in, out] A pointer to an initialized fast mutex for which the caller provides the storage.

## Remarks

**ExAcquireFastMutex** puts the caller into a wait state if the given fast mutex cannot be acquired immediately. Otherwise, the caller is given ownership of the fast mutex with APCs to the current thread disabled until it releases the fast mutex.

Use [**ExTryToAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-extrytoacquirefastmutex) if the current thread can do other work before it waits on the acquisition of the given mutex.

Any fast mutex that is acquired using **ExAcquireFastMutex** or **ExTryToAcquireFastMutex** must be released with [**ExReleaseFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasefastmutex).

For more information about fast mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

Callers of **ExAcquireFastMutex** must be running at IRQL \<= APC\_LEVEL. **ExAcquireFastMutex** sets the IRQL to APC\_LEVEL, and the caller continues to run at APC\_LEVEL after **ExAcquireFastMutex** returns. **ExAcquireFastMutex** saves the caller's previous IRQL in the mutex, however, and that IRQL is restored when the caller invokes **ExReleaseFastMutex**.

## See also

[**FAST\_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes#fast-mutexes)

[**ExAcquireFastMutexUnsafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutexunsafe)

[**ExInitializeFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[**ExReleaseFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasefastmutex)

[**ExTryToAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-extrytoacquirefastmutex)