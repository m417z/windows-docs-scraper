## Description

The **KeAcquireGuardedMutex** routine acquires a guarded mutex.

## Parameters

### `Mutex`

[in, out] Pointer to the [**KGUARDED\_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure for the guarded mutex. This structure must have been initialized with [**KeInitializeGuardedMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeguardedmutex).

## Remarks

Use [**KeReleaseGuardedMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseguardedmutex) to release a mutex acquired with **KeAcquireGuardedMutex**.

If the mutex is available, **KeAcquireGuardedMutex** returns immediately. Otherwise, the calling thread is put in a wait state until the mutex becomes available. To avoid entering a wait state when the mutex is unavailable, use [**KeTryToAcquireGuardedMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ketrytoacquireguardedmutex).

A thread that calls **KeAcquireGuardedMutex** implicitly enters a guarded region, where all APCs are disabled. They remain disabled until the thread releases the mutex with **KeReleaseGuardedMutex**.

A guarded mutex cannot be acquired recursively: if a thread is already holding the mutex when it calls **KeAcquireGuardedMutex**, the thread will deadlock.

For more information about guarded mutexes, see [Fast Mutexes and Guarded Mutexes](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes).

## See also

[**KGUARDED\_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[**KeReleaseGuardedMutex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleaseguardedmutex)