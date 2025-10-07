# IOCTL\_VOLUME\_IS\_CSV control code

Determines whether a volume is a CSV volume.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```C++
BOOL
WINAPI
DeviceIoControl( (HANDLE) hDevice,              // handle to device
                 IOCTL_VOLUME_IS_CSV,           // dwIoControlCode
                 NULL,                          // input buffer
                 0,                             // size of input buffer
                 (LPVOID) lpOutBuffer,          // lpOutBuffer
                 (DWORD) nOutBufferSize,        // nOutBufferSize
                 (LPDWORD) lpBytesReturned,     // number of bytes returned
                 (LPOVERLAPPED) lpOverlapped ); // OVERLAPPED structure
```

## Parameters

*hDevice*

A handle to the volume. To retrieve a volume handle, call the [**CreateFile**](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-createfilea) function. Only administrators can open volume handles.

*dwIoControlCode*

The control code for the operation. Use **IOCTL\_VOLUME\_IS\_CSV** for this operation.

*lpInBuffer*

Not used with this operation; set to **NULL**.

*nInBufferSize*

Not used with this operation; set to zero (0).

*lpOutBuffer*

A pointer to **TRUE** if the volume is a CSV volume; otherwise, the function call fails.

*nOutBufferSize*

The size of the output buffer, in bytes.

*lpBytesReturned*

A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

If *lpOverlapped* is **NULL**, *lpBytesReturned* cannot be **NULL**. Even when an operation returns no output data and *lpOutBuffer* is **NULL**, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) makes use of *lpBytesReturned*. After such an operation, the value of *lpBytesReturned* is meaningless.

If *lpOverlapped* is not **NULL**, *lpBytesReturned* can be **NULL**. If this parameter is not **NULL** and the operation returns data, *lpBytesReturned* is meaningless until the overlapped operation has completed. To retrieve the number of bytes returned, call [**GetOverlappedResult**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult). If *hDevice* is associated with an I/O completion port, you can retrieve the number of bytes returned by calling [**GetQueuedCompletionStatus**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus).

*lpOverlapped*

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

If *hDevice* was opened without specifying **FILE\_FLAG\_OVERLAPPED**, *lpOverlapped* is ignored.

If *hDevice* was opened with the **FILE\_FLAG\_OVERLAPPED** flag, the operation is performed as an overlapped (asynchronous) operation. In this case, *lpOverlapped* must point to a valid [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. Otherwise, the function fails in unpredictable ways.

For overlapped operations, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns immediately, and the event object is signaled when the operation has been completed. Otherwise, the function does not return until the operation has been completed or an error occurs.

## Return value

If the operation completes successfully, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero (0). To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Ntddvol.h |

## See also

[**CreateFile**](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-createfilea)

[**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[Volume Management Control Codes](https://learn.microsoft.com/windows/win32/fileio/volume-management-control-codes)

