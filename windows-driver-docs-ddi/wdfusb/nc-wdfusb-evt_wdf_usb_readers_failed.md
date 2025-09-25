# EVT_WDF_USB_READERS_FAILED callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtUsbTargetPipeReadersFailed* event callback function informs the driver that a continuous reader has reported an error while processing a read request.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object.

### `Status` [in]

The [NTSTATUS value](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) that the pipe's I/O target returned.

### `UsbdStatus` [in]

The [USBD_STATUS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff539136(v=vs.85))-typed status value that the pipe's I/O target returned.

## Return value

The *EvtUsbTargetPipeReadersFailed* event callback function returns a Boolean value that, if **TRUE**, causes the framework to reset the USB pipe and then restart the continuous reader. If this function returns **FALSE**, the framework does not reset the device or restart the continuous reader.

## Remarks

To register an *EvtUsbTargetPipeReadersFailed* callback function, the driver must place the function's address in a [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure. For information about when to add this function pointer, see the Remarks section of [WDF_USB_CONTINUOUS_READER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_continuous_reader_config_init).

If a driver has created a continuous reader for a USB pipe, the framework calls the driver's *EvtUsbTargetPipeReadersFailed* callback function if the driver's I/O target reports an error when it completes a read request. (If the I/O target successfully completes the request, the framework calls the driver's [EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine) callback function.)

Before the framework calls a driver's *EvtUsbTargetPipeReadersFailed* callback function, it tries to cancel all in-progress read requests. No read requests are in progress when the framework calls the *EvtUsbTargetPipeReadersFailed* callback function. The framework does not queue any additional read requests until the *EvtUsbTargetPipeReadersFailed* callback function returns.

For information about how the framework synchronizes calls to the *EvtUsbTargetPipeReadersFailed* callback function with calls to other callback functions, see the Remarks section of [EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine).

The *EvtUsbTargetPipeReadersFailed* callback function must not call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) to stop the continuous reader's USB target. (In fact, calling **WdfIoTargetStop** in an *EvtUsbTargetPipeReadersFailed* callback function causes a deadlock.) In addition, the callback function must not call [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart) to restart the continuous reader. Instead, the framework restarts the reader if the callback function returns **TRUE**. For more information about when to call **WdfIoTargetStart** and **WdfIoTargetStop** for a continuous reader, see [Working with USB Pipes](https://learn.microsoft.com/windows-hardware/drivers/wdf/working-with-usb-pipes).

If a driver does not provide an *EvtUsbTargetPipeReadersFailed* callback function and the driver's I/O target reports an error, the framework resets the USB pipe and restarts the continuous reader.

For more information about the *EvtUsbTargetPipeReadersFailed* callback function and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

## See also

[EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine)

[WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config)