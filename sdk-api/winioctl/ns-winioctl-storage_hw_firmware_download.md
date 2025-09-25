# STORAGE_HW_FIRMWARE_DOWNLOAD structure

## Description

This structure contains a firmware image payload to be downloaded to the target.

## Members

### `Version`

The version of this structure. This should be set to sizeof(STORAGE_HW_FIRMWARE_DOWNLOAD).

### `Size`

The size of this structure and the download image buffer.

### `Flags`

Flags associated with this download. The following are valid flags that this member can hold.

| Flag | Description |
| --- | --- |
| STORAGE_HW_FIRMWARE_REQUEST_FLAG_CONTROLLER | Indicates that the target of the request is a controller or adapter, different than the device handler or object itself (e.g. NVMe SSD or HBA). |
| STORAGE_HW_FIRMWARE_REQUEST_FLAG_LAST_SEGMENT | Indicates that the current firmware image segment is the last one. |

### `Slot`

The slot number that the firmware image will be downloaded to.

### `Reserved`

Reserved for future use.

### `Offset`

The offset in this buffer of where the Image file begins. This should be aligned to **ImagePayloadAlignment** from [STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-info).

### `BufferSize`

The buffer size of the ImageBuffer. This should be a multiple of **ImagePayloadAlignment** from [STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-info).

### `ImageBuffer`

The firmware image file.

## See also

[IOCTL_STORAGE_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_firmware_activate)

[IOCTL_STORAGE_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_firmware_download)

[IOCTL_STORAGE_FIRMWARE_GET_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_firmware_get_info)

[STORAGE_HW_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_hw_firmware_activate)

[STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-info)

[STORAGE_HW_FIRMWARE_INFO_QUERY](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-info-query)

[STORAGE_HW_FIRMWARE_SLOT_INFO](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-slot-info)