# GetHandleInformation function

## Description

Retrieves certain properties of an object handle.

## Parameters

### `hObject` [in]

A handle to an object whose information is to be retrieved.

You can specify a handle to one of the following types of objects: access token, console input buffer, console screen buffer, event, file, file mapping, job, mailslot, mutex, pipe, printer, process, registry key, semaphore, serial communication device, socket, thread, or waitable timer.

### `lpdwFlags` [out]

A pointer to a variable that receives a set of bit flags that specify properties of the object handle or 0. The following values are defined.

| Value | Meaning |
| --- | --- |
| **HANDLE_FLAG_INHERIT**<br><br>0x00000001 | If this flag is set, a child process created with the *bInheritHandles* parameter of [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) set to **TRUE** will inherit the object handle. |
| **HANDLE_FLAG_PROTECT_FROM_CLOSE**<br><br>0x00000002 | If this flag is set, calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function will not close the object handle. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[Handle and
Object Functions](https://learn.microsoft.com/windows/desktop/SysInfo/handle-and-object-functions)

[SetHandleInformation](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-sethandleinformation)