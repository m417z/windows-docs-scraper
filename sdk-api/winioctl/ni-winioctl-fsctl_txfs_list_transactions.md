# FSCTL_TXFS_LIST_TRANSACTIONS IOCTL

## Description

> [!NOTE]
> Microsoft strongly recommends developers utilize alternative means to achieve your application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more information, and alternatives to TxF, please see [Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).

Returns a list of all the transactions currently involved in the specified resource manager. If the function fails with **ERROR_MORE_DATA**, it returns the length of the buffer required to hold the complete list of transactions at the time of this call.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  FSCTL_TXFS_LIST_TRANSACTIONS,     // dwIoControlCode
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

**FSCTL_TXFS_LIST_TRANSACTIONS** is a synchronous operation.

The number of transactions returned from one call to the next can change depending on the number of active transactions at any given point in time. If this call returns a request for a larger buffer, that size may or may not be adequate for the next call, based on the number of active transactions at the time of the next call.

**ReFS:** This code is not supported.

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [TXFS_LIST_TRANSACTIONS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_list_transactions)
* [TXFS_LIST_TRANSACTIONS_ENTRY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_list_transactions_entry)