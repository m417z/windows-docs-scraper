# CreateUmsThreadContext function

## Description

Creates a user-mode scheduling (UMS) thread context to represent a UMS worker thread.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `lpUmsThread` [out]

A PUMS_CONTEXT variable. On output, this parameter receives a pointer to a UMS thread context.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to create the UMS thread context. |

## Remarks

A UMS thread context represents the state of a UMS worker thread. Thread contexts are used to specify UMS worker threads in function calls.

A UMS worker thread is created by calling the [CreateRemoteThreadEx](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethreadex) function after using [InitializeProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-initializeprocthreadattributelist) and [UpdateProcThreadAttribute](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute) to prepare a list of UMS attributes for the thread.

The underlying structures for a UMS thread context are managed by the system and should not be modified directly. To get and set information about a UMS worker thread, use the [QueryUmsThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryumsthreadinformation) and [SetUmsThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setumsthreadinformation) functions.

After a UMS worker thread terminates, its thread context should be released by calling [DeleteUmsThreadContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deleteumsthreadcontext).

## See also

[CreateRemoteThreadEx](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethreadex)

[DeleteUmsThreadContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deleteumsthreadcontext)

[InitializeProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-initializeprocthreadattributelist)

[QueryUmsThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryumsthreadinformation)

[SetUmsThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setumsthreadinformation)

[UpdateProcThreadAttribute](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute)