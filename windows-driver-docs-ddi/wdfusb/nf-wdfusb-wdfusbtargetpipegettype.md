# WdfUsbTargetPipeGetType function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeGetType** method returns the type of a specified USB pipe.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

## Return value

**WdfUsbTargetPipeGetType** returns a [WDF_USB_PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_pipe_type)-typed value that identifies the specified pipe's type.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the **WdfUsbTargetPipeGetType** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example determines the type of a USB pipe.

```cpp
WDF_USB_PIPE_TYPEusbPipeType;

usbPipeType = WdfUsbTargetPipeGetType(usbPipe);

```

## See also

[WDF_USB_PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_pipe_type)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)