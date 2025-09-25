# SpbRequestComplete function

## Description

The **SpbRequestComplete** method completes an I/O request and supplies a completion status.

## Parameters

### `Request` [in]

An [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the I/O request to complete. The SPB controller driver previously received this handle through one of its registered [event callback functions](https://learn.microsoft.com/previous-versions/hh450911(v=vs.85)).

### `CompletionStatus` [in]

An NTSTATUS value that represents the completion status of the request. Valid status values include, but are not limited to, the following:

#### STATUS_SUCCESS

The I/O request completed successfully.

#### STATUS_CANCELLED

The I/O request is canceled.

#### STATUS_UNSUCCESSFUL

The driver encountered an error while processing the I/O request.

## Remarks

Your controller driver calls this method to complete an I/O request that it previously received during one of the following callbacks:

[EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other)
[EvtSpbControllerIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_read)
[EvtSpbControllerIoSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_sequence)
[EvtSpbControllerIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_write)
Call **SpbRequestComplete** instead of the [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) method to complete I/O requests received by the callback functions in the preceding list.

A bug check occurs if the caller supplies an invalid SPBREQUEST handle.

A call to **SpbRequestComplete** represents the final stage in the processing of an I/O request. When this method returns, the *Request* handle value is no longer valid.

## See also

[EvtSpbControllerIoOther](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_other)

[EvtSpbControllerIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_read)

[EvtSpbControllerIoSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_sequence)

[EvtSpbControllerIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_controller_write)

[SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)