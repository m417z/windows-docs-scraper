# IOCTL_DISK_GET_DRIVE_GEOMETRY IOCTL

## Description

Retrieves information about the physical disk's geometry: type, number of cylinders, tracks per cylinder, sectors per track, and bytes per sector.

> [!NOTE]
> **IOCTL_DISK_GET_DRIVE_GEOMETRY** has been superseded by [**IOCTL_DISK_GET_DRIVE_GEOMETRY_EX**](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_geometry_ex), which retrieves additional information.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_DISK_GET_DRIVE_GEOMETRY,    // dwIoControlCode
  NULL,                             // lpInBuffer
  0,                                // nInBufferSize
  (LPVOID) lpOutBuffer,             // output buffer
  (DWORD) nOutBufferSize,           // size of output buffer
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

Use **IOCTL_DISK_GET_DRIVE_GEOMETRY** for this operation.

### `lpInBuffer` [in, optional]

Not used with this operation. Set to **NULL**.

### `nInBufferSize` [in]

The size of the input buffer, in bytes. Set to 0 (zero).

### `lpOutBuffer` [out, optional]

A pointer to the output buffer that is to receive the [**DISK_GEOMETRY**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry) data returned by the operation.

### `nOutBufferSize` [in]

The size of the output buffer, in bytes. It must be >= **sizeof**(DISK_GEOMETRY).

### `lpBytesReturned` [out, optional]

A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

### `lpOverlapped` [in, out, optional]

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

## Return value

If the operation completes successfully, the return value is nonzero.

If the operation fails or is pending, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

* [DISK_GEOMETRY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/win32/FileIO/disk-management-control-codes)
* [IOCTL_DISK_GET_DRIVE_GEOMETRY_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_geometry_ex)
* [IOCTL_STORAGE_GET_MEDIA_TYPES](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_get_media_types)