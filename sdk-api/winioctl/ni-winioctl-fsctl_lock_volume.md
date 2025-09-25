# FSCTL_LOCK_VOLUME IOCTL

## Description

Locks a volume if it is not in use. A locked volume can be accessed only through handles to the file object (**hDevice*) that locks the volume. For more information, see the Remarks section.

To perform this operation, call the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.
```cpp
BOOL DeviceIoControl(
  (HANDLE) hVolume,            // handle to a volume
  (DWORD) FSCTL_LOCK_VOLUME,   // dwIoControlCode
  NULL,                        // lpInBuffer
  0,                           // nInBufferSize
  NULL,                        // lpOutBuffer
  0,                           // nOutBufferSize
  (LPDWORD) lpBytesReturned,   // number of bytes returned
  NULL                         // OVERLAPPED structure
);
```

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The *hDevice* handle passed to [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) must be a handle to a volume, opened for direct access. To retrieve this handle, call
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the *lpFileName* parameter set to a string of the following form:

\\.\\X:

where *X* is a hard-drive partition letter, floppy disk drive, or CD-ROM drive. The application must also specify the **FILE_SHARE_READ** and **FILE_SHARE_WRITE** flags in the *dwShareMode* parameter of [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

If the specified volume is a system volume or contains a page file, the operation fails.

If there are any open files on the volume, this operation will fail. Conversely, success of this operation indicates there are no open files.

This operation is useful for applications that need exclusive access to a volume for a period of time—for example, disk utility and backup programs.

A locked volume remains locked until one of the following occurs:

* The application uses the
  [FSCTL_UNLOCK_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_unlock_volume) control code to unlock the volume.
* The handle closes, either directly through
  [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle), or indirectly when a process terminates.

The system flushes all cached data to the volume before locking it. For example, any data held in a lazy-write cache is written to the volume.

The NTFS file system treats a locked volume as a dismounted volume. The [FSCTL_DISMOUNT_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_dismount_volume) control code functions similarly but does not check for open files before dismounting. Note that without a successful lock operation, a dismounted volume may be remounted by any process at any time. This would not be an ideal state for performing a volume backup, for example.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | See comment |

On CsvFs Lock Volume, PNP notification will be sent only on the node where the lock request was issued. A lock will succeed only if the CsvFs filter on top of NTFS does not see any opened files.

After acquiring a lock on a CSV volume, you must close the handle used to lock that volume before opening a handle to the volume. Unlocking the volume by using [FSCTL_UNLOCK_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_unlock_volume) is not sufficient.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[FSCTL_DISMOUNT_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_dismount_volume)

[FSCTL_UNLOCK_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_unlock_volume)

[Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)