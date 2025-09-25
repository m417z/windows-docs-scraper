# WdfUsbInterfaceGetConfiguredPipe function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbInterfaceGetConfiguredPipe** method returns a handle to the framework pipe object that is associated with a specified USB device interface and pipe index. Optionally, the method also returns information about the pipe.

## Parameters

### `UsbInterface` [in]

A handle to a USB interface object that was obtained by calling [WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface).

### `PipeIndex` [in]

A zero-based index into the set of framework pipe objects that are associated with the specified interface object.

### `PipeInfo` [in, out, optional]

A pointer to a caller-allocated [WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information) structure that the framework fills in. This parameter is optional and can be **NULL**.

## Return value

If the operation succeeds, **WdfUsbInterfaceGetConfiguredPipe** returns a handle to the framework pipe object that is associated with the specified interface object and pipe index. The method returns **NULL** if the [WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information) structure's size is incorrect or if the pipe index value is too large.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver can call **WdfUsbInterfaceGetConfiguredPipe** after it has called [WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig).

For more information about the **WdfUsbInterfaceGetConfiguredPipe** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example sends a USB abort request to each configured pipe of a specified USB interface.

```cpp
BYTE  count, i;
NTSTATUS  status;

count = WdfUsbInterfaceGetNumConfiguredPipes(UsbInterface);

for (i = 0; i < count; i++) {
    WDFUSBPIPE pipe;
    pipe = WdfUsbInterfaceGetConfiguredPipe(
                                            UsbInterface,
                                            i,
                                            NULL
                                            );
    status = WdfUsbTargetPipeAbortSynchronously(
                                            pipe,
                                            WDF_NO_HANDLE,
                                            NULL
                                            );

    if (!NT_SUCCESS(status)) {
        break;
    }
}
```

## See also

[WDF_USB_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_pipe_information)

[WdfUsbInterfaceGetNumConfiguredPipes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetnumconfiguredpipes)

[WdfUsbTargetDeviceGetInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetinterface)

[WdfUsbTargetDeviceSelectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceselectconfig)