## Description

The **KeAcquireGuardedMutexUnsafe** acquires a guarded mutex while inside a guarded region.

## Parameters

### `FastMutex`

[in, out] Pointer to the [**KGUARDED\_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the guarded mutex.

## Remarks

Use **KeReleaseGuardedMutexUnsafe** to release a guarded mutex acquired with **KeAcquireMutexUnsafe**.

**KeAcquireGuardedMutexUnsafe** does not implicitly place the calling thread within a guarded region. Code enclosed within a **KeAcquireGuardedMutexUnsafe**/**KeReleaseGuardedMutexUnsafe** pair must execute either at IRQL = APC\_LEVEL, or within a guarded region. For code that is not guaranteed to execute within a guarded region, use **KeAcquireGuardedMutex** and **KeReleaseGuardedMutexUnsafe**.

A guarded mutex cannot be acquired recursively: if a thread is already holding the mutex when it calls **KeAcquireGuardedMutexUnsafe**, the thread will deadlock.

For more information about guarded mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

## See also

[**KGUARDED\_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[**KeReleaseGuardedMutexUnsafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseguardedmutexunsafe)