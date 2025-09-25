# WinUsb_StartTrackingForTimeSync function

## Description

The **WinUsb_StartTrackingForTimeSync** function starts the time synchronization feature in the USB driver stack that gets the associated system QPC time for USB bus frames and microframes.

## Parameters

### `InterfaceHandle` [in]

An opaque handle retrieved in the previous call to [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

### `StartTrackingInfo` [in]

A pointer to a [USB_START_TRACKING_FOR_TIME_SYNC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbioctl/ns-usbioctl-_usb_start_tracking_for_time_sync_information) structure. Set **TimeTrackingHandle** to INAVLID_HANDLE.
Set **IsStartupDelayTolerable** to TRUE if the initial startup latency of up to 2.048 seconds is tolerable. FALSE, the registration is delayed until the USB driver stack is able to detect a valid frame or microframe boundary.

## Return value

**WinUsb_StartTrackingForTimeSync** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* or *StartTrackingInfo* parameter. |

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)