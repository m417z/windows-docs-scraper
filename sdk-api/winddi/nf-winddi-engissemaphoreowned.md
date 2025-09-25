# EngIsSemaphoreOwned function

## Description

The **EngIsSemaphoreOwned** function determines whether any thread holds the specified semaphore.

## Parameters

### `hsem` [in]

Handle to the semaphore.

## Return value

**EngIsSemaphoreOwned** returns **TRUE** if any thread holds the specified semaphore, and **FALSE** if no thread holds it.

## See also

[EngAcquireSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engacquiresemaphore)

[EngCreateSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatesemaphore)

[EngIsSemaphoreOwnedByCurrentThread](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engissemaphoreownedbycurrentthread)

[EngReleaseSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engreleasesemaphore)