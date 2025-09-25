# IOCTL_USB_GET_FRAME_NUMBER_AND_QPC_FOR_TIME_SYNC IOCTL

## Description

Retrieves the system query performance counter (QPC) value synchronized with the frame and microframe.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

A pointer to a [USB_FRAME_NUMBER_AND_QPC_FOR_TIME_SYNC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_frame_number_and_qpc_for_time_sync_information) structure that contains the time tracking handled retrieved by the [IOCTL_USB_START_TRACKING_FOR_TIME_SYNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_start_tracking_for_time_sync) request. On input, the caller can specify a frame and microframe number for which to retrieve the QPC value.

On output, the **CurrentQueryPerformanceCounter** member is set to a value predicted by the USB driver stack. The value represents the system QPC value in microseconds.

### Input/output buffer length

The size of the [USB_FRAME_NUMBER_AND_QPC_FOR_TIME_SYNC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_frame_number_and_qpc_for_time_sync_information) structure.

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** indicates an appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

On input, the caller can optionally specify a frame and microframe for which the caller is interested in knowing the associated system QPC value. Those values must be provided in the **InputFrameNumber** and **InputMicroFrameNumber** members of [USB_FRAME_NUMBER_AND_QPC_FOR_TIME_SYNC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_frame_number_and_qpc_for_time_sync_information), respectively. On output, the USB driver stack fills the **QueryPerformanceCounterAtInputFrameOrMicroFrame** member with a system QPC value calculated by the USB driver stack.

If the caller is not interested those values, **InputFrameNumber** and **InputMicroFrameNumber** values must be initialized to 0. On output, **QueryPerformanceCounterAtInputFrameOrMicroFrame** is set to 0.

 If the USB driver stack encountered a frame boundary, the **PredictedAccuracyInMicroSeconds** value indicates accuracy in 125-microseconds unit. It also takes into consideration if sufficient time has elapsed since tracking is enabled.

The USB driver stack can also predict the system QPC value that are synchronized with bus frame and microframe numbers retrieved directly from the host controller.

In order to predict QPC values with accuracy, the USB driver stack might poll the frame and microframe time sources. That polling operation might require raising or lowering of IRQL to eliminate scheduling delays interfering with the accuracy of the value (after attempting to read the register/QPC timer from passive IRQL for a given number of tries). Given this possible additional CPU cost, this interface must only be used to get associated USB bus and QPC values and must not be used as a replacement to existing methods for retrieving just the USB bus time.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)