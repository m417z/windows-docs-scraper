# _USBD_VERSION_INFORMATION structure

## Description

The **USBD_VERSION_INFORMATION** structure is used by the [GetUSBDIVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_getusbdi_version) function to report its output data.

## Members

### `USBDI_Version`

Contains a binary-coded decimal USB interface version number. Released interface versions are listed in the following table.

| Operating system | Interface version |
| --- | --- |
| Windows 98 Gold | 0x00000102 |
| Windows 98 SE | 0x00000200 |
| Windows 2000 | 0x00000300 |
| Windows Millennium Edition | 0x00000400 |
| Windows XP | 0x00000500 |
| Windows Vista<br><br>Windows 7<br><br>Windows 8 | 0x00000600 |

### `Supported_USB_Version`

Contains a binary-coded decimal USB specification version number.

## Remarks

[GetUSBDIVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_getusbdi_version) is deprecated in Windows 8 and later versions of the operating system. To determine whether a particular version is supported by the underlying USB driver stack, the client driver must call [USBD_IsInterfaceVersionSupported](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isinterfaceversionsupported).

## See also

[GetUSBDIVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/nc-usbbusif-pusb_busiffn_getusbdi_version)

[USB Bus Driver Interface (USBDI) Routines](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540046(v=vs.85))

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)