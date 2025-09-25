## Description

The **ExReleaseFastMutexUnsafe** routine releases ownership of a fast mutex that was acquired by using [**ExAcquireFastMutexUnsafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutexunsafe).

## Parameters

### `FastMutex`

[in, out] A pointer to the fast mutex to be released.

## Remarks

It is a programming error to call **ExReleaseFastMutexUnsafe** with a pointer to a fast mutex that was acquired by using [**ExAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutex) or [**ExTryToAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-extrytoacquirefastmutex).

For more information about fast mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

## See also

[**FAST\_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes#fast-mutexes)

[**ExAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutex)

[**ExAcquireFastMutexUnsafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutexunsafe)

[**ExInitializeFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[**ExTryToAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-extrytoacquirefastmutex)