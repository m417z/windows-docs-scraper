# MEDIA\_SERIAL\_NUMBER\_DATA structure

Contains the serial number of a USB device. It is used by the [**IOCTL\_STORAGE\_GET\_MEDIA\_SERIAL\_NUMBER**](https://learn.microsoft.com/windows/desktop/api/WinIoCtl/ni-winioctl-ioctl_storage_get_media_serial_number) control code.

## Members

**SerialNumberLength**

The size of the **SerialNumberData** string, in bytes.

**Result**

The status of the request.

**Reserved**

Reserved.

**SerialNumberData**

The serial number of the device.

## Remarks

No header file is available for the **MEDIA\_SERIAL\_NUMBER\_DATA** structure. Include the structure definition at the top of this page in your source code.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------|
| Minimum supported client<br> | Windows XP<br> |
| Minimum supported server<br> | Windows Server 2003<br> |

## See also

[**IOCTL\_STORAGE\_GET\_MEDIA\_SERIAL\_NUMBER**](https://learn.microsoft.com/windows/desktop/api/WinIoCtl/ni-winioctl-ioctl_storage_get_media_serial_number)

