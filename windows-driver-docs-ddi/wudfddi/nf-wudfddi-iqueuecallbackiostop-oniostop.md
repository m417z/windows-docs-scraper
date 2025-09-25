# IQueueCallbackIoStop::OnIoStop

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnIoStop** callback function stops the processing of the specified I/O request from the specified queue.

## Parameters

### `pWdfQueue` [in]

A pointer to the [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue) interface for the I/O queue object that processing of the I/O request is stopped from.

### `pWdfRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface that represents the framework request object whose processing is stopped.

### `ActionFlags` [in]

A valid bitwise OR of [WDF_REQUEST_STOP_ACTION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_request_stop_action_flags)-typed values that identifies the state of a stop action request.

## Remarks

A driver registers the [IQueueCallbackIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackiostop) interface when the driver calls the [IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue) method to create an I/O queue or to configure the default I/O queue.

If a driver registers an **OnIoStop** callback function for an I/O queue, the framework calls it when the queue's underlying device is leaving its working (D0) state. The framework calls the **OnIoStop** callback function for every I/O request that the driver has not completed, including requests that the driver owns and those that it has forwarded to an I/O target.

The **OnIoStop** callback function must complete, cancel, or postpone further processing of the I/O request. You must use the following rules:

If the driver owns the I/O request, it must call [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) to complete or cancel the request, or it must postpone further processing of the request and then call [IWDFIoRequest2::StopAcknowledge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-stopacknowledge).

If the driver has forwarded the I/O request to an I/O target, it must call [IWDFIoRequest::CancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-cancelsentrequest) to attempt to cancel the request, or it must postpone further processing of the request and then call [StopAcknowledge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-stopacknowledge).

If the **WdfRequestStopRequestCancelable** flag is set in the *ActionFlags* parameter, the driver must call [IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable) before calling [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) to complete (or cancel) the request or calling [IWDFIoRequest2::StopAcknowledge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-stopacknowledge) to requeue the request.

## See also

[IQueueCallbackIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackiostop)

[IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue)

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest2::StopAcknowledge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-stopacknowledge)

[WDF_REQUEST_STOP_ACTION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_request_stop_action_flags)