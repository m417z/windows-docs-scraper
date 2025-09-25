# EngIsSemaphoreOwnedByCurrentThread function

## Description

The **EngIsSemaphoreOwnedByCurrentThread** function determines whether the currently executing thread holds the specified semaphore.

## Parameters

### `hsem` [in]

Handle to the semaphore.

## Return value

**EngIsSemaphoreOwnedByCurrentThread** returns **TRUE** if the currently executing thread holds the specified semaphore, and **FALSE** if it does not.

## See also

[EngAcquireSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engacquiresemaphore)

[EngCreateSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatesemaphore)

[EngIsSemaphoreOwned](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engissemaphoreowned)

[EngReleaseSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engreleasesemaphore)