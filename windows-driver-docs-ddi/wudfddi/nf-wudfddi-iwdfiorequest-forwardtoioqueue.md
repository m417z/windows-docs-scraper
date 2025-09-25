# IWDFIoRequest::ForwardToIoQueue

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **ForwardToIoQueue** method forwards (that is, requeues) an I/O request to one of the calling driver's I/O queues.

## Parameters

### `pDestination` [in]

A pointer to the [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue) interface for the destination queue object.

## Return value

**ForwardToIoQueue** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The driver must own the I/O request and must have obtained the request from one of its I/O queues.

The source and destination queues cannot be the same. In other words, the driver cannot call **ForwardToIoQueue** to return a request to the queue that it came from. To return an I/O request to the I/O queue that it came from, the driver can call [IWDFIoRequest2::Requeue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-requeue).

Both the source and destination queues must belong to the same device.

Also, the **ForwardToIoQueue** method cannot requeue a request that the driver obtained by calling the [IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest) method.

The request cannot be cancelable. If the driver previously called the [IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable) method to make the request cancelable, the driver must call the [IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable) method before calling **ForwardToIoQueue**.

#### Examples

The following code example shows how to forward a request to another queue if the request's buffer is insufficient to hold the required information.

```
HRESULT hr;
 if (OutputBufferSizeInBytes < sizeof(SWITCH_STATE)) {
    hr = HRESULT_FROM_NT(ERROR_INSUFFICIENT_BUFFER);
 }
 else {
     hr = FxRequest->ForwardToIoQueue(
                          m_Device->GetSwitchChangeQueue()
                          );
     if (SUCCEEDED(hr)) {
         completeRequest = false;
     }
  }
```

## See also

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable)

[IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable)