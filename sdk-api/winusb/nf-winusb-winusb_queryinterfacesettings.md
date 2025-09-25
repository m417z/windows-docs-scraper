# WinUsb_QueryInterfaceSettings function

## Description

The **WinUsb_QueryInterfaceSettings** function retrieves the interface descriptor for the specified alternate interface settings for a particular interface handle.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to an interface in the selected configuration.

To retrieve the settings of the first interface, use the handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For all other interfaces, use the handle to the target interface, retrieved by [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `AlternateInterfaceNumber` [in]

A value that indicates which alternate settings to return. A value of 0 indicates the first alternate setting, a value of 1 indicates the second alternate setting, and so on.

### `UsbAltInterfaceDescriptor` [out]

A pointer to a caller-allocated [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbspec/ns-usbspec-_usb_interface_descriptor) structure that contains information about the interface that *AlternateSettingNumber* specified.

## Return value

**WinUsb_QueryInterfaceSettings** returns **TRUE** if the operation succeeds. Otherwise, it returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |
| **ERROR_NO_MORE_ITEMS** | The specified alternate interface was not found. |

## Remarks

**WinUsb_QueryInterfaceSettings** parses the configuration descriptor previously retrieved by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For more information, see the Remarks section for **WinUsb_Initialize**.

The **WinUsb_QueryInterfaceSettings** call searches the interface array for the alternate interface specified by the interface index passed by the caller in the *AlternateSettingNumber*. If the specified interface is found, the function populates the caller-allocated [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbspec/ns-usbspec-_usb_interface_descriptor) structure. If the specified interface is not found, then the call fails with the ERROR_NO_MORE_ITEMS code.

## See also

[USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbspec/ns-usbspec-_usb_interface_descriptor)

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)