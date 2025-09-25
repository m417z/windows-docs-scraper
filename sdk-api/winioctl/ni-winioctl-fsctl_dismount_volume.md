# FSCTL_DISMOUNT_VOLUME IOCTL

## Description

Dismounts a volume regardless of whether or not the volume is currently in use. For more information, see the Remarks section.

To perform this operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)
function with the following parameters.

| C++ |
| --- |
| ``` BOOL DeviceIoControl(   (HANDLE) hDevice,            // handle to a volume   (DWORD) FSCTL_DISMOUNT_VOLUME,   // dwIoControlCodeNULL,                        // lpInBuffer0,                           // nInBufferSizeNULL,                        // lpOutBuffer0,                           // nOutBufferSize(LPDWORD) lpBytesReturned,   // number of bytes returned   (LPOVERLAPPED) lpOverlapped  // OVERLAPPED structure ); ``` |

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

The **FSCTL_DISMOUNT_VOLUME** control code will attempt to dismount a volume regardless of whether or not any other processes are using the volume, which can have unpredictable results for those processes if they do not hold a lock on the volume. For information about locking a volume, see [FSCTL_LOCK_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lock_volume).

The *hDevice* handle passed to
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) must be a handle to a volume, opened
for direct access. To retrieve a volume handle, call
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the
*lpFileName* parameter set to a string of the following form:

\\.\*X*:

where *X* is a hard-drive partition letter, floppy disk drive, or CD-ROM drive. The
application must also specify the **FILE_SHARE_READ** and
**FILE_SHARE_WRITE** flags in the *dwShareMode* parameter of
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

If the specified volume is a system volume or contains a page file, the operation fails.

If the specified volume is locked by another process, the operation fails. To prevent another process from
locking the volume, lock it as soon as you open it.

A dismounted volume has the following properties:

* There are no open files.
* The operating system does detect the volume.

The operating system tries to mount an unmounted volume as soon as an attempt is made to access it. For
example, a call to [GetLogicalDrives](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlogicaldrives) triggers the
operating system to mount unmounted volumes.

Dismounting a volume is useful when a volume needs to disappear for a while. For example, an application that
changes a volume file system from the FAT file system to the NTFS file system might use the following
procedure.

**To change a volume file system**

1. Open a volume.
2. Lock the volume.
3. Format the volume.
4. Dismount the volume.
5. Unlock the volume.
6. Close the volume handle.

A dismounting operation removes the volume from the FAT file system awareness. When the operating system
mounts the volume, it appears as an NTFS file system volume.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | See comment |

On CsvFs the node where dismount is issued will see a normal dismount sequence. On all other nodes FS will invalidate all the opened files.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[FSCTL_LOCK_VOLUME](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lock_volume)

[GetLogicalDrives](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlogicaldrives)

[Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)