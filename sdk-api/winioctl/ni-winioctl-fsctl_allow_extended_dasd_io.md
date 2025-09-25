# FSCTL_ALLOW_EXTENDED_DASD_IO IOCTL

## Description

Signals the file system drive not to perform any I/O boundary checks on partition read or write calls. Instead, boundary checks are performed by the device driver.

To perform this operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                    // handle to file
  FSCTL_ALLOW_EXTENDED_DASD_IO,        // dwIoControlCode
  NULL,                                // lpInBuffer
  0,                                   // nInBufferSize
  NULL,                                // lpOutBuffer
  0,                                   // nOutBufferSize
  (LPDWORD) lpBytesReturned,           // number of bytes returned
  (LPOVERLAPPED) lpOverlapped          // OVERLAPPED structure
);

```

### Parameters

#### Input buffer

#### Input buffer length

#### Output buffer

#### Output buffer length

#### Input/output buffer

#### Input/output buffer length

#### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A call using the **FSCTL_ALLOW_EXTENDED_DASD_IO** control code should only be used with great caution by programmers familiar with the underlying structure of a hard disk drive and file system. Improper use or inaccurate checking in subsequent write operations to the partition can result in damage to data on the partition, or destruction of the entire partition.

The **FSCTL_ALLOW_EXTENDED_DASD_IO** control code is used to signal the file system driver not to perform any I/O boundary checks on read or write calls made with the specified handle. **FSCTL_ALLOW_EXTENDED_DASD_IO** allows access to hidden sectors, a part of the partition that might exist between the first sector of the partition (the boot parameter block) and the first useful sector of the partition. **FSCTL_ALLOW_EXTENDED_DASD_IO** also allows access to lost clusters, which might exist between the last useful cluster and the end of the partition.

I/O requests issued after this operation are passed directly to the device driver. If these subsequent calls request data beyond the partition boundary, the driver causes them to fail.

For the implications of overlapped I/O on this operation, see the Remarks section of [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol).

To retrieve a handle to a partition, call [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) with the *lpFileName* parameter set to a string of the following form:

\\.\*X*:

where *X* is the drive letter.

The application calling [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) must also specify the **FILE_SHARE_READ** and **FILE_SHARE_WRITE** flags in the *dwShareMode* parameter of [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea). For more information, see the Disk Devices section in [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

To determine the partition structure of the drive and to determine if the system recognizes the partition, use the [IOCTL_DISK_GET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout_ex) or [IOCTL_DISK_GET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout) control code, as appropriate. For similar information on a single partition, use the [IOCTL_DISK_GET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info_ex) or [IOCTL_DISK_GET_PARTITION_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info) control code, as appropriate. To determine the size of a cluster, use the [GetDiskFreeSpaceEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespaceexa) or [GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea) function, as appropriate.

In Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
|-------------------------------------------------|-----------|
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)

[GetDiskFreeSpace](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespacea)

[GetDiskFreeSpaceEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdiskfreespaceexa)

[IOCTL_DISK_GET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout)

[IOCTL_DISK_GET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout_ex)

[IOCTL_DISK_GET_PARTITION_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info)

[IOCTL_DISK_GET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info_ex)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)