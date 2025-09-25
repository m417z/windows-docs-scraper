# IOCTL_DISK_SET_DRIVE_LAYOUT IOCTL

## Description

Partitions a disk as specified by drive layout and partition information data.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the parameters specified below.

> [!NOTE]
> **IOCTL_DISK_SET_DRIVE_LAYOUT** has been superseded by [**IOCTL_DISK_SET_DRIVE_LAYOUT_EX**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout_ex), which retrieves layout information for AT and EFI (Extensible Firmware Interface) partitions.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters. You must have write access to the drive in order to use this control code.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_DISK_SET_DRIVE_LAYOUT,  // dwIoControlCode
  (LPVOID) lpInBuffer,          // input buffer
  (DWORD) nInBufferSize,        // size of input buffer
  NULL,                         // lpOutBuffer
  0,                            // nOutBufferSize
  (LPDWORD) lpBytesReturned,    // number of bytes returned
  (LPOVERLAPPED) lpOverlapped   // OVERLAPPED structure
);
```

## Parameters

### `hDevice` [in]

A handle to the disk.

To retrieve a device handle, call the [**CreateFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) function.

### `dwIoControlCode` [in]

The control code for the operation.

Use **IOCTL_DISK_SET_DRIVE_LAYOUT** for this operation.

### `lpInBuffer` [in, optional]

A pointer to the input buffer that contains the [**DRIVE_LAYOUT_INFORMATION**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information) data to be set.

### `nInBufferSize` [in]

The size of the input buffer, in bytes. It must be >= **sizeof**(DRIVE_LAYOUT_INFORMATION).

### `lpOutBuffer` [out, optional]

Not used with this operation. Set to **NULL**.

### `nOutBufferSize` [in]

The size of the input buffer, in bytes. Set to 0 (zero).

### `lpBytesReturned` [out, optional]

A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

### `lpOverlapped` [in, out, optional]

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

## Return value

If the operation completes successfully, the return value is nonzero.

If the operation fails or is pending, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the partition is on a disk formatted as type master boot record (MBR), partition size totals cannot exceed 2 TB per MBR disk. For example, a disk of type MBR can have a single 2-TB partition, two 1-TB partitions, or any combination that does not total more than 2 TB. If more space is required, a disk formatted as type GUID partition table (GPT) should be used. If third-party partitioning tools are used to work around this limitation on disks of type MBR larger than 2 TB, configuration operations via the disk partitioning IOCTL control codes will be limited.

## See also

* [DRIVE_LAYOUT_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/win32/FileIO/disk-management-control-codes)
* [IOCTL_DISK_SET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout_ex)
* [IOCTL_DISK_GET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout)