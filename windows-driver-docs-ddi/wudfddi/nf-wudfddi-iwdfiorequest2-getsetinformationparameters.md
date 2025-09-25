# IWDFIoRequest2::GetSetInformationParameters

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetSetInformationParameters** method retrieves parameters that are associated with a [WdfRequestSetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetinformation)-typed I/O request.

## Parameters

### `pInformationClass` [out, optional]

A pointer to a driver-allocated variable that receives a [WDF_FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffileobject/ne-wdffileobject-_wdf_file_information_class)-typed value. This pointer is optional and can be **NULL**.

### `pSizeInBytes` [out, optional]

A pointer to a driver-allocated variable that receives the size, in bytes, of the file information. This pointer is optional and can be **NULL**.

## Remarks

Your driver can call **GetSetInformationParameters** to obtain the parameters that are associated with an I/O request, if the request type is [WdfRequestSetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetinformation). The *pInformationClass* parameter identifies the type of file information that the driver should set, and the *pSizeInBytes* parameter specifies the size of the buffer that contains the information. The driver can call [IWDFIoRequest2::RetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveinputbuffer) to obtain the buffer address.

Your driver must verify that the specified buffer size is large enough to contain the file information that the driver must set.

#### Examples

The following code example is part of an [IQueueCallbackDefaultIoHandler::OnDefaultIoHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdefaultiohandler-ondefaultiohandler) callback function. If the callback function receives a set information request, it retrieves the request's parameters. If the driver supports the specified type of information, it copies the information from the request's input buffer.

```
void
CMyQueue::OnDefaultIoHandler(
    IWDFIoQueue*  pQueue,
    IWDFIoRequest*  pRequest
    )
{
    HRESULT hr;
    WDF_FILE_INFORMATION_CLASS infoClass;
    SIZE_T bufSize;
    PFILE_BASIC_INFORMATION buffer;

 if (WdfRequestQueryInformation==pRequest->GetType())
    {
        //
        // Declare an IWDFIoRequest2 interface pointer and obtain the
        // IWDFIoRequest2 interface from the IWDFIoRequest interface.
        //
        CComQIPtr<IWDFIoRequest2> r2 = pRequest;
        //
        // Get the I/O request's parameters.
        //
        r2->GetSetInformationParameters(&infoClass,
                                        &bufSize);
        //
        // This driver supports only FileBasicInformation.
        //
        if (infoClass != FileBasicInformation)
        {
            hr = HRESULT_FROM_NT(STATUS_NOT_SUPPORTED);
            goto exit;
        }
        //
        // Validate buffer size.
        //
        if (bufferCb != sizeof(FILE_BASIC_INFORMATION))
        {
            hr = HRESULT_FROM_NT(STATUS_BUFFER_TOO_SMALL);
            goto exit;
        }
        //
        // Get input buffer.
        //
 hr = r2->RetrieveInputBuffer(sizeof(FILE_BASIC_INFORMATION),
                              (PVOID*) &buffer,
                              &bufferCb);
 if (SUCCEEDED(hr))
        {
            //
            // Copy file information from input buffer.
            //
            CopyMemory(&g_FileInfo,
                       buffer,
                       sizeof(FILE_BASIC_INFORMATION));
        }
 ...
    }
...
exit:
...
}
```

## See also

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)

[IWDFIoRequest2::GetQueryInformationParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getqueryinformationparameters)