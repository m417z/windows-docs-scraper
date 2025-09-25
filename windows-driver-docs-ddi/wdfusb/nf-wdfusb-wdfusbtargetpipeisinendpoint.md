# WdfUsbTargetPipeIsInEndpoint function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeIsInEndpoint** method determines whether a specified USB pipe is connected to an input endpoint.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that represents a bulk pipe or interrupt pipe and was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

## Return value

**WdfUsbTargetPipeIsInEndpoint** returns **TRUE** if the pipe that the *Pipe* handle represents is an input endpoint. The method returns **FALSE** if the endpoint is an output endpoint.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the **WdfUsbTargetPipeIsInEndpoint** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example determines whether a specified USB pipe is connected to an input endpoint.

```cpp
BOOLEAN isInEndPoint;

isInEndPoint = WdfUsbTargetPipeIsInEndpoint(usbPipe);
```

## See also

[WDF_USB_PIPE_DIRECTION_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_pipe_direction_in)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)

[WdfUsbTargetPipeIsOutEndpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeisoutendpoint)