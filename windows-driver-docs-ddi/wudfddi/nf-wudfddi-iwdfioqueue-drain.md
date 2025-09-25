# IWDFIoQueue::Drain

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Drain** method directs the queue to reject new incoming I/O requests and allow already-queued requests to be delivered to the driver for processing.

## Parameters

### `pDrainComplete` [in, optional]

A pointer to the [IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange) interface whose method the framework calls to deliver queue state to the driver. The framework calls the method after all requests are completed or canceled and the queue is empty. This parameter is optional and can be **NULL**.

## Remarks

A driver should ensure that only one of the following methods is in progress at any given time:

* [IWDFIoQueue::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-stop)
* **IWDFIoQueue::Drain**
* [IWDFIoQueue::Purge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-purge)

For example, if the driver previously called **Drain**, it should wait for notification from the method of the interface that the *pDrainComplete* parameter points to before the driver calls either [Stop](https://learn.microsoft.com/windows-hardware/test/wpt/stop-icontrolmanager) or [Purge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-purge). Violating this rule results in termination of the host process.

## See also

[IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange)

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[IWDFIoQueue::Purge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-purge)

[IWDFIoQueue::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-stop)