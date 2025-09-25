## Description

The **ExReleaseFastMutex** routine releases ownership of a fast mutex that was acquired with [**ExAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutex) or [**ExTryToAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-extrytoacquirefastmutex).

## Parameters

### `FastMutex`

[in, out] A pointer to the fast mutex to be released.

## Remarks

**ExReleaseFastMutex** releases ownership of the given fast mutex and sets the IRQL to the value that the caller was running at before it called [**ExAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutex). If the previous IRQL was less than APC\_LEVEL, the delivery of APCs to the current thread is reenabled.

It is a programming error to call **ExReleaseFastMutex** with a *FastMutex* that was acquired using **ExAcquireFastMutexUnsafe**. Drivers should release a fast mutex from the same thread that acquired it. Fast mutexes should be released in the opposite order from the order they were acquired.

For more information about fast mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

Callers of **ExReleaseFastMutex** must be running at IRQL = APC\_LEVEL. In most cases the IRQL will already be set to APC\_LEVEL before **ExReleaseFastMutex** is called because **ExAcquireFastMutex** has already set the IRQL to APC\_LEVEL automatically. However, if the caller changes the IRQL after **ExAcquireFastMutex** returns, the caller must explicitly set the IRQL to APC\_LEVEL prior to calling **ExReleaseFastMutex**.

## See also

[**FAST\_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes#fast-mutexes)

[**ExAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutex)

[**ExInitializeFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[**ExTryToAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-extrytoacquirefastmutex)