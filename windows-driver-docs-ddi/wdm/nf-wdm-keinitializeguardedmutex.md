# KeInitializeGuardedMutex function

## Description

The **KeInitializeGuardedMutex** routine initializes a guarded mutex.

## Parameters

### `Mutex` [out]

Pointer to the [KGUARDED_MUTEX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure to initialize. The storage must be 4-byte aligned on 32-bit platforms, and 8-byte aligned on 64-bit platforms.

## Remarks

Guarded mutexes must be allocated from nonpaged pool.

For more information about guarded mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

## See also

[KGUARDED_MUTEX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeAcquireGuardedMutex](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551892(v=vs.85))