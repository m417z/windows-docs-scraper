# STORAGE\_HW\_FIRMWARE\_INFO\_QUERY structure

This structure contains information about the device firmware.

## Members

**Version**

The version of this structure. This should be set to sizeof(STORAGE\_HW\_FIRMWARE\_INFO\_QUERY)

**Size**

The size of this structure as a buffer.

**Flags**

The flags associated with the query. The following are flags that can be set in this member.

| Flag | Description |
|--------------------------------------------------|------------------------------------------------------------------------------------|
| STORAGE\_HW\_FIRMWARE\_REQUEST\_FLAG\_CONTROLLER | Indicates that the target of the request other than the device hand/object itself. |

**Reserved**

Reserved for future use.

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

[**STORAGE\_HW\_FIRMWARE\_SLOT\_INFO**](https://learn.microsoft.com/windows/win32/fileio/storage-hw-firmware-slot-info)

