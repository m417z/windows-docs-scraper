# IQueueCallbackIoCanceledOnQueue::OnIoCanceledOnQueue

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver's **OnIoCanceledOnQueue** event callback function informs the driver that an I/O request was canceled while it was in an I/O queue.

## Parameters

### `pWdfQueue` [in]

A pointer to the [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue) interface for the I/O queue that the I/O request was in when it was canceled.

### `pWdfRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface for the I/O request.

## Remarks

A driver registers an I/O queue's [IQueueCallbackIoCanceledOnQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackiocanceledonqueue) interface and **OnIoCanceledOnQueue** callback function when the driver calls the [IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue). For more information about how to register the interface, see [IQueueCallbackIoCanceledOnQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackiocanceledonqueue).

If a driver registers an **OnIoCanceledOnQueue** callback function for an I/O queue, the framework calls the callback function if a request handler receives an I/O request from an I/O queue, the driver calls [IWDFIoRequest::ForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-forwardtoioqueue) or [IWDFIoRequest2::Requeue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-requeue) to requeue the request to the I/O queue for which the **OnIoCanceledOnQueue** callback function is registered, and the associated I/O operation is subsequently canceled.

After the framework calls the **OnIoCanceledOnQueue** callback function, the driver owns the request object and, therefore, must [cancel](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests) the request.

The framework does not call the driver's **OnIoCanceledOnQueue** callback function for I/O requests that the framework has never delivered to the driver.

The framework calls an **OnIoCanceledOnQueue** callback function as soon as it determines that an I/O request has been canceled, regardless of the [dispatching method](https://learn.microsoft.com/windows-hardware/drivers/wdf/configuring-dispatch-mode-for-an-i-o-queue) that the driver has set for the I/O queue. Therefore, the framework can call an **OnIoCanceledOnQueue** callback function for a request in a queue that uses sequential dispatching, even if the driver currently owns another request from the queue.

For more information about the **OnIoCanceledOnQueue** callback function, see [Canceling I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests).

## See also

[IQueueCallbackIoCanceledOnQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackiocanceledonqueue)

[IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue)

[IWDFIoRequest::ForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-forwardtoioqueue)