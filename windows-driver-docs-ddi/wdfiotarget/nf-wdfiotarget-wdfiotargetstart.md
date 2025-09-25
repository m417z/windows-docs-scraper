# WdfIoTargetStart function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetStart** method starts sending queued requests to a local or remote I/O target.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate), or from a method that a specialized I/O target provides.

## Return value

**WdfIoTargetStart** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_STATE** | The device has been removed. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If your driver can detect recoverable device errors, you might want your driver to call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) to temporarily stop sending requests, then later call **WdfIoTargetStart** to resume sending requests.

Additionally, if a driver calls [WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader) to configure a continuous reader for a USB pipe, the driver's [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) callback function must call **WdfIoTargetStart** to start the reader.

Your driver must call **WdfIoTargetStart** and [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) synchronously. After the driver calls one of these functions, it must not call the other function before the first one returns.

For more information about **WdfIoTargetStart**, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example shows how an [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) callback function can call **WdfIoTargetStart**, if the driver uses a continuous reader for a USB pipe.

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

[EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop)

[WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader)