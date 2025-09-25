# IOCTL_DISK_GET_DRIVE_LAYOUT IOCTL

## Description

Retrieves information for each entry in the partition tables for a disk.

> [!NOTE]
> **IOCTL_DISK_GET_DRIVE_LAYOUT** has been superseded by [**IOCTL_DISK_GET_DRIVE_LAYOUT_EX**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout_ex), which retrieves layout information for AT and EFI (Extensible Firmware Interface) partitions.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters. You must have read access to the drive in order to use this control code.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_DISK_GET_DRIVE_LAYOUT,  // dwIoControlCode
  NULL,                         // lpInBuffer
  0,                            // nInBufferSize
  (LPVOID) lpOutBuffer,         // output buffer
  (DWORD) nOutBufferSize,       // size of output buffer
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

Use **IOCTL_DISK_GET_DRIVE_LAYOUT** for this operation.

### `lpInBuffer` [in, optional]

Not used with this operation. Set to **NULL**.

### `nInBufferSize` [in]

The size of the input buffer, in bytes. Set to 0 (zero).

### `lpOutBuffer` [out, optional]

A pointer to the output buffer that is to receive the [**DRIVE_LAYOUT_INFORMATION**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information) data returned by the operation.

If the output buffer is not large enough to store the data, the function returns **FALSE** and [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INSUFFICIENT_BUFFER**.

### `nOutBufferSize` [in]

The size of the output buffer, in bytes. It must be >= **sizeof**(DRIVE_LAYOUT_INFORMATION).

### `lpBytesReturned` [out, optional]

A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

### `lpOverlapped` [in, out, optional]

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

## Return value

If the operation completes successfully, the return value is nonzero.

If the operation fails or is pending, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This operation retrieves information for each primary partition as well as each logical drive. To determine whether the entry is an extended or unused partition, check the [Disk Partition Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-partition-types).

## See also

* [DRIVE_LAYOUT_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/win32/FileIO/disk-management-control-codes)
* [IOCTL_DISK_GET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout_ex)
* [IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout)