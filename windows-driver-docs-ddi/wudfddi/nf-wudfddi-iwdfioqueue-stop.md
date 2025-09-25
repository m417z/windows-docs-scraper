# IWDFIoQueue::Stop

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Stop** method prevents an I/O queue from delivering I/O requests, but the queue receives and stores new requests.

## Parameters

### `pStopComplete` [in, optional]

A pointer to the [IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange) interface whose method the framework calls after all outstanding I/O requests, if any, in the driver are completed. This parameter is optional and can be **NULL**.

## Remarks

A call to **Stop** is asynchronous and immediately returns to the driver. The driver is notified through the method of the supplied [IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange) interface after all outstanding requests in the driver complete.

The driver should ensure that only one of the following methods is in progress at any given time:

* **IWDFIoQueue::Stop**
* [IWDFIoQueue::Drain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drain)
* [IWDFIoQueue::Purge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-purge)

For example, if the driver previously called **Stop**, it should wait for notification from the method of the interface that the *pStopComplete* parameter points to before the driver calls either [Drain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drain) or [Purge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-purge). Violating this rule results in termination of the host process.

The **Stop** method enables the queue to receive new requests, even if the queue was not receiving new requests before the driver called **Stop**. For example, a driver might call [IWDFIoQueue::Drain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drain), which causes the framework to stop adding new I/O requests to the queue. The driver's subsequent call of **Stop** causes the framework to resume adding requests to the queue.

## See also

[IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange)

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[IWDFIoQueue::Drain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drain)

[IWDFIoQueue::Purge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-purge)