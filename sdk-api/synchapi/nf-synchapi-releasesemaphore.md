# ReleaseSemaphore function

## Description

Increases the count of the specified semaphore object by a specified amount.

## Parameters

### `hSemaphore` [in]

A handle to the semaphore object. The
[CreateSemaphore](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createsemaphorea) or
[OpenSemaphore](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-opensemaphorew) function returns this handle.

This handle must have the **SEMAPHORE_MODIFY_STATE** access right. For more information, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

### `lReleaseCount` [in]

The amount by which the semaphore object's current count is to be increased. The value must be greater than zero. If the specified amount would cause the semaphore's count to exceed the maximum count that was specified when the semaphore was created, the count is not changed and the function returns **FALSE**.

### `lpPreviousCount` [out, optional]

A pointer to a variable to receive the previous count for the semaphore. This parameter can be **NULL** if the previous count is not required.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The state of a semaphore object is signaled when its count is greater than zero and nonsignaled when its count is equal to zero. The process that calls the
[CreateSemaphore](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createsemaphorea) function specifies the semaphore's initial count. Each time a waiting thread is released because of the semaphore's signaled state, the count of the semaphore is decreased by one.

Typically, an application uses a semaphore to limit the number of threads using a resource. Before a thread uses the resource, it specifies the semaphore handle in a call to one of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). When the wait function returns, it decreases the semaphore's count by one. When the thread has finished using the resource, it calls
**ReleaseSemaphore** to increase the semaphore's count by one.

Another use of
**ReleaseSemaphore** is during an application's initialization. The application can create a semaphore with an initial count of zero. This sets the semaphore's state to nonsignaled and blocks all threads from accessing the protected resource. When the application finishes its initialization, it uses
**ReleaseSemaphore** to increase the count to its maximum value, to permit normal access to the protected resource.

It is not possible to reduce the semaphore object count using
**ReleaseSemaphore**, because *lReleaseCount* cannot be a negative number. To temporarily restrict or reduce access, create a loop in which you call the
[WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject) function with a time-out interval of zero until the semaphore count has been reduced sufficiently. (Note that other threads can reduce the count while this loop is being executed.) To restore access, call
**ReleaseSemaphore** with the release count equal to the number of times
**WaitForSingleObject** was called in the loop.

#### Examples

For an example that uses
**ReleaseSemaphore**, see
[Using Semaphore Objects](https://learn.microsoft.com/windows/desktop/Sync/using-semaphore-objects).

## See also

[CreateSemaphore](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createsemaphorea)

[OpenSemaphore](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-opensemaphorew)

[Semaphore Objects](https://learn.microsoft.com/windows/desktop/Sync/semaphore-objects)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)