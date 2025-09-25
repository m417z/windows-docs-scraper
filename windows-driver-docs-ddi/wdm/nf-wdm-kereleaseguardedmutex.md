# KeReleaseGuardedMutex function

## Description

The **KeReleaseGuardedMutex** routine releases a guarded mutex acquired with [KeAcquireGuardedMutex](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551892(v=vs.85)) or [KeTryToAcquireGuardedMutex](https://learn.microsoft.com/previous-versions/ff553307(v=vs.85)).

## Parameters

### `Mutex` [in, out]

Pointer to the [KGUARDED_MUTEX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the guarded mutex.

## Remarks

**KeReleaseGuardedMutex** implicitly exits the guarded region entered by **KeAcquireGuardedMutex** and **KeTryToAcquireGuardedMutex**.

For more information about guarded mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

## See also

[KeAcquireGuardedMutex](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551892(v=vs.85))