# FSCTL_TXFS_READ_BACKUP_INFORMATION IOCTL

## Description

> [!NOTE]
> Microsoft strongly recommends developers utilize alternative means to achieve your application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more information, and alternatives to TxF, please see [Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).

Returns Transactional NTFS (TxF) specific information for the specified file.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                     // handle to device
  FSCTL_TXFS_READ_BACKUP_INFORMATION,   // dwIoControlCode
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

**FSCTL_TXFS_READ_BACKUP_INFORMATION** is a synchronous operation.

This control code can be used by backup functions and applications, such as Win32 [BackupRead](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-backupread), and by Volume Shadow Copy Service (VSS) writers that support secondary resource managers. For more information, see [Volume Shadow Copy Service](https://learn.microsoft.com/windows-server/storage/file-server/volume-shadow-copy-service).

**ReFS:** This code is not supported.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [TXFS_READ_BACKUP_INFORMATION_OUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-txfs_read_backup_information_out)
* [Volume Shadow Copy Service](https://learn.microsoft.com/windows-server/storage/file-server/volume-shadow-copy-service)