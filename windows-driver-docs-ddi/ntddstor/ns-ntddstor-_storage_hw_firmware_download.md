# _STORAGE_HW_FIRMWARE_DOWNLOAD structure

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
| STORAGE_HW_FIRMWARE_REQUEST_FLAG_CONTROLLER | Indicates that the target of the request is a controller or adapter, different than the device handle or object itself (e.g. NVMe SSD or HBA). |
| STORAGE_HW_FIRMWARE_REQUEST_FLAG_LAST_SEGMENT | Indicates that the current firmware image segment is the last one. |

### `Slot`

The slot number that the firmware image will be downloaded to.

### `Reserved`

Reserved for future use.

### `Offset`

The offset in this buffer of where the Image file begins. This should be aligned to ImagePayloadAlignment from [STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_info).

### `BufferSize`

The buffer size of the ImageBuffer. This should be a multiple of ImagePayloadAlignment from [STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_info).

### `ImageBuffer`

The firmware image file.