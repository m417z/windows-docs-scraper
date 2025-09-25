# FSCTL_TXFS_MODIFY_RM IOCTL

## Description

> [!NOTE]
> Microsoft strongly recommends developers utilize alternative means to achieve your application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more information, and alternatives to TxF, please see [Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).

Sets the log mode and log parameter information for a secondary resource manager (RM).

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  FSCTL_TXFS_MODIFY_RM,         // dwIoControlCode
  (LPVOID) lpInBuffer,          // input buffer
  (DWORD) nInBufferSize,        // size of input buffer
  NULL,                         // lpOutBuffer
  0,                            // nOutBufferSize
  (LPDWORD) lpBytesReturned,    // bytes returned
  (LPOVERLAPPED) lpOverlapped   // OVERLAPPED structure
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

**FSCTL_TXFS_MODIFY_RM** is a synchronous operation.

This control code is for remote clients to use when setting log parameters, and for local clients to specify log parameters for the default RMs.

**Note** You cannot set the logging mode for a default RM. The logging mode for a default RM is
**TXFS_LOGGING_MODE_SIMPLE**.

**ReFS:** This code is not supported.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Secondary Resource Managers for TxF Volumes](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-reference)
* [TXFS_MODIFY_RM](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_modify_rm)