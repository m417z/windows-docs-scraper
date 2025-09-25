## Description

The **ExAcquireFastMutexUnsafe** routine acquires the specified fast mutex for the calling thread.

## Parameters

### `FastMutex`

[in, out] A pointer to a [**FAST\_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes#fast-mutexes)) structure that the caller provides the storage for. The caller previously initialized this structure by a call to the [**ExInitializeFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex) routine

## Remarks

**ExAcquireFastMutexUnsafe** puts the caller into a wait state if the specified fast mutex cannot be acquired immediately. Otherwise, the caller is given ownership of the mutex and exclusive access to the resource that the mutex protects until the caller releases the mutex.

Any fast mutex that is acquired by a call to **ExAcquireFastMutexUnsafe** must be released by a call to the [**ExReleaseFastMutexUnsafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasefastmutexunsafe) routine.

The [**ExAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutex) and **ExAcquireFastMutexUnsafe** routines cause the calling thread to block until the mutex is available. The [**ExTryToAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-extrytoacquirefastmutex) routine returns immediately with return value **FALSE** if another thread has already acquired the mutex. Both **ExAcquireFastMutex** and **ExTryToAcquireFastMutex** raise the IRQL to APC\_LEVEL before acquiring the fast mutex. Drivers should use **ExAcquireFastMutexUnsafe**, which does not raise the IRQL, only if either of the following is true:

  - The thread is already running at APC\_LEVEL.

  - The thread acquires the mutex within a critical region that was previously entered by a call to the [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keentercriticalregion) or [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) routine.

For more information about fast mutexes, see the following topics:

[Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes)

[Locks, Deadlocks, and Synchronization](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks)

## See also

[**ExAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirefastmutex)

[**ExInitializeFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[**ExReleaseFastMutexUnsafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasefastmutexunsafe)

[**ExTryToAcquireFastMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-extrytoacquirefastmutex)

[**FAST\_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes#fast-mutexes)

[**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem)

[**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keentercriticalregion)

[**KeLeaveCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keleavecriticalregion)