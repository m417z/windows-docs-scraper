# STORAGE\_HW\_FIRMWARE\_INFO structure

This structure contains information about the device firmware.

## Members

**Version**

The version of this structure. This should be set to sizeof(STORAGE\_HW\_FIRMWARE\_INFO)

**Size**

The size of this structure as a buffer including slot.

**SupportUpgrade**

Indicates that this firmware supports an upgrade.

**Reserved0**

Reserved for future use.

**SlotCount**

The number of firmware slots on the device. This is the dimension of the Slot array.

> [!Note]
> Some devices can store more than 1 firmware image, if they have more than 1 firmware slot.

**ActiveSlot**

The firmware slot containing the currently active/running firmware image.

**PendingActivateSlot**

The firmware slot that is pending activation.

**FirmwareShared**

Indicates that the firmware applies to both the device and controller/adapter, e.g. NVMe SSD.

**Reserved**

Reserved for future use.

**ImagePayloadAlignment**

The alignment of the image payload, in number of bytes. The maximum is PAGE\_SIZE. The transfer size is a mutliple of this size. Some protocols require at least sector size. When this value is set to 0, this means that this value is invalid.

**ImagePayloadMaxSize**

The image payload maximum size, this is used for a single command.

**Slot**

Contains the slot information for each slot on the device, of type [**STORAGE\_HW\_FIRMWARE\_SLOT\_INFO**](https://learn.microsoft.com/windows/win32/fileio/storage-hw-firmware-slot-info).

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Winioctl.h (include Windows.h) |

## See also

[**IOCTL\_STORAGE\_FIRMWARE\_ACTIVATE**](https://learn.microsoft.com/windows/desktop/api/WinIoctl/ni-winioctl-ioctl_storage_firmware_activate)

[**STORAGE\_HW\_FIRMWARE\_ACTIVATE**](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_hw_firmware_activate)

[**IOCTL\_STORAGE\_FIRMWARE\_DOWNLOAD**](https://learn.microsoft.com/windows/desktop/api/WinIoctl/ni-winioctl-ioctl_storage_firmware_download)

[**STORAGE\_HW\_FIRMWARE\_DOWNLOAD**](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_hw_firmware_download)

[**IOCTL\_STORAGE\_FIRMWARE\_GET\_INFO**](https://learn.microsoft.com/windows/desktop/api/WinIoctl/ni-winioctl-ioctl_storage_firmware_get_info)

[**STORAGE\_HW\_FIRMWARE\_INFO\_QUERY**](https://learn.microsoft.com/windows/win32/fileio/storage-hw-firmware-info-query)

[**STORAGE\_HW\_FIRMWARE\_SLOT\_INFO**](https://learn.microsoft.com/windows/win32/fileio/storage-hw-firmware-slot-info)

