# EngReleaseSemaphore function

## Description

The **EngReleaseSemaphore** function releases the specified semaphore.

## Parameters

### `hsem` [in]

Handle to the semaphore to be released.

## Return value

None

## Remarks

**EngReleaseSemaphore** releases the semaphore's exclusive lock on a driver's resource and reenables the delivery of special kernel asynchronous procedure calls.

The lock and asynchronous procedure call suspension were acquired in a call to [EngAcquireSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engacquiresemaphore).

## See also

[EngAcquireSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engacquiresemaphore)

[EngDeleteSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletesemaphore)

[EngIsSemaphoreOwned](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engissemaphoreowned)

[EngIsSemaphoreOwnedByCurrentThread](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engissemaphoreownedbycurrentthread)