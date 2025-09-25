# WdfUsbTargetPipeSetNoMaximumPacketSizeCheck function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeSetNoMaximumPacketSizeCheck** method disables the framework's test of whether the size of a driver's read buffer is a multiple of a USB pipe's maximum packet size.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

To avoid receiving extra data from unexpected bus activity, which is sometimes called *babble*, drivers usually specify read buffers that are a multiple of the pipe's maximum packet size. (Drivers receive a USB pipe's maximum packet size in a [WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information) structure.) By default, the framework reports an error if a driver specifies a read buffer that is not a multiple of the pipe's maximum packet size. If the driver calls **WdfUsbTargetPipeSetNoMaximumPacketSizeCheck**, the framework does not report an error if a read buffer is not a multiple of the maximum packet size.

For more information about the **WdfUsbTargetPipeSetNoMaximumPacketSizeCheck** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example disables the framework's test of whether the size of a buffer is a multiple of a USB pipe's maximum packet size.

```cpp
WdfUsbTargetPipeSetNoMaximumPacketSizeCheck(pipe);

```

## See also

[WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)