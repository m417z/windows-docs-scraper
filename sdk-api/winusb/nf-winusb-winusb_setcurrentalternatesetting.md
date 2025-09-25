# WinUsb_SetCurrentAlternateSetting function

## Description

The **WinUsb_SetCurrentAlternateSetting** function sets the alternate setting of an interface.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to an interface, which defines the alternate setting to set.

To set an alternate setting in the first interface on the device, use the interface handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For all other interfaces, use the handle to the target interface, retrieved by [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `SettingNumber` [in]

The value that is contained in the **bAlternateSetting** member of the [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbspec/ns-usbspec-_usb_interface_descriptor) structure. This structure is populated by the [WinUsb_QueryInterfaceSettings](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_queryinterfacesettings) routine.

## Return value

**WinUsb_SetCurrentAlternateSetting** returns **TRUE** if the operation succeeds. Otherwise, this function returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |

## Remarks

**WinUsb_SetCurrentAlternateSetting** fails if outstanding I/O requests are present on the interface.

## See also

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbspec/ns-usbspec-_usb_interface_descriptor)

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)

[WinUsb_QueryInterfaceSettings](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_queryinterfacesettings)