# IOCTL\_DISK\_SET\_CLUSTER\_INFO control code

Sets the cluster information on a disk.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```C++
BOOL
WINAPI
DeviceIoControl( (HANDLE)       hDevice,         // handle to device
                 IOCTL_DISK_SET_CLUSTER_INFO,    // dwIoControlCode
                 (LPVOID)       NULL,            // lpInBuffer
                 (DWORD)        0,               // nInBufferSize
                 (LPVOID)       lpOutBuffer,     // output buffer:GET_DISK_ATTRIBUTES
                 (DWORD)        nOutBufferSize,  // size of output buffer
                 (LPDWORD)      lpBytesReturned, // number of bytes returned
                 (LPOVERLAPPED) lpOverlapped );  // OVERLAPPED structure
```

## Parameters

*hDevice*

A handle to the disk.

To retrieve a device handle, call the [**CreateFile**](https://learn.microsoft.com/windows/desktop/api/FileAPI/nf-fileapi-createfilea) function.

*dwIoControlCode*

The control code for the operation.

Use **IOCTL\_DISK\_SET\_CLUSTER\_INFO** for this operation.

*lpInBuffer*

A pointer to a [**DISK\_CLUSTER\_INFO**](https://learn.microsoft.com/windows/win32/fileio/disk-cluster-info) data structure that contains cluster information for the disk.

*nInBufferSize*

The size of the input buffer, in bytes.

*lpOutBuffer*

Not used with this operation. Set to **NULL**.

*nOutBufferSize*

The size of the output buffer, in bytes. Set to 0 (zero).

*lpBytesReturned*

Not used with this operation. Set to **NULL**.

*lpOverlapped*

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

If *hDevice* was opened without specifying **FILE\_FLAG\_OVERLAPPED**, *lpOverlapped* is ignored.

If *hDevice* was opened with the **FILE\_FLAG\_OVERLAPPED** flag, the operation is performed as an overlapped (asynchronous) operation. In this case, *lpOverlapped* must point to a valid [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. Otherwise, the function fails in unpredictable ways.

For overlapped operations, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns immediately, and the event object is signaled when the operation has been completed. Otherwise, the function does not return until the operation has been completed or an error occurs.

## Return value

If the operation completes successfully, indicating that all volumes on the disk are ready for use, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Ntdddisk.h |

## See also

[**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[Disk Management Control Codes](https://learn.microsoft.com/windows/win32/fileio/disk-management-control-codes)

[**DISK\_CLUSTER\_INFO**](https://learn.microsoft.com/windows/win32/fileio/disk-cluster-info)

[**IOCTL\_DISK\_GET\_CLUSTER\_INFO**](https://learn.microsoft.com/windows/win32/fileio/ioctl-disk-get-cluster-info)

