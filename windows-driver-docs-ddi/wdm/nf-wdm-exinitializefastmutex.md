# ExInitializeFastMutex function

## Description

The **ExInitializeFastMutex** routine initializes a fast mutex variable, used to synchronize mutually exclusive access by a set of threads to a shared resource.

## Parameters

### `FastMutex` [out]

A pointer to a caller-allocated [FAST_MUTEX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, which represents the fast mutex, in the nonpaged memory pool. The allocation must be 4-byte aligned on 32-bit platforms, and 8-byte aligned on 64-bit platforms.

## Remarks

**ExInitializeFastMutex** must be called before any calls to other **Ex*Xxx*FastMutex** routines occur.

Although the caller supplies the storage for the given fast mutex, the **FAST_MUTEX** structure is opaque: that is, its members are reserved for system use.

For better performance, use the **Ex*Xxx*FastMutex** routines instead of the **Ke*Xxx*Mutex** routines. However, a fast mutex cannot be acquired recursively, as a kernel mutex can.

For more information about fast mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

## See also

[ExAcquireFastMutex](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff544337(v=vs.85))

[ExAcquireFastMutexUnsafe](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff544340(v=vs.85))

[ExReleaseFastMutex](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff545549(v=vs.85))

[ExReleaseFastMutexUnsafe](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff545567(v=vs.85))

[ExTryToAcquireFastMutex](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff545647(v=vs.85))

[FAST_MUTEX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeInitializeMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializemutex)