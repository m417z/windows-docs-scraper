# IWDFIoRequest2::RetrieveInputBuffer

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [RequestRetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputbuffer) method retrieves an I/O request's input buffer.

## Parameters

### `MinimumRequiredCb` [in]

The minimum buffer size, in bytes, that the driver needs to process the I/O request. This value can be zero if there is no minimum buffer size.

### `Buffer` [out]

A pointer to a location that receives the buffer's address.

### `BufferCb` [out, optional]

A pointer to a location that receives the buffer's size, in bytes. This parameter is optional and can be **NULL**.

## Return value

[RequestRetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputbuffer) returns S_OK if the operation succeeds. Otherwise, this method can return the following value:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The I/O request did not provide an input buffer, or the size of the input buffer is less than the minimum size that *MinimumRequiredCb* specifies. |
| **E_OUTOFMEMORY** | Not enough memory is available to retrieve the buffer. The driver should complete the request with an error status value. |

This method might return one of the other values that Winerror.h contains.

## Remarks

A request's input buffer contains information, such as data to be written to a disk, that the originator of the request supplied. Your driver can call [RequestRetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputbuffer) to obtain the input buffer for a write request or a device I/O control request, but not for a read request (because read requests do not provide input data).

The [RequestRetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputbuffer) method retrieves the input buffer for I/O requests that use the [buffered I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) or [direct I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) method for accessing data buffers.

If [RequestRetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputbuffer) returns S_OK, the driver receives the address and, optionally, the size of the input buffer.

The driver can access the retrieved buffer until it [completes](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) the I/O request.

Instead of calling [RequestRetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputbuffer), the driver can call [IWDFIoRequest2::RetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveinputmemory), which creates a framework memory object that represents the buffer.

For more information about accessing an I/O request's data buffers, see [Accessing Data Buffers in UMDF-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example shows a segment of a serial port driver's [IQueueCallbackDeviceIoControl::OnDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdeviceiocontrol-ondeviceiocontrol) callback function. From an I/O request's input buffer, the code segment obtains the baud rate that should be set for the device.

```
VOID
STDMETHODCALLTYPE
  CMyQueue::OnDeviceIoControl(
    __in IWDFIoQueue*  FxQueue,
    __in IWDFIoRequest*  FxRequest,
    __in ULONG  ControlCode,
    __in SIZE_T  InputBufferCb,
    __in SIZE_T  OutputBufferCb
    )
{
    PBYTE buffer;
    SIZE_T bufferSize;
    HRESULT hr;
    //
    // Declare an IWDFIoRequest2 interface pointer and obtain the
    // IWDFIoRequest2 interface from the IWDFIoRequest interface.
    //
    CComQIPtr<IWDFIoRequest2> r2 = FxRequest;

    switch (ControlCode)
    {
        case IOCTL_SERIAL_SET_BAUD_RATE:
        {
            //
            // Obtain the baud rate from the write request's input buffer.
            //
            hr = r2->RetrieveInputBuffer(sizeof(SERIAL_BAUD_RATE),
                                         (PVOID*) &buffer,
                                         &bufferSize);
...
        }
    }
}
```

## See also

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)

[IWDFIoRequest2::RetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveinputmemory)

[IWDFIoRequest2::RetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveoutputbuffer)

[IWDFIoRequest2::RetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveoutputmemory)

[IWDFIoRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory)

[IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory)