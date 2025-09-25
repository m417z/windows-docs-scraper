# SpbRequestCaptureIoOtherTransferList function

## Description

The **SpbRequestCaptureIoOtherTransferList** method retrieves the [SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list) structure in the input buffer of the custom IOCTL request.

## Parameters

### `Request`

An [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the custom IOCTL request. The SPB controller driver previously received this handle through one of its registered [event callback functions](https://learn.microsoft.com/previous-versions/hh450911(v=vs.85)).

## Return value

**SpbRequestCaptureIoOtherTransferList** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error codes.

| Return value | Description |
| --- | --- |
| STATUS_INVALID_PARAMETER | The [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) parameter is invalid or the [SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list) structure in the request is formatted incorrectly. |
| STATUS_INSUFFICIENT_RESOURCES | Cannot allocate the system resources that are required for this operation. |

## Remarks

This method must be called in the context of the process in which the buffer addresses are valid. Typically, the SPB controller driver calls this method from the [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) event callback function that the driver supplies as an input parameter to the [SpbControllerSetIoOtherCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbcontrollersetioothercallback) method.

The maximum IRQL at which the SPB controller driver can call this method depends on whether the originator of the I/O request is running in user mode or in kernel mode. If the request originated from user mode, the driver must call this method at PASSIVE_LEVEL. If the request originated from kernel mode, the driver must call this method at IRQL <= DISPATCH_LEVEL. The driver can call the [WdfRequestGetRequestorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetrequestormode) method to determine the originator's mode. However, this call is typically unnecessary because the driver can rely on the SPB framework extension (SpbCx) to call the driver's [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) function at the appropriate IRQL.

#### Examples

The following code example shows how an SPB controller driver's [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) event callback function can use the **SpbRequestCaptureIoOtherTransferList** method to obtain the I/O buffer or buffers from a custom IOCTL request.

```
VOID
EvtIoInCallerContext(
    _In_  WDFDEVICE   SpbController,
    _In_  WDFREQUEST  FxRequest
    )
{
    NTSTATUS status;

    //
    // NOTE: The driver should check for custom IOCTLs that this
    // driver handles. If an IOCTL is not recognized, mark the
    // request as STATUS_NOT_SUPPORTED, and complete the request.
    //

    status = SpbRequestCaptureIoOtherTransferList((SPBREQUEST)FxRequest);

    //
    // If the preceding call fails, the driver must complete the
    // request instead of queueing the request.
    //

    if (!NT_SUCCESS(status))
    {
        goto exit;
    }

    status = WdfDeviceEnqueueRequest(SpbController, FxRequest);

    if (!NT_SUCCESS(status))
    {
        goto exit;
    }

exit:

    if (!NT_SUCCESS(status))
    {
        WdfRequestComplete(FxRequest, status);
    }
}

```

## See also

[EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context)

[SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)

[SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list)

[SpbControllerSetIoOtherCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbcontrollersetioothercallback)

[WdfRequestGetRequestorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetrequestormode)