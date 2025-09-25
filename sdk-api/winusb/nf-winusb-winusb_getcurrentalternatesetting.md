# WinUsb_GetCurrentAlternateSetting function

## Description

The **WinUsb_GetCurrentAlternateSetting** function gets the current alternate interface setting for an interface. This is a synchronous operation.

## Parameters

### `InterfaceHandle` [in]

An opaque handle to an interface in the selected configuration. To get the current alternate setting in the first (default) interface on the device, use the interface handle returned by [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize). For all other interfaces, use the handle to the target interface, retrieved by [WinUsb_GetAssociatedInterface](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_getassociatedinterface).

### `SettingNumber` [out]

A pointer to an unsigned character that receives an integer that indicates the current alternate setting.

## Return value

**WinUsb_GetCurrentAlternateSetting** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* parameter. |

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)