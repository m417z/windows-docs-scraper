# SetHandleInformation function

## Description

Sets certain properties of an object handle.

## Parameters

### `hObject` [in]

A handle to an object whose information is to be set.

You can specify a handle to one of the following types of objects: access token, console input buffer, console screen buffer, event, file, file mapping, job, mailslot, mutex, pipe, printer, process, registry key, semaphore, serial communication device, socket, thread, or waitable timer.

### `dwMask` [in]

A mask that specifies the bit flags to be changed. Use the same constants shown in the description of *dwFlags*.

### `dwFlags` [in]

Set of bit flags that specifies properties of the object handle. This parameter can be 0 or one or more of the following values.

| Value | Meaning |
| --- | --- |
| **HANDLE_FLAG_INHERIT**<br><br>0x00000001 | If this flag is set, a child process created with the *bInheritHandles* parameter of [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) set to **TRUE** will inherit the object handle. |
| **HANDLE_FLAG_PROTECT_FROM_CLOSE**<br><br>0x00000002 | If this flag is set, calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function will not close the object handle. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To set or clear the associated bit flag in *dwFlags*, you must set a change mask bit flag in *dwMask*.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[GetHandleInformation](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-gethandleinformation)

[Handle and Object Functions](https://learn.microsoft.com/windows/desktop/SysInfo/handle-and-object-functions)