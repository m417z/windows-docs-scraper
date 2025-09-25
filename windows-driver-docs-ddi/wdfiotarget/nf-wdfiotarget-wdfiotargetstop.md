# WdfIoTargetStop function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetStop** method stops sending queued requests to a local or remote I/O target.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate), or from a method that a specialized I/O target supplies.

### `Action` [in]

A [WDF_IO_TARGET_SENT_IO_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_sent_io_action)-typed value that specifies how the framework should handle I/O requests that the driver has sent to the I/O target, if the target has not completed the requests.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If your driver can detect recoverable device errors, you might want your driver to call **WdfIoTargetStop** to temporarily stop sending requests, then later call [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart) to resume sending requests.

While stopped, an I/O target continues to accept new requests but does not deliver the queued requests to the appropriate driver.

For more information about possible states for I/O targets, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

If a driver calls [WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader) to configure a continuous reader for a USB pipe, the driver's [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function must call **WdfIoTargetStop** to stop the reader.

If a driver has called **WdfIoTargetStop**, it can still send a request to the target by setting the **WDF_REQUEST_OPTION_IGNORE_TARGET_STATE** flag in the request's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure. If a driver sets this flag, the driver can send a request, such as a request to reset a USB pipe (see [WdfUsbTargetPipeResetSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpiperesetsynchronously)), to a device after the driver has called **WdfIoTargetStop**.

When a driver calls **WdfIoTargetStop**, the framework does not attempt to cancel or wait for I/O requests that were previously sent to the target using either the **WDF_REQUEST_SEND_OPTION_IGNORE_TARGET_STATE** flag or the **WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET** flag in the request's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure.

Your driver must call [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart) and **WdfIoTargetStop** synchronously. After the driver calls one of these functions, it must not call either function before the first call returns.

Your driver can call **WdfIoTargetStop** multiple times from a single thread without calling [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart). For example, your driver might do the following:

1. Call **WdfIoTargetStop** and specify an *Action* value of **WdfIoTargetLeaveSentIoPending**.
2. Determine whether the target should resume processing I/O requests.
3. If the target should resume, call [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart). Otherwise, call **WdfIoTargetStop** again with an *Action* value of **WdfIoTargetCancelSentIo**.

**Note** **WdfIoTargetStop** is not thread safe. It is not safe to call **WdfIoTargetStop** simultaneously from different threads.

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

If the driver has called [WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader) for the pipe, **WdfIoTargetStop** must be called at IRQL = PASSIVE_LEVEL.

If the driver has not called [WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader) and if the *Action* parameter of **WdfIoTargetStop** is **WdfIoTargetLeaveSentIoPending**, **WdfIoTargetStop** can be called at IRQL <= DISPATCH_LEVEL. Otherwise, **WdfIoTargetStop** is called at IRQL = PASSIVE_LEVEL.

#### Examples

The following code example shows how an [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function can call **WdfIoTargetStop**, if the driver uses a continuous reader for a USB pipe.

```cpp
NTSTATUS
MyEvtDeviceD0Exit(
    IN  WDFDEVICE Device,
    IN  WDF_POWER_DEVICE_STATE TargetState
)
{
    PDEVICE_CONTEXT  pDeviceContext;
    pDeviceContext = GetMyDeviceContext(Device);

    WdfIoTargetStop(
                    WdfUsbTargetPipeGetIoTarget(pDeviceContext->InterruptPipe),
                    WdfIoTargetCancelSentIo
                    );

    return STATUS_SUCCESS;
}
```

## See also

[EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit)

[WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart)

[WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader)

[WdfUsbTargetPipeResetSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpiperesetsynchronously)