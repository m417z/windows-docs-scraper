# FSCTL_TXFS_QUERY_RM_INFORMATION IOCTL

## Description

> [!NOTE]
> Microsoft strongly recommends developers utilize alternative means to achieve your application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more information, and alternatives to TxF, please see [Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).

Retrieves information for a resource manager (RM).

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  FSCTL_TXFS_QUERY_RM_INFORMATION,  // dwIoControlCode
  NULL,                             // lpInBuffer
  0,                                // nInBufferSize
  (LPVOID) lpOutBuffer,             // output buffer
  (DWORD) nOutBufferSize,           // size of output buffer
  (LPDWORD) lpBytesReturned,        // bytes returned
  (LPOVERLAPPED) lpOverlapped       // OVERLAPPED structure
);
```

## Parameters

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

**FSCTL_TXFS_QUERY_RM_INFORMATION** is a synchronous operation.

If this call fails with **ERROR_BUFFER_TOO_SMALL**, the **BytesRequired** member of the [TXFS_QUERY_RM_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_query_rm_information) structure specifies how large the buffer must be for the call to return successfully.

If you are writing an application that supports remote Server Message Block Protocol clients, you must use this control code to use the resource manager.

The resource manager may be queried regardless of its state; if the RM is not started, **ERROR_RM_NOT_ACTIVE** is returned. You can use the information about the active range of the log to guide decisions about how much of the log to archive.

**ReFS:** This code is not supported.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Secondary Resource Managers for TxF Volumes](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-reference)
* [TXFS_QUERY_RM_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_query_rm_information)