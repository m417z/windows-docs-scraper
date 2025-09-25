# IOCTL_DISK_SET_DRIVE_LAYOUT_EX IOCTL

## Description

Partitions a disk according to the specified drive layout and partition information data.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters. You must have write access to the drive in order to use this control code.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_DISK_SET_DRIVE_LAYOUT_EX,   // dwIoControlCode
  (LPVOID) lpInBuffer,              // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  NULL,                             // lpOutBuffer
  0,                                // nOutBufferSize
  (LPDWORD) lpBytesReturned,        // number of bytes returned
  (LPOVERLAPPED) lpOverlapped       // OVERLAPPED structure
);
```

## Parameters

### `hDevice` [in]

A handle to the disk.

To retrieve a device handle, call the [**CreateFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) function.

### `dwIoControlCode` [in]

The control code for the operation.

Use **IOCTL_DISK_SET_DRIVE_LAYOUT_EX** for this operation.

### `lpInBuffer` [in, optional]

A pointer to the input buffer that contains the [**DRIVE_LAYOUT_INFORMATION_EX**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information_ex) data to be set.

### `nInBufferSize` [in]

The size of the input buffer, in bytes. It must be >= **sizeof**(DRIVE_LAYOUT_INFORMATION_EX).

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

When specifying a **GUID** partition table (GPT) as the [PARTITION_STYLE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-partition_style) of the [CREATE_DISK](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-create_disk) structure, an application should wait for the MSR partition arrival before sending the **IOCTL_DISK_SET_DRIVE_LAYOUT_EX** control code. For more information about device notification, see [RegisterDeviceNotification](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerdevicenotificationa).

When creating and manipulating an Extended Boot Record (EBR), the first entry of the EBR should point to the logical drive that immediately follows the EBR and the next EBR should lie after the end of the current logical drive and before the start of the next logical drive.

If the partition is on a disk formatted as type master boot record (MBR), partition size totals are limited. For more information, see the Remarks section of [IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_set_drive_layout).

## See also

* [DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-drive_layout_information_ex)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/win32/FileIO/disk-management-control-codes)
* [IOCTL_DISK_GET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_layout_ex)