# WdfIoTargetPurge function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetPurge** method cancels all I/O requests queued to a local, remote, or specialized I/O target and prevents any new I/O requests from being queued. The method also attempts to cancel I/O requests that have left the I/O target's queue and entered lower drivers.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate), or from a method supplied by a specialized I/O target, such as [WdfUsbTargetPipeGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipegetiotarget).

### `Action` [in]

A [WDF_IO_TARGET_PURGE_IO_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_purge_io_action)-typed value that indicates whether the framework should wait to return from **WdfIoTargetPurge** until all delivered requests are completed or canceled.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If the driver has previously called [WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader), **WdfIoTargetPurge** must be called at IRQL = PASSIVE_LEVEL.
If the driver has not called **WdfUsbTargetPipeConfigContinuousReader** and if the *Action* parameter of **WdfIoTargetPurge** is **WdfIoTargetPurgeIo**, **WdfIoTargetPurge** can be called at IRQL <= DISPATCH_LEVEL. Otherwise, **WdfIoTargetPurge** must be called at IRQL = PASSIVE_LEVEL.

To make **WdfIoTargetPurge** a synchronous call, the driver can set the **WdfIoTargetPurgeIoAndWait** value of the *Action* parameter. In this case, **WdfIoTargetPurge** waits to return until all delivered requests are completed or canceled.

After a driver has called **WdfIoTargetPurge**, it can still send a request to the target by setting the **WDF_REQUEST_SEND_OPTION_IGNORE_TARGET_STATE** flag in the request's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure. For example, a driver might send a request, such as a request to reset a USB pipe (see [WdfUsbTargetPipeResetSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpiperesetsynchronously)), to a device after the driver has called **WdfIoTargetPurge**.

When a driver calls **WdfIoTargetPurge**, the framework does not attempt to cancel or wait for I/O requests that were previously sent to the target using either the **WDF_REQUEST_SEND_OPTION_IGNORE_TARGET_STATE** flag or the **WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET** flag in the request's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure.

After a driver has purged an I/O queue, it can restart the queue by calling [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart).

Your driver must call [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart), [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) and **WdfIoTargetPurge** synchronously. After the driver calls one of these functions, it must not call any of the others until the previous call returns.

Your driver can call **WdfIoTargetPurge** multiple times without calling [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart). For example, your driver might do the following:

1. Call **WdfIoTargetPurge** and specify an *Action* value of **WdfIoTargetPurgeIo**.
2. Determine whether the target should resume processing I/O requests.
3. If the target should resume, call [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart). Otherwise, call **WdfIoTargetPurge** again with an *Action* value of **WdfIoTargetPurgeIoAndWait**.

For more information about I/O target states, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example shows how an [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function can call **WdfIoTargetPurge**, if the driver uses a continuous reader for a USB pipe.

```cpp
NTSTATUS
MyEvtDeviceD0Exit(
    IN  WDFDEVICE Device,
    IN  WDF_POWER_DEVICE_STATE TargetState
)
{
    PDEVICE_CONTEXT  pDeviceContext;
    pDeviceContext = GetMyDeviceContext(Device);

    WdfIoTargetPurge(
                    WdfUsbTargetPipeGetIoTarget(pDeviceContext->InterruptPipe),
                    WdfIoTargetPurgeIoAndWait
                    );

    return STATUS_SUCCESS;
}
```

## See also

[WDF_IO_TARGET_PURGE_IO_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_purge_io_action)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetGetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetgetstate)

[WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart)

[WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop)