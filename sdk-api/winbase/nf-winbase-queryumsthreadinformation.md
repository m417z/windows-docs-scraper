# QueryUmsThreadInformation function

## Description

Retrieves information about the specified user-mode scheduling (UMS) worker thread.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `UmsThread` [in]

A pointer to a UMS thread context.

### `UmsThreadInfoClass` [in]

A UMS_THREAD_INFO_CLASS value that specifies the kind of information to retrieve.

### `UmsThreadInformation` [out]

A pointer to a buffer to receive the specified information. The required size of this buffer depends on the specified information class.

If the information class is **UmsThreadContext** or **UmsThreadTeb**, the buffer must be `sizeof(PVOID)`.

If the information class is **UmsThreadIsSuspended** or **UmsThreadIsTerminated**, the buffer must be `sizeof(BOOLEAN)`.

### `UmsThreadInformationLength` [in]

The size of the *UmsThreadInformation* buffer, in bytes.

### `ReturnLength` [out, optional]

A pointer to a ULONG variable. On output, this parameter receives the number of bytes written to the *UmsThreadInformation* buffer.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INFO_LENGTH_MISMATCH** | The buffer is too small for the requested information. |
| **ERROR_INVALID_INFO_CLASS** | The specified information class is not supported. |
| **ERROR_NOT_SUPPORTED** | UMS is not supported. |

## Remarks

The **QueryUmsThreadInformation** function retrieves information about the specified UMS worker thread such as its application-defined context, its thread execution block ([TEB](https://learn.microsoft.com/windows/desktop/api/winternl/ns-winternl-teb)), and whether the thread is suspended or terminated.

The underlying structures for UMS worker threads are managed by the system. Information that is not exposed through **QueryUmsThreadInformation** should be considered reserved.

## See also

[SetUmsThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setumsthreadinformation)

UMS_THREAD_INFO_CLASS