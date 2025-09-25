# EngInitializeSafeSemaphore function

## Description

The **EngInitializeSafeSemaphore** function initializes the specified safe semaphore.

## Parameters

### `pssem` [out]

Pointer to the driver-allocated [ENGSAFESEMAPHORE](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-engsafesemaphore) structure to be initialized.

## Return value

**EngInitializeSafeSemaphore** returns **TRUE** upon success. Otherwise, it returns **FALSE**.

## Remarks

**EngInitializeSafeSemaphore** and [EngDeleteSafeSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletesafesemaphore) are thread-safe, operating under a lock and maintaining a reference count on the semaphore. This guarantees that only one semaphore is created regardless of the number of simultaneous calls to it, and that the semaphore exists until the last reference to it is released.

Once the safe semaphore is initialized, the driver can call [EngAcquireSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engacquiresemaphore) and [EngReleaseSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engreleasesemaphore) with the **hsem** member of the [ENGSAFESEMAPHORE](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-engsafesemaphore) structure for synchronization.

Callers of **EngInitializeSafeSemaphore** should call **EngDeleteSafeSemaphore** when they no longer need the semaphore.

## See also

[ENGSAFESEMAPHORE](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-engsafesemaphore)

[EngAcquireSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engacquiresemaphore)

[EngDeleteSafeSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletesafesemaphore)

[EngIsSemaphoreOwned](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engissemaphoreowned)

[EngIsSemaphoreOwnedByCurrentThread](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engissemaphoreownedbycurrentthread)

[EngReleaseSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engreleasesemaphore)