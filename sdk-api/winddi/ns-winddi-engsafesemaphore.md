# ENGSAFESEMAPHORE structure

## Description

The ENGSAFESEMAPHORE structure provides the driver with a thread-safe semaphore.

## Members

### `hsem`

Handle to the semaphore.

### `lCount`

Specifies the reference count on the semaphore.

## Remarks

A safe semaphore is a wrapper that contains a handle to a semaphore and a reference count on that semaphore.

The driver allocates an ENGSAFESEMAPHORE structure and passes it to [EngInitializeSafeSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enginitializesafesemaphore) for initialization. GDI operates the safe semaphore under a lock and maintains a reference count on it, making it suitable for multithreading.

Once the safe semaphore is initialized, the driver can call [EngAcquireSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engacquiresemaphore) and [EngReleaseSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engreleasesemaphore) with the **hsem** for synchronization.

## See also

[EngAcquireSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engacquiresemaphore)

[EngDeleteSafeSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletesafesemaphore)

[EngInitializeSafeSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enginitializesafesemaphore)

[EngReleaseSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engreleasesemaphore)