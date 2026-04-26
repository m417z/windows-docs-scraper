# STORAGE_HW_BOOT_PARTITION_DOWNLOAD structure

## Description

Contains a boot partition image payload to be downloaded to an NVMe storage controller or disk. This structure is used as the input buffer for the [IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_download) control code.

## Members

### `Version`

The version of this structure. Set this to **STORAGE_HW_BOOT_PARTITION_DOWNLOAD_STRUCTURE_VERSION** (0x01).

### `Size`

The size of this structure including the image buffer, in bytes.

### `Flags`

Flags associated with this download. The following are valid flags that this member can hold.

| Flag | Description |
| --- | --- |
| STORAGE_HW_BOOT_PARTITION_REQUEST_FLAG_CONTROLLER | Indicates that the target of the request is a controller or adapter, different than the device handle or object itself (for example, NVMe SSD or HBA). |

### `BPID`

The boot partition ID that the image will be downloaded to. Valid values are 0 or 1.

### `Reserved[3]`

Reserved for future use.

### `Offset`

The offset within the boot partition image where this chunk begins. This value should be aligned to **ImagePayloadAlignment** from [STORAGE_HW_BOOT_PARTITION_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_boot_partition_info).

### `BufferSize`

The size of the **ImageBuffer** data, in bytes. This value should be a multiple of **ImagePayloadAlignment** from [STORAGE_HW_BOOT_PARTITION_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_boot_partition_info).

### `ImageBuffer[ANYSIZE_ARRAY]`

The boot partition image data for this download chunk.

## Remarks

This structure is used with [IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_download), which issues an NVMe Firmware Download command (**NVME_ADMIN_COMMAND_FIRMWARE_IMAGE_DOWNLOAD**) to transfer image data to the controller's internal buffer. For large boot partition images that exceed the controller's maximum transfer size (reported in **ImagePayloadMaxSize** from [STORAGE_HW_BOOT_PARTITION_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_boot_partition_info)), the image must be split into multiple chunks and downloaded using multiple IOCTL calls with the appropriate **Offset** values.

After all image data has been downloaded, use [IOCTL_STORAGE_BOOT_PARTITION_ACTIVATE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_activate) with the **STORAGE_HW_BOOT_PARTITION_REQUEST_REPLACE_EXISTING_BOOT_PARTITION** flag to commit the downloaded image to the boot partition.

> [!NOTE]
> These IOCTLs are currently only supported for PCIe NVMe devices.

## See also

[IOCTL_STORAGE_BOOT_PARTITION_DOWNLOAD](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_download)

[IOCTL_STORAGE_BOOT_PARTITION_GET_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_get_info)

[IOCTL_STORAGE_BOOT_PARTITION_ACTIVATE](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_boot_partition_activate)

[STORAGE_HW_BOOT_PARTITION_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_boot_partition_info)

[STORAGE_HW_BOOT_PARTITION_ACTIVATE](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_hw_boot_partition_activate)