# QueryMemoryResourceNotification function

## Description

Retrieves the state of the specified memory resource object.

## Parameters

### `ResourceNotificationHandle` [in]

A handle to a memory resource notification object. The
[CreateMemoryResourceNotification](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-creatememoryresourcenotification) function returns this handle.

### `ResourceState` [out]

The memory pointed to by this parameter receives the state of the memory resource notification object. The value of this parameter is set to **TRUE** if the specified memory condition exists, and **FALSE** if the specified memory condition does not exist.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. For more error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Unlike the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions),
**QueryMemoryResourceNotification** does not block the calling thread. Therefore, it is an efficient way to check the state of physical memory before proceeding with an operation.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0501 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CreateMemoryResourceNotification](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-creatememoryresourcenotification)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)