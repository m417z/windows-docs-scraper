# SetUmsThreadInformation function

## Description

Sets application-specific context information for the specified user-mode scheduling (UMS) worker thread.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `UmsThread` [in]

A pointer to a UMS thread context.

### `UmsThreadInfoClass` [in]

A [UMS_THREAD_INFO_CLASS](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-queryumsthreadinformation) value that specifies the kind of information to set. This parameter must be **UmsThreadUserContext**.

### `UmsThreadInformation` [in]

A pointer to a buffer that contains the information to set.

### `UmsThreadInformationLength` [in]

The size of the *UmsThreadInformation* buffer, in bytes.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INFO_LENGTH_MISMATCH** | The buffer size does not match the required size for the specified information class. |
| **ERROR_INVALID_INFO_CLASS** | The *UmsThreadInfoClass* parameter specifies an information class that is not supported. |
| **ERROR_NOT_SUPPORTED** | UMS is not supported. |

## Remarks

The **SetUmsThreadInformation** function can be used to set an application-defined context for the specified UMS worker thread. The context information can consist of anything the application might find useful to track, such as per-scheduler or per-worker thread state. The underlying structures for UMS worker threads are managed by the system and should not be modified directly.

The [QueryUmsThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryumsthreadinformation) function can be used to retrieve other exposed information about the specified thread, such as its thread execution block ([TEB](https://learn.microsoft.com/windows/desktop/api/winternl/ns-winternl-teb)) and whether the thread is suspended or terminated. Information that is not exposed through **QueryUmsThreadInformation** should be considered reserved.

## See also

[QueryUmsThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryumsthreadinformation)