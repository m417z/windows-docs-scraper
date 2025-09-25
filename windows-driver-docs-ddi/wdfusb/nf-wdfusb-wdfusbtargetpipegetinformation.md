# WdfUsbTargetPipeGetInformation function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeGetInformation** method retrieves information about a USB pipe and its endpoint.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

### `PipeInformation` [out]

A pointer to a caller-allocated [WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information) structure that receives information about the pipe and endpoint.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

For more information about the **WdfUsbTargetPipeGetInformation** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example initializes a [WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information) structure and calls **WdfUsbTargetPipeGetInformation**.

```cpp
WDF_USB_PIPE_INFORMATION pipeInfo;

WDF_USB_PIPE_INFORMATION_INIT(&pipeInfo);
WdfUsbTargetPipeGetInformation(
                               Pipe,
                               &pipeInfo
                               );
```

## See also

[WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information)

[WDF_USB_PIPE_INFORMATION_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_pipe_information_init)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)