# FSCTL_TXFS_TRANSACTION_ACTIVE IOCTL

## Description

> [!NOTE]
> Microsoft strongly recommends developers utilize alternative means to achieve your application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more information, and alternatives to TxF, please see [Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).

Returns a Boolean value that indicates if there were any transactions active on the associated volume when the snapshot was taken. This call is only valid for read-only snapshot volumes.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  FSCTL_TXFS_TRANSACTION_ACTIVE,    // dwIoControlCode
  NULL,                             // lpInBuffer
  0,                                // nInBufferSize
  (LPVOID) lpOutBuffer,             // output buffer
  (DWORD) nOutBufferSize,           // size of output buffer
  (LPDWORD) lpBytesReturned,        // number of bytes returned
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

**FSCTL_TXFS_TRANSACTION_ACTIVE** is a synchronous operation.

If the **TransactionsActiveAtSnapshot** member of the [TXFS_TRANSACTION_ACTIVE_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_transaction_active_info) structure is **TRUE**, you must remount the snapshot read/write, and run your recovery operations.

**ReFS:** This code is not supported.

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [TXFS_TRANSACTION_ACTIVE_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_transaction_active_info)