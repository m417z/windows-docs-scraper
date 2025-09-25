# WdfUsbTargetPipeIsOutEndpoint function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeIsOutEndpoint** method determines whether a specified USB pipe is connected to an output endpoint.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that represents a bulk pipe or interrupt pipe and was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

## Return value

**WdfUsbTargetPipeIsOutEndpoint** returns **TRUE** if the pipe that the *Pipe* handle represents an output endpoint. The method returns **FALSE** if the endpoint is an input endpoint.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the **WdfUsbTargetPipeIsOutEndpoint** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example determines whether a specified USB pipe is connected to an output endpoint.

```cpp
BOOLEAN isOutEndPoint;

isOutEndPoint = WdfUsbTargetPipeIsOutEndpoint(usbPipe);
```

## See also

[WDF_USB_PIPE_DIRECTION_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_pipe_direction_out)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)

[WdfUsbTargetPipeIsInEndpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeisinendpoint)