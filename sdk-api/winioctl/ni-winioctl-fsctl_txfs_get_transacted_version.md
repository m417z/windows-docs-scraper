# FSCTL_TXFS_GET_TRANSACTED_VERSION IOCTL

## Description

> [!NOTE]
> Microsoft strongly recommends developers utilize alternative means to achieve your application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more information, and alternatives to TxF, please see [Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).

Returns a [TXFS_GET_TRANSACTED_VERSION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_get_transacted_version) structure. The structure identifies the most recently committed version of the specified file, the version number of the handle.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                     // handle to device
  FSCTL_TXFS_GET_TRANSACTED_VERSION,    // dwIoControlCode
  NULL,                                 // lpInBuffer
  0,                                    // nInBufferSize
  (LPVOID) lpOutBuffer,                 // output buffer
  (DWORD) nOutBufferSize,               // size of output buffer
  (LPDWORD) lpBytesReturned,            // number of bytes returned
  NULL                                  // OVERLAPPED structure
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

**FSCTL_TXFS_GET_TRANSACTED_VERSION** is a synchronous operation.

This control code can be use to track the latest version of a base file. For a specified handle, the base version is always the base value returned when the handle was opened, but the latest version changes based on any commit operations another transaction makes. If handle is then closed and opened again, base version and latest version are updated to new values and any subsequent commit operations from the other transaction change the latest version.

If you attempt to retrieve the version of a resource manager's root, the value **TXFS_TRANSACTED_VERSION_NONTRANSACTED** is returned.

**ReFS:** This code is not supported.

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [TXFS_GET_TRANSACTED_VERSION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_get_transacted_version)