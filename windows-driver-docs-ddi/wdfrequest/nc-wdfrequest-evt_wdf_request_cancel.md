# EVT_WDF_REQUEST_CANCEL callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtRequestCancel* event callback function handles operations that must be performed when an I/O request is canceled.

## Parameters

### `Request` [in]

A handle to a framework request object that represents the I/O request that is being canceled.

## Remarks

To register an *EvtRequestCancel* callback function, the driver must call [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex).

 When the framework calls your driver's *EvtRequestCancel* callback function, if the driver can cancel the request, it must:

1. Finish or stop processing the request, along with subrequests that it might have created.
2. Call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete), specifying a status value of STATUS_CANCELLED.

For more information about this callback function, see [Canceling I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests).

## See also

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable)

[WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex)