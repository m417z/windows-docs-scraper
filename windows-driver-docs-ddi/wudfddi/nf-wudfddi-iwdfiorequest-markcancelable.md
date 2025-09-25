# IWDFIoRequest::MarkCancelable

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **MarkCancelable** method enables the canceling of the I/O request.

## Parameters

### `pCancelCallback` [in]

A pointer to the [IRequestCallbackCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackcancel) interface whose method the framework calls after the I/O request is canceled.

## Remarks

After a driver receives an I/O request as input to an [IQueueCallbackRead::OnRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackread-onread), [IQueueCallbackWrite::OnWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackwrite-onwrite), or [IQueueCallbackDeviceIoControl::OnDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdeviceiocontrol-ondeviceiocontrol) event callback function, the driver can call the **MarkCancelable** method to enable canceling of the request. Later, the driver can call the [IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable) method to disable canceling of the request.

Before a driver calls **MarkCancelable**, the driver must implement the [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) method.

The User Mode Driver Framework (UMDF) allows only one [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) method per queue. Therefore, when a driver calls **MarkCancelable** for requests that are associated with a particular queue to enable the framework to cancel those requests, the driver must pass a pointer to the [IRequestCallbackCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackcancel) interface for the same request-callback object. Later, to cancel each request, the framework passes a pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface for the request in a call to this request-callback object's **IRequestCallbackCancel::OnCancel** method.

The driver must call [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete), either from the [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) method or from its regular I/O completion path.

After a driver calls **MarkCancelable** to enable canceling, the request remains cancelable while the driver has possession of the request object, unless the driver calls [UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable) to disable canceling.

If the driver calls the [IWDFIoRequest::ForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-forwardtoioqueue) method to forward the request to a different queue, the following rules apply:

* Canceling of I/O requests cannot be enabled when the driver forwards the requests to a different queue.

  Typically, the driver should not call **MarkCancelable** to enable canceling a request before calling [IWDFIoRequest::ForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-forwardtoioqueue). Alternatively, the driver can make the request cancelable. However, the driver must then call [UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable) to disable canceling the request before calling **IWDFIoRequest::ForwardToIoQueue**.
* While the request is in a second queue, the framework owns it and can cancel it without notifying the driver.
* After the framework dequeues the request from the second queue and delivers the request to the driver, the driver can call **MarkCancelable** to enable canceling.

#### Examples

The following code example sets up a request so that the framework can cancel it.

```
    //
    // The QueryInteraface should not fail.
    //
    (VOID)this->QueryInterface(_uuidof(IRequestCallbackCancel),
                               (PVOID *)&cancelCallback);

    pWdfRequest->MarkCancelable(cancelCallback);
```

## See also

[IQueueCallbackDeviceIoControl::OnDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdeviceiocontrol-ondeviceiocontrol)

[IQueueCallbackRead::OnRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackread-onread)

[IQueueCallbackWrite::OnWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackwrite-onwrite)

[IRequestCallbackCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackcancel)

[IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete)

[IWDFIoRequest::ForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-forwardtoioqueue)

[IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable)