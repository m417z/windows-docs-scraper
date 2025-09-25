# EngAcquireSemaphore function

## Description

The **EngAcquireSemaphore** function acquires the resource associated with the semaphore for exclusive access by the calling thread.

## Parameters

### `hsem` [in]

Handle to the semaphore associated with the resource to be acquired.

## Return value

None

## Remarks

**EngAcquireSemaphore** allows exclusive access to the driver resource associated with the semaphore by locking out all other threads from accessing the semaphore's resource.

A call to this routine should be followed with a call to [EngReleaseSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engreleasesemaphore) as quickly as possible.

## See also

[EngCreateSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatesemaphore)

[EngDeleteSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletesemaphore)

[EngIsSemaphoreOwned](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engissemaphoreowned)

[EngIsSemaphoreOwnedByCurrentThread](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engissemaphoreownedbycurrentthread)

[EngReleaseSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engreleasesemaphore)