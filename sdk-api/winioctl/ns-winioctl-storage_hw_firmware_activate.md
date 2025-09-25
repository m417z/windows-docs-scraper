# STORAGE_HW_FIRMWARE_ACTIVATE structure

## Description

This structure contains information about the downloaded firmware to activate.

## Members

### `Version`

The version of this structure. This should be set to sizeof(STORAGE_HW_FIRMWARE_ACTIVATE).

### `Size`

The size of this structure. This should be set to sizeof(STORAGE_HW_FIRMWARE_ACTIVATE).

### `Flags`

The flags associated with the activation request. The following are valid flags that can be set in this member.

| Flag | Description |
| --- | --- |
| STORAGE_HW_FIRMWARE_REQUEST_FLAG_CONTROLLER | Indicates that the target of the request is a controller or adapter, different than the device handle or object itself (e.g. NVMe SSD or HBA). |
| STORAGE_HW_FIRMWARE_REQUEST_FLAG_SWITCH_TO_EXISTING_FIRMWARE | Indicates that the existing firmware image in the specified slot should be activated. |
| STORAGE_HW_FIRMWARE_REQUEST_FLAG_REPLACE_EXISTING_IMAGE | **Supported in Windows 11, version 24H2, and later.**\ Indicates that the existing firmware in the slot should be activated with a controller reset. |

### `Slot`

The slot with the firmware image that is to be activated.

### `Reserved0`

Reserved for future use.

## See also

[IOCTL_STORAGE_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_firmware_activate)

[IOCTL_STORAGE_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_firmware_download)

[IOCTL_STORAGE_FIRMWARE_GET_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_firmware_get_info)

[STORAGE_HW_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_hw_firmware_download)

[STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-info)

[STORAGE_HW_FIRMWARE_INFO_QUERY](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-info-query)

[STORAGE_HW_FIRMWARE_SLOT_INFO](https://learn.microsoft.com/windows/desktop/FileIO/storage-hw-firmware-slot-info)