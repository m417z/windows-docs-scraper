# _WDF_DEVICE_IO_BUFFER_RETRIEVAL enumeration

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_DEVICE_IO_BUFFER_RETRIEVAL** enumeration is used to specify when UMDF makes an I/O request's buffers available to the driver.

## Constants

### `WdfDeviceIoBufferRetrievalInvalid`

Reserved for system use.

### `WdfDeviceIoBufferRetrievalCopyImmediately`

UMDF makes an I/O request's buffers available to the driver (by copying them into the [UMDF driver host process](https://learn.microsoft.com/windows-hardware/drivers/wdf/umdf-driver-host-process)) as soon as UMDF receives the I/O request. For more information, see the following Remarks section.

### `WdfDeviceIoBufferRetrievalDeferred`

UMDF makes an I/O request's buffers available to the driver (by copying them into the UMDF driver host process) only when the driver attempts to access the buffers. For more information, see the following Remarks section.

### `WdfDeviceIoBufferRetrievalMaximum`

Reserved for system use.

## Remarks

The **WDF_DEVICE_IO_BUFFER_RETRIEVAL** enumeration is used as input to [IWDFDeviceInitialize2::SetIoTypePreference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize2-setiotypepreference).

In UMDF versions prior to version 1.9, UMDF always makes an I/O request's buffers available to the driver (by copying the buffers into the [UMDF driver host process](https://learn.microsoft.com/windows-hardware/drivers/wdf/umdf-driver-host-process)) as soon as UMDF receives the I/O request. [IWDFIoRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory) and [IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory) are the only object methods that drivers can call to access the buffers.

UMDF versions 1.9 and later can support either immediate or deferred retrieval of request buffers. All new drivers should enable deferred retrieval because it usually provides better driver performance than immediate retrieval. If a driver does not enable deferred retrieval, UMDF uses immediate retrieval.

To defer retrieval of buffers, your driver must call [IWDFDeviceInitialize2::SetIoTypePreference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize2-setiotypepreference) and specify the **WdfDeviceIoBufferRetrievalDeferred** value. After your driver enables deferred retrieval, it can call the following methods to access request buffers, using either the buffered or direct [access method](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers):

[IWDFIoRequest2::RetrieveInputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveinputbuffer)

[IWDFIoRequest2::RetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveinputmemory)

[IWDFIoRequest2::RetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveoutputbuffer)

[IWDFIoRequest2::RetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-retrieveoutputmemory)

A driver that enables deferred retrieval cannot use [IWDFIoRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory) and [IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory) to access the buffers.

For more information about accessing an I/O request's data buffers, see [Accessing Data Buffers in UMDF-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

## See also

[WDF_DEVICE_IO_TYPE (UMDF)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_device_io_type)