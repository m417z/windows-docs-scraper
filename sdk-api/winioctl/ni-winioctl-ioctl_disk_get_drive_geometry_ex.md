# IOCTL_DISK_GET_DRIVE_GEOMETRY_EX IOCTL

## Description

Retrieves extended information about the physical disk's geometry: type, number of cylinders, tracks per cylinder, sectors per track, bytes per sector, and size.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_DISK_GET_DRIVE_GEOMETRY_EX, // dwIoControlCode
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

Use **IOCTL_DISK_GET_DRIVE_GEOMETRY_EX** for this operation.

### `lpInBuffer` [in, optional]

Not used with this operation. Set to **NULL**.

### `nInBufferSize` [in]

The size of the input buffer, in bytes. Set to 0 (zero).

### `lpOutBuffer` [out, optional]

A pointer to the output buffer that is to receive the [**DISK_GEOMETRY_EX**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry_ex) data returned by the operation.

If the size of the output buffer is (**sizeof**(DISK_GEOMETRY) + **sizeof**(LARGE_INTEGER)), the output buffer receives only [**DISK_GEOMETRY**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry) data and disk size.

If you want to get [**DISK_PARTITION_INFO**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_partition_info) data and [**DISK_DETECTION_INFO**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_detection_info) data, the size of the output buffer must be at least (**sizeof**(DISK_GEOMETRY) + **sizeof**(LARGE_INTEGER) + **sizeof**(DISK_PARTITION_INFO) + **sizeof**(DISK_DETECTION_INFO)).

### `nOutBufferSize` [in]

The size of the output buffer, in bytes. It must be at least (**sizeof**(DISK_GEOMETRY) + **sizeof**(LARGE_INTEGER)).

### `lpBytesReturned` [out, optional]

A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

### `lpOverlapped` [in, out, optional]

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

## Return value

If the operation completes successfully, the return value is nonzero.

If the operation fails, or is pending, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

* [DISK_GEOMETRY_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry_ex)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Disk Management Control Codes](https://learn.microsoft.com/windows/win32/FileIO/disk-management-control-codes)