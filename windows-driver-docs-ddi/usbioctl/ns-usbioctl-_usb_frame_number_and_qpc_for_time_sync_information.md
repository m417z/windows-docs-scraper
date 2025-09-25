# _USB_FRAME_NUMBER_AND_QPC_FOR_TIME_SYNC_INFORMATION structure

## Description

Stores the frame and microframe numbers and the calculated system QPC values. This structure is used in the [IOCTL_USB_GET_FRAME_NUMBER_AND_QPC_FOR_TIME_SYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_frame_number_and_qpc_for_time_sync) request.

## Members

### `TimeTrackingHandle`

The time racking handle received in the previous [IOCTL_USB_STOP_TRACKING_FOR_TIME_SYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_stop_tracking_for_time_sync) request.

### `InputFrameNumber`

A 32-bit USB bus frame number.

### `InputMicroFrameNumber`

A 3-bit value received from the hardware.

### `QueryPerformanceCounterAtInputFrameOrMicroFrame`

A value predicted by the USB driver stack that represents the system QPC value at the beginning of the frame and microframe represented by the **InputFrameNumber** and **InputMicroFrameNumber** input values.

### `QueryPerformanceCounterFrequency`

The current performance-counter frequency, in counts per second.

### `PredictedAccuracyInMicroSeconds`

A value that represents the accuracy of the predicted QPC value in micro seconds.

### `CurrentGenerationID`

An identifier for this request of time synchronization.

### `CurrentQueryPerformanceCounter`

Current QPC value captured that is synchronized with the bus frame numbers represented by **CurrentHardwareFrameNumber**, **CurrentHardwareMicroFrameNumber** and **CurrentUSBFrameNumber**.

### `CurrentHardwareFrameNumber`

A 1-bit value of the current hardware frame number that is directly read from the MFINDEX register.

### `CurrentHardwareMicroFrameNumber`

A 3-bit value of the current hardware micro frame number that is directly read from the MFINDEX register.

### `CurrentUSBFrameNumber`

A 32-bit USB frame number value returned by [_URB_GET_CURRENT_FRAME_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_get_current_frame_number).