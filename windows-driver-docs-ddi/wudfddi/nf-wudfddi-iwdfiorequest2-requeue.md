# IWDFIoRequest2::Requeue

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Requeue** method returns an I/O request to the head of the I/O queue from which it was delivered to the driver.

## Return value

**Requeue** returns S_OK if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_OPERATION)** | This value is returned if one of the following occurs:<br><br>* The specified I/O request did not come from an I/O queue.<br>* The driver does not own the I/O request.<br>* The request is cancelable.<br>* The queue's dispatching method is not manual. |

This method might return one of the other values that Winerror.h contains.

## Remarks

A driver can call **Requeue** only if it uses the [manual dispatching method](https://learn.microsoft.com/windows-hardware/drivers/wdf/configuring-dispatch-mode-for-an-i-o-queue) for the I/O queue.

#### Examples

The following code example shows a segment of an [IQueueCallbackStateChange::OnStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackstatechange-onstatechange) callback function. The segment obtains an I/O request from the I/O and then returns the request to the queue.

```
void
CMyQueue::OnStateChange(
    __in IWDFIoQueue* pWdfQueue,
    __in WDF_IO_QUEUE_STATE
    )
{
    HRESULT hr;
    IWDFIoRequest* Request;
...
    //
    // Get the IWDFIoRequest interface of the next request.
    //
    hr = pWdfQueue->RetrieveNextRequest(&Request);
...
    //
    // Declare an IWDFIoRequest2 interface pointer and obtain the
    // IWDFIoRequest2 interface from the IWDFIoRequest interface.
    //
    CComQIPtr<IWDFIoRequest2> r2 = Request;

    //
    // Add code here to determine whether to process or requeue the request.
    //
...
    //
    // Requeue the request.
    //
    hr = r2->Requeue();
    if (FAILED(hr)) goto Error;
...
}
```

## See also

[IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest)

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)