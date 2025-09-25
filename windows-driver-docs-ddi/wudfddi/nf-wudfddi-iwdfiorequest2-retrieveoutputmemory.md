# IWDFIoRequest2::RetrieveOutputMemory

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveOutputMemory** method retrieves the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface of a framework memory object that represents an I/O request's output buffer.

## Parameters

### `Memory` [out]

The address of a location that receives a pointer to the **IWDFMemory** interface of a UMDF memory object.

## Return value

**RetrieveOutputMemory** returns S_OK if the operation succeeds. Otherwise, this method can return the following value:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32 (ERROR_INSUFFICIENT_BUFFER)** | The I/O request did not provide an input buffer. |
| **E_OUTOFMEMORY** | Not enough memory is available to retrieve the buffer. The driver should complete the request with an error status value. |

This method might return one of the other values that Winerror.h contains.

## Remarks

A request's output buffer receives information, such as data from a disk, that the driver provides to the originator of the request. Your driver can call **RetrieveOutputMemory** to obtain the output buffer for a read request or a device I/O control request, but not for a write request (because write requests do not provide output data).

The **RetrieveOutputMemory** method retrieves the output buffer for I/O requests that use the [buffered I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) or [direct I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) method for accessing data buffers.

If **RetrieveOutputMemory** returns S_OK, the driver receives a pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface of a UMDF memory object that represents the output buffer. To access the buffer, the driver must call [IWDFMemory::GetDataBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfmemory-getdatabuffer).

The driver can access the retrieved framework memory object until it [completes](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) the I/O request. Before the driver completes the I/O request, it must call **IWDFMemory::Release**.

Instead of calling **RetrieveOutputMemory**, the driver can call [IWDFIoRequest2::RetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveoutputbuffer), which retrieves the buffer's address and length.

For more information about accessing an I/O request's data buffers, see [Accessing Data Buffers in UMDF-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example shows how an [IQueueCallbackRead::OnRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackread-onread) callback function can obtain the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface of the framework memory object that represents a read request's output buffer. The example then formats and sends the read request to a USB I/O target.

```
VOID
STDMETHODCALLTYPE
  CMyQueue::OnRead(
     __in IWDFIoQueue *pWdfQueue,
     __in IWDFIoRequest *pWdfRequest,
     __in SIZE_T BytesToRead
     )
{
    HRESULT hr = S_OK;
    IWDFMemory * pOutputMemory = NULL;

    //
    // Declare an IWDFIoRequest2 interface pointer and obtain the
    // IWDFIoRequest2 interface from the IWDFIoRequest interface.
    //
    CComQIPtr<IWDFIoRequest2> r2 = pWdfRequest;

    r2->RetrieveOutputMemory(&pOutputMemory);
    if (FAILED(hr)) goto Exit;

    hr = m_Device->GetInputPipe()->FormatRequestForRead(pWdfRequest,
                                                        NULL,
                                                        pOutputMemory,
                                                        NULL,
                                                        NULL);
Exit:
    if (FAILED(hr))
    {
        pWdfRequest->Complete(hr);
    }
    else
    {
        ForwardFormattedRequest(pWdfRequest, m_Device->GetInputPipe());
    }
    SAFE_RELEASE(pOutputMemory);
    return;
}
```

## See also

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)

[IWDFIoRequest2::RetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveinputbuffer)

[IWDFIoRequest2::RetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveinputmemory)

[IWDFIoRequest2::RetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveoutputbuffer)

[IWDFIoRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory)

[IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory)