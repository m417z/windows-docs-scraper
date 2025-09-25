# CoGetCurrentProcess function

## Description

Returns a value that is unique to the current thread. **CoGetCurrentProcess** can be used to avoid thread ID reuse problems.

## Return value

The function returns the unique identifier of the current thread.

## Remarks

Using the value returned from a call to **CoGetCurrentProcess** can help you in maintaining tables that are keyed by threads or in uniquely identifying a thread to other threads or processes.

**CoGetCurrentProcess** returns a value that is effectively unique, because it is not used again until 2³² more threads have been created on the current workstation or until the workstation is restarted.

The value returned by **CoGetCurrentProcess** will uniquely identify the same thread for the life of the caller. Because thread IDs can be reused without notice as threads are created and destroyed, this value is more reliable than the value returned by the [GetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid) function.