# ReleaseMutex function

## Description

Releases ownership of the specified mutex object.

## Parameters

### `hMutex` [in]

A handle to the mutex object. The
[CreateMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexa) or

[OpenMutex](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openmutexw) function returns this handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**ReleaseMutex** function fails if the calling thread does not own the mutex object.

A thread obtains ownership of a mutex either by creating it with the *bInitialOwner* parameter set to **TRUE** or by specifying its handle in a call to one of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). When the thread no longer needs to own the mutex object, it calls the
**ReleaseMutex** function so that another thread can acquire ownership.

A thread can specify a mutex that it already owns in a call to one of the wait functions without blocking its execution. This prevents a thread from deadlocking itself while waiting for a mutex that it already owns. However, to release its ownership, the thread must call
**ReleaseMutex** one time for each time that it obtained ownership (either through [CreateMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexa) or a wait function).

#### Examples

For an example that uses
**ReleaseMutex**, see
[Using Mutex Objects](https://learn.microsoft.com/windows/desktop/Sync/using-mutex-objects).

## See also

[CreateMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexa)

[Mutex Objects](https://learn.microsoft.com/windows/desktop/Sync/mutex-objects)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)