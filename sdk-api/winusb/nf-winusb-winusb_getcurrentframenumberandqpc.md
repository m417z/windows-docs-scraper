# WinUsb_GetCurrentFrameNumberAndQpc function

## Description

The **WinUsb_GetCurrentFrameNumberAndQpc** function retrieves the system query performance counter (QPC) value synchronized with the frame and microframe.

## Parameters

### `InterfaceHandle` [in]

An opaque handle retrieved in the previous call to [WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize).

### `FrameQpcInfo` [in]

A pointer to a [USB_FRAME_NUMBER_AND_QPC_FOR_TIME_SYNC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbioctl/ns-usbioctl-_usb_frame_number_and_qpc_for_time_sync_information) structure. On output, **CurrentQueryPerformanceCounter** set to the system QPC value (in microseconds) predicted by the USB driver stack. Optionally, on input, the caller can specify a frame and microframe number for which to retrieve the QPC value.

On output, the **QueryPerformanceCounterAtInputFrameOrMicroFrame** member is set to the QPC value for that frame or microframe.

## Return value

**WinUsb_GetCurrentFrameNumberAndQpc** returns **TRUE** if the operation succeeds. Otherwise, this routine returns **FALSE**, and the caller can retrieve the logged error by calling **GetLastError**.

**GetLastError** can return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The caller passed **NULL** in the *InterfaceHandle* or *FrameQpcInfo* parameter. |

## See also

[WinUSB](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)

[WinUSB Functions](https://learn.microsoft.com/windows/iot-core/learn-about-hardware/hardwarecompatlist)

[WinUsb_Initialize](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_initialize)

[WinUsb_StartTrackingForTimeSync](https://learn.microsoft.com/windows/desktop/api/winusb/nf-winusb-winusb_starttrackingfortimesync)