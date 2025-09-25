# FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES IOCTL

## Description

> [!NOTE]
> Microsoft strongly recommends developers utilize alternative means to achieve your application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more information, and alternatives to TxF, please see [Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).

Returns a list of all files currently locked by the specified transaction. If the return value is **ERROR_MORE_DATA**, it returns the length of the buffer required to hold the complete list of files at the time of this call.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                         // handle to device
  FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES, // dwIoControlCode
  (LPVOID) lpInBuffer,                      // input buffer
  (DWORD) nInBufferSize,                    // size of input buffer
  (LPVOID) lpOutBuffer,                     // output buffer
  (DWORD) nOutBufferSize,                   // size of output buffer
  (LPDWORD) lpBytesReturned,                // number of bytes returned
  (LPOVERLAPPED) lpOverlapped );            // OVERLAPPED structure
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

**FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES** is a synchronous operation.

The file path names returned are relative to the volume root.

The number of files returned from one call to the next can change depending on the number of active transactions at any given point in time. If this call returns a request for a larger buffer, that size may or may not be adequate for the next call, based on the number of active transactions at the time of the next call.

**ReFS:** This code is not supported.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [TXFS_LIST_TRANSACTION_LOCKED_FILES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_list_transaction_locked_files)
* [TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_list_transaction_locked_files_entry)