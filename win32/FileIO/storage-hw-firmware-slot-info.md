# STORAGE\_HW\_FIRMWARE\_SLOT\_INFO structure

This structure contains information about a slot on a device.

## Members

**Version**

The version of this structure. This should be set to sizeof(STORAGE\_HW\_FIRMWARE\_SLOT\_INFO)

**Size**

The size of this structure.

**SlotNumber**

The slot number of this slot.

**ReadOnly**

Indicates whether this slot is read-only or not.

**Reserved0**

Reserved for future use.

**Reserved1**

Reserved for future use.

**Revision**

The revision of the firmware on this slot.

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

[**STORAGE\_HW\_FIRMWARE\_INFO**](https://learn.microsoft.com/windows/win32/fileio/storage-hw-firmware-info)

[**STORAGE\_HW\_FIRMWARE\_INFO\_QUERY**](https://learn.microsoft.com/windows/win32/fileio/storage-hw-firmware-info-query)

