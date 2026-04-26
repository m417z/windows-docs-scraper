# IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD IOCTL

## Description

Downloads a boot partition image to the storage controller or disk using the [NVMe Firmware Download](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_admin_commands) command (NVME_ADMIN_COMMAND_FIRMWARE_IMAGE_DOWNLOAD) opcode to transfer image data to the controller's internal buffer. Multiple download requests may be required for large images (using offset-based chunking).

To perform this operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function using the following parameters.

```cpp
BOOL DeviceIoControl(
      HANDLE hDevice,                 // handle to device
      IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD,  // dwIoControlCode
      LPVOID lpInBuffer,             // input buffer
      DWORD nInBufferSize,            // size of input buffer
      LPVOID lpOutBuffer,            // output buffer
      DWORD nOutBufferSize,           // size of output buffer
      LPDWORD lpBytesReturned,        // number of bytes returned
      LPOVERLAPPED lpOverlapped       // OVERLAPPED structure
);
```

## Parameters

### Input buffer

A pointer to a STORAGE_HW_BOOT_PARTITION_DOWNLOAD structure that specifies the boot partition image data to download, including the offset and size of the image chunk.

### Input buffer length

The size of the input buffer, in bytes. Set *nInBufferSize* to `sizeof(STORAGE_HW_BOOT_PARTITION_DOWNLOAD)` plus the size of the image data being transferred.

### Output buffer

None. Set *lpOutBuffer* to **NULL**.

### Output buffer length

Set *nOutBufferSize* to zero.

### Status block

If the operation completes successfully, [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This IOCTL transfers boot partition image data to the NVMe controller's internal buffer using the Firmware Download command. For large boot partition images that exceed the controller's transfer size limit, the image must be split into multiple chunks and downloaded using multiple IOCTL calls with appropriate offset values.

After all image data has been downloaded, use [IOCTL_STORAGE_BOOT_PARTITION_ACTIVATE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_activate) to commit the downloaded image to the boot partition.

The caller must have administrative privileges to issue this IOCTL.

## See also

[IOCTL_STORAGE_BOOT_PARTITION_GET_INFO IOCTL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_get_info), [IOCTL_STORAGE_BOOT_PARTITION_ACTIVATE IOCTL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_activate)