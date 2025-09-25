# WdfUsbTargetPipeGetIoTarget function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeGetIoTarget** method returns a handle to the I/O target object that is associated with a specified USB pipe.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

## Return value

**WdfUsbTargetPipeGetIoTarget** returns a handle to the I/O target object that is associated with the specified pipe object.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the **WdfUsbTargetPipeGetIoTarget** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example shows how an [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) callback function can start a continuous reader for a USB pipe.

```cpp
NTSTATUS
MyEvtDeviceD0Entry(
    IN  WDFDEVICE Device,
    IN  WDF_POWER_DEVICE_STATE PreviousState
)
{
    PDEVICE_CONTEXT  pDeviceContext;
    NTSTATUS  status;

    pDeviceContext = GetMyDeviceContext(Device);

    status = WdfIoTargetStart(WdfUsbTargetPipeGetIoTarget(pDeviceContext->InterruptPipe));

    return status;
}
```

## See also

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)

[WdfUsbTargetDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicegetiotarget)