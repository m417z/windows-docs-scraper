# WDF_USB_PIPE_DIRECTION_OUT function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_PIPE_DIRECTION_OUT** function determines whether a specified USB endpoint is an output endpoint.

## Parameters

### `EndpointAddress` [in]

A USB endpoint address.

## Return value

**WDF_USB_PIPE_DIRECTION_OUT** returns **TRUE** if the specified endpoint is an output endpoint. Otherwise, this function returns **FALSE**.

## Remarks

The high bit of the endpoint address determines the direction (input or output) of an endpoint. For more information about endpoint addresses, see the USB specification.

For more information about the **WDF_USB_PIPE_DIRECTION_OUT** function and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

## See also

[WDF_USB_PIPE_DIRECTION_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_pipe_direction_in)

[WdfUsbTargetPipeIsOutEndpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeisoutendpoint)