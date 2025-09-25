# IQueueCallbackDeviceIoControl::OnDeviceIoControl

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **OnDeviceIoControl** method is called to handle a device I/O control request when an application performs a specific operation on a device through the Microsoft Win32 **OnDeviceIoControl** function.

## Parameters

### `pWdfQueue` [in]

A pointer to the [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue) interface for the I/O queue object that the request arrives from.

### `pWdfRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface that represents the framework request object.

### `ControlCode` [in]

The driver-defined or system-defined I/O control code (IOCTL) that identifies the specific operation to be performed and that is associated with the request.

### `InputBufferSizeInBytes`

The size, in bytes, of the input buffer for the request.

### `OutputBufferSizeInBytes`

The size, in bytes, of the output buffer for the request.

## Remarks

A driver registers the [IQueueCallbackDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackdeviceiocontrol) interface when the driver calls the [IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue) method to create an I/O queue or to configure the default I/O queue.

A driver can implement a single **OnDeviceIoControl** method for all I/O queues or separate **OnDeviceIoControl** methods for each I/O queue.

The **OnDeviceIoControl** method receives every device I/O control request type from a queue. (The request type is identified by the **WdfRequestDeviceIoControl** value of the [WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type) enumeration type for the request.)

For more information about the driver's methods that are associated with queues and that the framework calls, see [I/O Queue Event Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/wdf/i-o-queue-event-callback-functions). The **OnDeviceIoControl** method must process each received device I/O control request. For more information about how UMDF drivers process I/O requests, see [Processing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/processing-i-o-requests).

The driver can call the [IWDFIoRequest::GetDeviceIoControlParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getdeviceiocontrolparameters), [IWDFIoRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory), and [IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory) methods to retrieve information about the request and the input and output buffers.

## See also

- [IQueueCallbackDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackdeviceiocontrol)
- [IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue)
- [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)
- [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)
- [WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type)