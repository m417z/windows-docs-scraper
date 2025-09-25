# IWDFIoTarget2::FormatRequestForFlush

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **FormatRequestForFlush** method builds an I/O request for a flush operation but does not send the request to an I/O target.

## Parameters

### `pRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface of the request object that represents the I/O request.

### `pFile` [in, optional]

A pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface of the file object that is associated with the I/O request. This parameter is optional and can be **NULL**, but it is required for the default I/O target.

## Return value

**FormatRequestForFlush** returns S_OK if the operation succeeds. Otherwise, the method might return one of the following value:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The framework was unable to allocate memory. |

This method might return one of the other values that Winerror.h contains.

## Remarks

Some drivers must flush cached buffers that exist in either a lower driver or the device. For example, drivers that exist in a driver stack for a serial device or a storage device might support this operation.

Use the **FormatRequestForFlush** method, followed by the [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) method, to send flush requests either synchronously or asynchronously.

#### Examples

The following code example is part of an [IQueueCallbackDefaultIoHandler::OnDefaultIoHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdefaultiohandler-ondefaultiohandler) callback function. If the callback function receives a flush request, it sends the request to the device's default I/O target.

```
void
CMyQueue::OnDefaultIoHandler(
 IWDFIoQueue*  pQueue,
 IWDFIoRequest*  pRequest
    )
{
    HRESULT hr;
    IWDFDevice *pDevice;
    IWDFIoTarget *pTarget;
    IWDFFile *pFile;

    //
    // Obtain the device, default I/O target, and file object.
    //
    pQueue->GetDevice(&pDevice);
    pDevice->GetDefaultIoTarget(&pTarget);
    pRequest->GetFileObject(&pFile);

    if (WdfRequestFlushBuffers==pRequest->GetType())
    {
        //
        // Declare an IWDFIoTarget2 interface pointer and obtain the
        // IWDFIoTarget2 interface from the IWDFIoTarget interface.
        //
        CComQIPtr<IWDFIoTarget2> target2(pTarget);

        //
        // Format a flush request and send it to the I/O target.
        //
        hr = target2->FormatRequestForFlush(pRequest,
                                            pFile);

        if (SUCCEEDED(hr))
        {
            hr = pRequest->Send(pTarget,
                                WDF_REQUEST_SEND_OPTION_SYNCHRONOUS,
                                0);
        }
    }
...
    //
    // Release objects.
    //
    SAFE_RELEASE(pDevice);
    SAFE_RELEASE(pTarget);
    SAFE_RELEASE(pFile);
}
```

## See also

[IQueueCallbackDefaultIoHandler::OnDefaultIoHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdefaultiohandler-ondefaultiohandler)

[IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send)

[IWDFIoTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget2)