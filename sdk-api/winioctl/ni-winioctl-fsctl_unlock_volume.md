# FSCTL_UNLOCK_VOLUME IOCTL

## Description

Unlocks a volume.

To perform this operation, call the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.
```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,            // handle to a volume
  FSCTL_UNLOCK_VOLUME,         // dwIoControlCode
  NULL,                        // lpInBuffer
  0,                           // nInBufferSize
  NULL,                        // lpOutBuffer
  0,                           // nOutBufferSize
  (LPDWORD) lpBytesReturned,   // number of bytes returned
  (LPOVERLAPPED) lpOverlapped  // OVERLAPPED structure
);
```

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

To lock a volume, use the
[FSCTL_LOCK_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lock_volume) control code.

The *hDevice* handle passed to [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) must be a handle to a volume, opened for direct access. To retrieve this handle, call
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the *lpFileName* parameter set to a string of the following form:

\\.\*X*:

where *X* is a hard-drive partition letter, floppy disk drive, or CD-ROM drive. The application must also specify the **FILE_SHARE_READ** and **FILE_SHARE_WRITE** flags in the *dwShareMode* parameter of
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

IIn Windows 8 and Windows Server 2012, this code is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | See comment |

PNP notification is issued only on the node where the FSCTL was issued.

After acquiring a lock on a CSV volume, you must close the handle used to lock that volume before opening a handle to the volume. Unlocking the volume by using **FSCTL_UNLOCK_VOLUME** is not sufficient.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[FSCTL_LOCK_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lock_volume)

[Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)