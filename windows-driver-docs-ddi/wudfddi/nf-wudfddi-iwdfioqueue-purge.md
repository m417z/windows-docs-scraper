# IWDFIoQueue::Purge

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Purge** method directs the framework to reject new incoming I/O requests and to cancel all outstanding requests.

## Parameters

### `pPurgeComplete` [in, optional]

A pointer to the [IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange) interface whose method the framework calls to deliver queue state to the driver. The framework calls the method after all requests are canceled. This parameter is optional and can be **NULL**.

## Remarks

The framework cancels unprocessed requests in the queue. For requests that are delivered to the driver and marked cancelable, the framework calls [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel).

The driver should ensure that only one of the following methods is in progress at any given time:

* [IWDFIoQueue::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-stop)
* [IWDFIoQueue::Drain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drain)
* **IWDFIoQueue::Purge**

For example, if the driver previously called **Purge**, it should wait for notification from the method of the interface that the *pPurgeComplete* parameter points to before it calls either [Stop](https://learn.microsoft.com/windows-hardware/test/wpt/stop-icontrolmanager) or [Drain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drain). Violating this rule results in termination of the host process.

#### Examples

The following code example shows how to stop requests to a queue.

```
VOID
CUmdfHidFile::OnCleanupFile(
    __in IWDFFile* /* WdfFile */
    )
/*++
    This method handles the cleanup operation for the file object.
    Because the file is disabled, no new reports should be added to the ring buffer.
--*/
{
    this->Disable();

    //
    // Stop all current requests to read reports.
    //

    m_GetReportQueue->Purge(NULL);
}
```

## See also

[IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange)

[IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel)

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[IWDFIoQueue::Drain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drain)

[IWDFIoQueue::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-stop)