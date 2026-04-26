# IOCTL_STORAGE_BOOT_PARTITION_GET_INFO IOCTL

## Description

Retrieves boot partition information from a storage controller or disk by issuing a [GetLogPage](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) command for the **Boot Partition Log Page** (NVME_LOG_PAGE_BOOT_PARTITION).

To perform this operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function using the following parameters.

```cpp
BOOL DeviceIoControl(
    HANDLE hDevice,                   // handle to device
    IOCTL_STORAGE_BOOT_PARTITION_GET_INFO,  // dwIoControlCode
    LPVOID lpInBuffer,                // input buffer
    DWORD nInBufferSize,              // size of input buffer
    LPVOID lpOutBuffer,               // output buffer
    DWORD nOutBufferSize,             // size of output buffer
    LPDWORD lpBytesReturned,          // number of bytes returned
    LPOVERLAPPED lpOverlapped         // OVERLAPPED structure
);
```

## Parameters

### Input buffer

A pointer to a [STORAGE_HW_BOOT_PARTITION_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_boot_partition_info) structure. Set *nInBufferSize* to `sizeof(STORAGE_HW_BOOT_PARTITION_INFO)`.

### Input buffer length

The size of the input buffer, in bytes.

### Output buffer

A pointer to a [STORAGE_HW_BOOT_PARTITION_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_boot_partition_info) structure that receives the boot partition information. Set *nOutBufferSize* to `sizeof(STORAGE_HW_BOOT_PARTITION_INFO)`.

### Output buffer length

The size of the output buffer, in bytes.

### Status block

If the operation completes successfully, [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This IOCTL is used to query boot partition information from NVMe storage devices that support boot partitions. The controller issues a GetLogPage command requesting the Boot Partition Log Page (NVME_LOG_PAGE_BOOT_PARTITION) to retrieve this information.

The caller must have administrative privileges to issue this IOCTL.

## See also

[IOCTL_STORAGE_BOOT_PARTITION_ACTIVATE IOCTL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_activate), [IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD IOCTL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_download)