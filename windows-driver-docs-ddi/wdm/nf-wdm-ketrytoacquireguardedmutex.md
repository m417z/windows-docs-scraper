# KeTryToAcquireGuardedMutex function

## Description

The **KeTryToAcquireGuardedMutex** routine acquires a guarded mutex, if available.

## Parameters

### `Mutex` [in, out]

Pointer to the [KGUARDED_MUTEX](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the guarded mutex.

## Return value

**KeTryToAcquireGuardedMutex** returns **TRUE** if the mutex is acquired, and **FALSE** otherwise.

## Remarks

Use **KeReleaseGuardedMutex** to release the mutex.

**KeTryToAcquireGuardedMutex** returns immediately, regardless of whether it can acquire the mutex. Use **KeAcquireGuardedMutex** to put the calling thread into a wait state until mutex becomes available.

A thread that calls **KeTryToAcquireGuardedMutex** implicitly enters a guarded region, where all APCs are disabled. They remain disabled until the thread releases the mutex with **KeReleaseGuardedMutex**.

For more information about guarded mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

## See also

[KeReleaseGuardedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseguardedmutex)