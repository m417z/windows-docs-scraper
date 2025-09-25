# IWDFIoRequest::GetInputMemory

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetInputMemory** method retrieves the memory object that represents the input buffer in an I/O request.

## Parameters

### `ppWdfMemory` [out]

A pointer to a variable that receives a pointer to the reference-counted [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface for the memory object. Note that returning **NULL** is valid; in this situation, no input memory is associated with the I/O request.

## Remarks

Drivers that use the [buffered I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) access method can call **GetInputMemory** to obtain an I/O request's input buffer.

Before a driver completes an I/O request, the driver must call the **IWDFMemory::Release** method for the memory object. The underlying memory object is freed when the request is completed.

The input buffer that is associated with the I/O request contains information (for example, data to be written to a disk) that the originator of the request supplied. The driver can call **GetInputMemory** to obtain the input buffer for a write request or a device I/O control request, but not for a read request (because read requests do not provide input data). To access the input buffer, the driver must call the [IWDFMemory::GetDataBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfmemory-getdatabuffer) method.

UMDF creates an I/O request's memory objects when it receives the I/O request, before it adds the I/O request to a driver's I/O queue. If UMDF cannot allocate memory for the memory objects, it completes the I/O request with a failure return status and does not deliver the I/O request to the driver.

For more information about accessing an I/O request's data buffers, see [Accessing Data Buffers in UMDF-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

For a code example of how to use the **GetInputMemory** method, see [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete).

## See also

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete)

[IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)

[IWDFMemory::GetDataBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfmemory-getdatabuffer)