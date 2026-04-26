# STORAGE_HW_BOOT_PARTITION_INFO structure

## Description

Contains boot partition information retrieved from an NVMe storage controller or disk. This structure is used as the input and output buffer for the [IOCTL_STORAGE_BOOT_PARTITION_GET_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_get_info) control code.

## Members

### `Version`

The version of this structure. Set this to **STORAGE_HW_BOOT_PARTITION_INFO_STRUCTURE_VERSION_V1** (0x01).

### `Size`

The size of this structure, in bytes.

### `BPSZ`

The boot partition size, in bytes.

### `Flags`

Flags associated with this request. The following are valid flags that this member can hold.

| Flag | Description |
| --- | --- |
| STORAGE_HW_BOOT_PARTITION_REQUEST_FLAG_CONTROLLER | Indicates that the target of the request is a controller or adapter, different than the device handle or object itself (for example, NVMe SSD or HBA). |

### `ImagePayloadAlignment`

The alignment of the image payload, in bytes. The maximum value is **PAGE_SIZE**. The transfer size must be a multiple of this value. Some protocols require at least sector-size alignment. A value of 0 indicates that the alignment value is invalid or not applicable.

### `ImagePayloadMaxSize`

The maximum size for a single image payload command, in bytes.

### `SlotCount`

The number of boot partition slots available. For NVMe devices, this value is 2 as defined by the NVMe specification.

### `ABPID`

The active boot partition ID (0 or 1).

## Remarks

This structure is returned by [IOCTL_STORAGE_BOOT_PARTITION_GET_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_get_info), which issues a Get Log Page command for the Boot Partition Log Page (**NVME_LOG_PAGE_BOOT_PARTITION**) to retrieve boot partition state from the NVMe controller.

The **ImagePayloadAlignment** and **ImagePayloadMaxSize** values should be used when preparing image data for download via [IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_download). The download buffer offset must be aligned to **ImagePayloadAlignment**, and each chunk size should be a multiple of **ImagePayloadAlignment** and not exceed **ImagePayloadMaxSize**.

> [!NOTE]
> These IOCTLs are currently only supported for PCIe NVMe devices.

## See also

[IOCTL_STORAGE_BOOT_PARTITION_GET_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_get_info)

[IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_download)

[IOCTL_STORAGE_BOOT_PARTITION_ACTIVATE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_activate)

[STORAGE_HW_BOOT_PARTITION_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_boot_partition_download)

[STORAGE_HW_BOOT_PARTITION_ACTIVATE](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_boot_partition_activate)