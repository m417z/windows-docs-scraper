# _USB_START_TRACKING_FOR_TIME_SYNC_INFORMATION structure

## Description

The input and output buffer for the [IOCTL_USB_START_TRACKING_FOR_TIME_SYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_start_tracking_for_time_sync) request.

## Members

### `TimeTrackingHandle`

Registration handle for time sync tracking retrieved through the [IOCTL_USB_START_TRACKING_FOR_TIME_SYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_start_tracking_for_time_sync) request. On input, this handle must be set to NULL. On output, the USB driver stack sets this member to the assigned handle.

### `IsStartupDelayTolerable`

On input, the caller must specify whether the initial startup latency of up to 2.048 seconds is tolerable. TRUE indicates that the caller can tolerate the initial startup latency FALSE, the registration is delayed until the USB driver stack is able to detect a valid frame or microframe boundary.

## See also

[IOCTL_USB_START_TRACKING_FOR_TIME_SYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_start_tracking_for_time_sync)