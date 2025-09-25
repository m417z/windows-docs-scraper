# IWDFIoRequest2::RetrieveInputMemory

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveInputMemory** method retrieves the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface of a framework memory object that represents an I/O request's input buffer.

## Parameters

### `Memory` [out]

The address of a location that receives a pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface of a UMDF memory object.

## Return value

**RetrieveInputMemory** returns S_OK if the operation succeeds. Otherwise, this method can return the following value:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The I/O request did not provide an output buffer. |
| **E_OUTOFMEMORY** | Not enough memory is available to retrieve the buffer. The driver should complete the request with an error status value. |

This method might return one of the other values that Winerror.h contains.

## Remarks

A request's input buffer contains information, such as data to be written to a disk, that the originator of the request supplied. Your driver can call **RetrieveInputMemory** to obtain the input buffer for a write request or a device I/O control request, but not for a read request (because read requests do not provide input data).

The **RetrieveInputMemory** method retrieves the input buffer for I/O requests that use the [buffered I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) or [direct I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) method for accessing data buffers.

If **RetrieveInputMemory** returns S_OK, the driver receives a pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface of a UMDF memory object that represents the input buffer. To access the buffer, the driver must call [IWDFMemory::GetDataBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfmemory-getdatabuffer).

The driver can access the retrieved framework memory object until it [completes](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) the I/O request. Before the driver completes the I/O request, it must call **IWDFMemory::Release**.

Instead of calling **RetrieveInputMemory**, the driver can call [IWDFIoRequest2::RetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveinputbuffer), which retrieves the buffer's address and length.

For more information about accessing an I/O request's data buffers, see [Accessing Data Buffers in UMDF-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example shows how an [IQueueCallbackWrite::OnWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackwrite-onwrite) callback function can obtain the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface of the framework memory object that represents a write request's input buffer. The example then formats and sends the write request to a USB I/O target.

```
VOID
STDMETHODCALLTYPE
  CMyQueue::OnWrite(
    __in IWDFIoQueue *pWdfQueue,
    __in IWDFIoRequest *pWdfRequest,
    __in SIZE_T BytesToWrite
    )
{
    HRESULT hr = S_OK;
    IWDFMemory * pInputMemory = NULL;
    IWDFUsbTargetPipe * pOutputPipe = m_Device->GetOutputPipe();
    //
    // Declare an IWDFIoRequest2 interface pointer and obtain the
    // IWDFIoRequest2 interface from the IWDFIoRequest interface.
    //
    CComQIPtr<IWDFIoRequest2> r2 = pWdfRequest;

    hr = r2->RetrieveInputMemory(&pInputMemory);
    if (FAILED(hr)) goto Exit;

    hr = pOutputPipe->FormatRequestForWrite(
                                           pWdfRequest,
                                           NULL, //pFile
                                           pInputMemory,
                                           NULL, //Memory offset
                                           NULL  //DeviceOffset
                                           );
Exit:
    if (FAILED(hr))
    {
        pWdfRequest->Complete(hr);
    }
    else
    {
        ForwardFormattedRequest(pWdfRequest, pOutputPipe);
    }
    SAFE_RELEASE(pInputMemory);
 return;
}
```

## See also

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)

[IWDFIoRequest2::RetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveinputbuffer)

[IWDFIoRequest2::RetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveoutputbuffer)

[IWDFIoRequest2::RetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveoutputmemory)

[IWDFIoRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory)

[IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory)