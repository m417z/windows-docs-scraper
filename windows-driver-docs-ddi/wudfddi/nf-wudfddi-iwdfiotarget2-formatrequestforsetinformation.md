# IWDFIoTarget2::FormatRequestForSetInformation

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **FormatRequestForSetInformation** method formats an I/O request to set information about a file, but it does not send the request to an I/O target.

## Parameters

### `pRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface of the request object that represents the I/O request.

### `InformationClass` [in]

A [WDF_FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffileobject/ne-wdffileobject-_wdf_file_information_class)-typed value that specifies the type of information to set.

### `pFile` [in, optional]

A pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface of the file object that is associated with the I/O request. This parameter is required for local and remote [I/O targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets-in-umdf), and is optional (can be **NULL**) for file handle I/O targets.

### `pInformationMemory` [in, optional]

A pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface of a memory object. This object represents the input buffer, which contains driver-supplied file information that the *InformationClass* parameter specifies. This parameter is optional and can be **NULL**.

### `pInformationMemoryOffset` [in, optional]

A pointer to a [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdfmemory_offset) structure that supplies optional byte offset and length values. The framework uses these values to determine the beginning address and length, within the input buffer, for the data transfer. If this pointer is **NULL**, the data transfer begins at the beginning of the input buffer, and the transfer size is the buffer size.

## Return value

**FormatRequestForSetInformation** returns S_OK if the operation succeeds. Otherwise, the method might return the following value:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The framework was unable to allocate memory. |

This method might return one of the other values that Winerror.h contains.

## Remarks

Use the **FormatRequestForSetInformation** method, followed by the [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) method, to send requests either synchronously or asynchronously to an [I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets-in-umdf).

#### Examples

The following code example is part of an [IQueueCallbackDefaultIoHandler::OnDefaultIoHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdefaultiohandler-ondefaultiohandler) callback function. If the callback function receives a set information request, it sends the request to the device's default I/O target.

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
    IWDFMemory *pInMemory;
    WDF_FILE_INFORMATION_CLASS infoClass;

    //
    // Obtain the device, default I/O target, and file object.
    //
    pQueue->GetDevice(&pDevice);
    pDevice->GetDefaultIoTarget(&pTarget);
    pRequest->GetFileObject(&pFile);

    if (WdfRequestQueryInformation==pRequest->GetType())
    {
        //
        // Declare an IWDFIoRequest2 interface pointer and obtain the
        // IWDFIoRequest2 interface from the IWDFIoRequest interface.
        //
        CComQIPtr<IWDFIoRequest2> r2 = pRequest;

        //
        // Declare an IWDFIoTarget2 interface pointer and obtain the
        // IWDFIoTarget2 interface from the IWDFIoTarget interface.
        //
        CComQIPtr<IWDFIoTarget2> target2(pTarget);

        //
        // Get the I/O request's input buffer.
        //
        hr = pWdfRequest2->RetrieveInputMemory(&pInMemory);
        if (!SUCCEEDED(hr)) goto Error;

        //
        // Get the I/O request's parameters.
        //
        hr = pWdfRequest2->GetSetInformationParameters(&infoClass,
                                                       NULL);
        if (!SUCCEEDED(hr)) goto Error;

        //
        // Format a query information request and send it to the I/O target.
        //
        hr = target2->FormatRequestForSetInformation(pRequest,
                                                     infoClass,
                                                     pFile,
                                                     pInMemory,
                                                     NULL);
        if (!SUCCEEDED(hr)) goto Error;
        hr = pRequest->Send(pTarget,
                            WDF_REQUEST_SEND_OPTION_SYNCHRONOUS,
                            0);
    }
...
Error;
    //
    // Release objects.
    //
    SAFE_RELEASE(pDevice);
    SAFE_RELEASE(pTarget);
    SAFE_RELEASE(pFile);
    SAFE_RELEASE(pOutMemory);
}
```

## See also

[IWDFIoTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget2)

[IWDFIoTarget2::FormatRequestForQueryInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget2-formatrequestforqueryinformation)