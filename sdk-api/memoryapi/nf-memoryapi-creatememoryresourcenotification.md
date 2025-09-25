# CreateMemoryResourceNotification function

## Description

Creates a memory resource notification object.

## Parameters

### `NotificationType` [in]

The memory condition under which the object is to be signaled. This parameter can be one of the following
values from the **MEMORY_RESOURCE_NOTIFICATION_TYPE** enumeration.

| Value | Meaning |
| --- | --- |
| **LowMemoryResourceNotification**<br><br>0 | Available physical memory is running low. |
| **HighMemoryResourceNotification**<br><br>1 | Available physical memory is high. |

## Return value

If the function succeeds, the return value is a handle to a memory resource notification object.

If the function fails, the return value is **NULL**. To get extended information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications can use memory resource notification events to scale the memory usage as appropriate. If
available memory is low, the application can reduce its working set. If available memory is high, the application
can allocate more memory.

Any thread of the calling process can specify the memory resource notification handle in a call to the
[QueryMemoryResourceNotification](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-querymemoryresourcenotification)
function or one of the [wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). The state of the
object is signaled when the specified memory condition exists. This is a system-wide event, so all applications
receive notification when the object is signaled. Note that there is a range of memory availability where neither
the **LowMemoryResourceNotification** or
**HighMemoryResourceNotification** object is signaled. In this case, applications should
attempt to keep the memory use constant.

Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle. The
system closes the handle automatically when the process terminates. The memory resource notification object is
destroyed when its last handle has been closed.

To compile an application that uses this function, define the **_WIN32_WINNT** macro
as 0x0501 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[QueryMemoryResourceNotification](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-querymemoryresourcenotification)