# WinUsb_StopTrackingForTimeSync function

## Description

The **WinUsb_StopTrackingForTimeSync** function stops the time synchronization feature in the USB driver stack that gets the associated system QPC time for USB bus frames and microframes.

## Parameters

### `InterfaceHandle` [in]

An opaque handle retrieved in the previous call to [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

### `StopTrackingInfo` [in]

A pointer to a [USB_STOP_TRACKING_FOR_TIME_SYNC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbioctl/ns-usbioctl-_usb_stop_tracking_for_time_sync_information) structure. Set **TimeTrackingHandle** to the handle received in the previous call to [WinUsb_StartTrackingForTimeSync](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_starttrackingfortimesync).

## Return value

**WinUsb_StopTrackingForTimeSync** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* or *StopTrackingInfo* parameter. |

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)

[WinUsb_StartTrackingForTimeSync](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_starttrackingfortimesync)