# KeReleaseGuardedMutexUnsafe function

## Description

The **KeReleaseGuardedMutexUnsafe** routine releases a guarded mutex acquired by [KeAcquireGuardedMutexUnsafe](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551894(v=vs.85)).

## Parameters

### `FastMutex` [in, out]

Pointer to the [KGUARDED_MUTEX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the guarded mutex.

## Remarks

For more information about guarded mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

## See also

[KeAcquireGuardedMutexUnsafe](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551894(v=vs.85))