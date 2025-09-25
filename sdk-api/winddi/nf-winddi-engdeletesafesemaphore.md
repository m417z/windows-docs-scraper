# EngDeleteSafeSemaphore function

## Description

The **EngDeleteSafeSemaphore** function removes a reference to the specified safe semaphore.

## Parameters

### `pssem` [in, out]

Pointer to the [ENGSAFESEMAPHORE](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-engsafesemaphore) structure that contains the safe semaphore from which to delete a reference.

## Return value

None

## Remarks

**EngDeleteSafeSemaphore** deletes the semaphore only when the last reference to it has been removed.

[EngInitializeSafeSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enginitializesafesemaphore) and **EngDeleteSafeSemaphore** are thread-safe, operating under a lock and maintaining a reference count on the semaphore. This guarantees that only one semaphore is created regardless of the number of simultaneous calls to it, and that the semaphore exists until the last reference to it is released.

Every caller of **EngInitializeSafeSemaphore** should call **EngDeleteSafeSemaphore** when it no longer needs the semaphore.

## See also

[ENGSAFESEMAPHORE](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-engsafesemaphore)

[EngInitializeSafeSemaphore](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enginitializesafesemaphore)