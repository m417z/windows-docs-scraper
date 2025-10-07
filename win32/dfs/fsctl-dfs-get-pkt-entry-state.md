# FSCTL_DFS_GET_PKT_ENTRY_STATE control code

The **FSCTL_DFS_GET_PKT_ENTRY_STATE** control code can get the same information as the [**NetDfsGetClientInfo**](https://learn.microsoft.com/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo) function but can provide better performance in some configurations with high latencies to the DFS servers. It is not recommended to use the **FSCTL_DFS_GET_PKT_ENTRY_STATE** control code unless there are performance issues.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```C++
BOOL
   WINAPI
   DeviceIoControl( (HANDLE)       hDevice,            // handle to device
                    (DWORD)        FSCTL_DFS_GET_PKT_ENTRY_STATE, // dwIoControlCode(LPDWORD)      lpInBuffer,         // input buffer
                    (DWORD)        nInBufferSize,      // size of input buffer
                    (LPDWORD)      lpOutBuffer,        // output buffer
                    (DWORD)        nOutBufferSize,     // size of output buffer
                    (LPDWORD)      lpBytesReturned,    // number of bytes returned
                    (LPOVERLAPPED) lpOverlapped );     // OVERLAPPED structure
```

## Parameters

*hDevice* [in]

A handle to the device. To obtain a device handle, call the [**CreateFile**](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

*dwIoControlCode* [in]

The control code for the operation. Use **FSCTL_DFS_GET_PKT_ENTRY_STATE** for this operation.

*lpInBuffer*

Address of a [**DFS_GET_PKT_ENTRY_STATE_ARG**](https://learn.microsoft.com/windows/win32/api/lmdfs/ns-lmdfs-dfs_get_pkt_entry_state_arg) structure and the 1-3 Unicode strings that follow.

*nInBufferSize* [in]

Size, in bytes, of the buffer pointed to by the *lpInBuffer* parameter.

*lpOutBuffer* [out]

Address of a **DFS_INFO_\#** structure and any strings and structures pointed to by the **DFS_INFO_\#** structure. The specific structure returned depends on the **Level** member in the [**DFS_GET_PKT_ENTRY_STATE_ARG**](https://learn.microsoft.com/windows/win32/api/lmdfs/ns-lmdfs-dfs_get_pkt_entry_state_arg) structure passed in the input buffer.

*nOutBufferSize* [in]

Size, in bytes, of the buffer pointed to by the *lpOutBuffer* parameter. Due to the strings and structures referenced by the returned **DFS_INFO_\#** structure that are also in the output buffer, this buffer should be larger than the **DFS_INFO_\#** structure specified.

*lpBytesReturned* [out]

A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

If the output buffer is too small, but at least large enough to hold a **DWORD**, the call fails, [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_MORE_DATA**, and the first **DWORD** of the output buffer contains the size that would have been required. If the output buffer cannot hold a **DWORD** then the call fails with **ERROR_INSUFFICIENT_BUFFER**, and *lpBytesReturned* is zero.

If *lpOverlapped* is **NULL**, *lpBytesReturned* cannot be **NULL**. Even when an operation returns no output data and *lpOutBuffer* is **NULL**, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) makes use of *lpBytesReturned*. After such an operation, the value of *lpBytesReturned* is meaningless.

If *lpOverlapped* is not **NULL**, *lpBytesReturned* can be **NULL**. If this parameter is not **NULL** and the operation returns data, *lpBytesReturned* is meaningless until the overlapped operation has completed. To retrieve the number of bytes returned, call [**GetOverlappedResult**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult). If the *hDevice* parameter is associated with an I/O completion port, you can retrieve the number of bytes returned by calling [**GetQueuedCompletionStatus**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus).

*lpOverlapped* [in]

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

If *hDevice* was opened without specifying **FILE_FLAG_OVERLAPPED**, *lpOverlapped* is ignored.

If *hDevice* was opened with the **FILE_FLAG_OVERLAPPED** flag, the operation is performed as an overlapped (asynchronous) operation. In this case, *lpOverlapped* must point to a valid [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. Otherwise, the function fails in unpredictable ways.

For overlapped operations, [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns immediately, and the event object is signaled when the operation has been completed. Otherwise, the function does not return until the operation has been completed or an error occurs.

## Return value

If the operation completes successfully, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Header<br> | LmDfs.h (include LmDfs.h) |

## See also

[**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[**NetDfsGetClientInfo**](https://learn.microsoft.com/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetclientinfo)