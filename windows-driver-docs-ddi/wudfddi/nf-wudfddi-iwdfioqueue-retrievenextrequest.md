# IWDFIoQueue::RetrieveNextRequest

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveNextRequest** method retrieves the next I/O request from an I/O queue.

## Parameters

### `ppRequest` [out]

A pointer to a buffer that receives a pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface for the next request object, or receives **NULL** if the queue is empty or if the next request is not found.

## Return value

**RetrieveNextRequest** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The next I/O request was successfully retrieved from the I/O queue. |
| **HRESULT_FROM_NT (STATUS_WDF_PAUSED)** | The queue is not dispatching requests. This situation occurs if the device undergoes a power state transition and all of the queues are stopped from dispatching requests or if the driver explicitly called [IWDFIoQueue::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-stop) to stop dispatching requests. This situation can also occur if the driver attempts to remove a request from a manual queue that is power managed and that is powered down or if the queue is paused. |
| **HRESULT_FROM_WIN32 (ERROR_NO_MORE_ITEMS)** | No requests were in the queue. |
| **HRESULT_FROM_NT (STATUS_INVALID_DEVICE_STATE)** | The call was made to retrieve the request from a parallel queue. |

**RetrieveNextRequest** might also return other HRESULT values.

## Remarks

If a driver configures an I/O queue for manual dispatching of I/O requests, the driver can call the **RetrieveNextRequest** method to obtain the next request from the queue. For more information about manually dispatching I/O requests, see [Configuring Dispatch Mode for an I/O Queue](https://learn.microsoft.com/windows-hardware/drivers/wdf/configuring-dispatch-mode-for-an-i-o-queue).

If a driver configures an I/O queue for sequential dispatching of I/O requests, the driver can still call the **RetrieveNextRequest** method to obtain the next request from the queue without receiving an error. Although the framework permits the driver to call **RetrieveNextRequest** to retrieve a request from a sequential queue, the driver should only call **RetrieveNextRequest** before the driver completes the current request. Otherwise, if the driver attempts to call **RetrieveNextRequest** after the driver completes the current request, a race condition might occur. This race condition occurs between the framework's automatic dispatching of the next request from the sequential queue and the driver's call to **RetrieveNextRequest** to retrieve the next request.

#### Examples

The following code example, which is from the [umdf_fx2](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample driver, polls the queue for requests for as long as requests can be retrieved. The code first verifies if requests are associated with a specific file object.

```
VOID
CMyDevice::ServiceSwitchChangeQueue(
    __in SWITCH_STATE NewState,
    __in HRESULT CompletionStatus,
    __in_opt IWDFFile *SpecificFile
    )
{
    IWDFIoRequest *fxRequest;
    HRESULT enumHr = S_OK;
    do {
        HRESULT hr;
        //
        // Get the next request.
        //
        if (NULL != SpecificFile) {
        enumHr = m_SwitchChangeQueue->RetrieveNextRequestByFileObject(
                                        SpecificFile,
                                        &fxRequest
                                        );
        }
        else {
            enumHr = m_SwitchChangeQueue->RetrieveNextRequest(&fxRequest);
        }
        //
        // If a request was retrieved, complete it.
        //
        if (S_OK == enumHr) {
            if (S_OK == CompletionStatus) {
                IWDFMemory *fxMemory;
                //
                // Copy the result to the request buffer.
                //
                fxRequest->GetOutputMemory(&fxMemory);
                hr = fxMemory->CopyFromBuffer(0,
                                              &NewState,
                                              sizeof(SWITCH_STATE));
                                              fxMemory->Release();
            }
            else {
                 hr = CompletionStatus;
            }
            //
            // Complete the request with the copy or
            // completion status.
            //
            if (S_OK == hr) {
                fxRequest->CompleteWithInformation(hr,
                                                   sizeof(SWITCH_STATE));
            }
            else {
                fxRequest->Complete(hr);
            }
            fxRequest->Release();
        }
    }
    while (S_OK == enumHr);
}
```

## See also

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[IWDFIoQueue::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-stop)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)