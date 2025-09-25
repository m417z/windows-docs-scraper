# EVT_UCX_CONTROLLER_START_TRACKING_FOR_TIME_SYNC callback function

## Description

UCX invokes this callback function to the start time tracking functionality in the controller.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `WdfRequest` [in]

A framework request object that contains the request to start time tracking.

### `OutputBufferLength` [in]

The length, in bytes, of the request's output buffer, if an output buffer
is available. This value is the size of the [USB_START_TRACKING_FOR_TIME_SYNC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_start_tracking_for_time_sync_information) structure.

### `InputBufferLength` [in]

The length, in bytes, of the request's input buffer, if an input buffer
is available. This value is the size of the [USB_START_TRACKING_FOR_TIME_SYNC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_start_tracking_for_time_sync_information) structure.

## See also

[IOCTL_USB_START_TRACKING_FOR_TIME_SYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_start_tracking_for_time_sync)