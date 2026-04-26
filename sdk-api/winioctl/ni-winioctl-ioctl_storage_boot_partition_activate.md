# IOCTL_STORAGE_BOOT_PARTITION_ACTIVATE IOCTL

## Description

Activates or replaces a boot partition on the storage controller or disk using the [NVMe Firmware Commit](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_admin_commands) command (NVME_ADMIN_COMMAND_FIRMWARE_COMMIT) with boot partition-specific action codes. This IOCTL supports two mutually exclusive operations: replacing an existing boot partition with a downloaded image or activating an existing boot partition.

To perform this operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function using the following parameters.

```cpp
BOOL DeviceIoControl(
      (HANDLE) hDevice,                 // handle to device
      IOCTL_STORAGE_BOOT_PARTITION_ACTIVATE,  // dwIoControlCode
      (LPDWORD) lpInBuffer,             // input buffer
      (DWORD) nInBufferSize,            // size of input buffer
      (LPDWORD) lpOutBuffer,            // output buffer
      (DWORD) nOutBufferSize,           // size of output buffer
      (LPDWORD) lpBytesReturned,        // number of bytes returned
      (LPOVERLAPPED) lpOverlapped       // OVERLAPPED structure
);
```

## Parameters

### Input buffer

A pointer to a [STORAGE_HW_BOOT_PARTITION_ACTIVATE](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_boot_partition_activate) structure that specifies the boot partition to activate and the action to perform.

### Input buffer length

The size of the input buffer, in bytes. Set *nInBufferSize* to `sizeof(STORAGE_BOOT_PARTITION_ACTIVATE)`.

### Output buffer

None. Set *lpOutBuffer* to **NULL**.

### Output buffer length

Set *nOutBufferSize* to zero.

### Status block

If the operation completes successfully, [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This IOCTL commits a boot partition image to the NVMe controller using the Firmware Commit command with boot partition-specific action codes. It supports two mutually exclusive operations:

- **Replace**: Commits a previously downloaded boot partition image (via [IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_download)) to the specified boot partition slot.
- **Activate**: Activates an existing boot partition without modifying its contents.

To update a boot partition, first use [IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_download) to transfer the image data, then use this IOCTL to commit and activate the new image.

The caller must have administrative privileges to issue this IOCTL.

## See also

[IOCTL_STORAGE_BOOT_PARTITION_GET_INFO IOCTL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_get_info), [IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD IOCTL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_download)