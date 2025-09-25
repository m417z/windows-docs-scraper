# _WDF_REQUEST_TYPE enumeration (wudfddi_types.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_REQUEST_TYPE** enumeration identifies the types of I/O requests that a UMDF request object can represent.

## Constants

### `WdfRequestUndefined`

The type of the request object is undefined.

### `WdfRequestCreate`

The request object represents a file creation request. The driver receives this type of request object when an application opens a device by calling the Microsoft Win32 **CreateFile** function. The framework delivers this type of request, along with a newly created file object ([IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)), to the driver's [IQueueCallbackCreate::OnCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackcreate-oncreatefile) callback function. The new file object represents the HANDLE-typed file handle that the Win32 **CreateFile** returns.

### `WdfRequestCleanup`

 The request object represents a file cleanup request. The driver receives this type of request object after an application's call to the Win32 **CloseHandle** function closes the last handle to a file object, but possibly before all of the file's outstanding I/O requests have been completed or canceled. The framework delivers this type of request to the driver's [IFileCallbackCleanup::OnCleanupFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ifilecallbackcleanup-oncleanupfile) callback function. (Also see **WdfRequestClose**.)

### `WdfRequestRead`

The request object represents a read request. This driver receives this type of I/O request when an application calls the Win32 **ReadFile** or **ReadFileEx** function. The framework delivers this type of request to the driver's [IQueueCallbackRead::OnRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackread-onread) callback function.

### `WdfRequestWrite`

The request object represents a write request. This driver receives this type of I/O request when an application calls the Win32 **WriteFile** or **WriteFileEx** function. The framework delivers this type of request to the driver's [IQueueCallbackWrite::OnWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackwrite-onwrite) callback function.

### `WdfRequestDeviceIoControl`

The request object represents a device I/O control request. This driver receives this type of I/O request when an application calls the Win32 **DeviceIoControl** function. The framework delivers this type of request to the driver's [IQueueCallbackDeviceIoControl::OnDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdeviceiocontrol-ondeviceiocontrol) callback function.

### `WdfRequestClose`

The request object represents a file close request. The driver receives this type of request object after an application's call to the Win32 **CloseHandle** function closes the last handle to a file object, and after all of the file's outstanding I/O requests have been completed or canceled. The framework delivers this type of request to the driver's [IFileCallbackClose::OnCloseFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ifilecallbackclose-onclosefile) callback function. (Also see **WdfRequestCleanup**.)

### `WdfRequestUsb`

The request object was sent to a USB port. The [IWDFRequestCompletionParams::GetCompletedRequestType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfrequestcompletionparams-getcompletedrequesttype) method can return this value.

### `WdfRequestOther`

This value is reserved for internal use only.

### `WdfRequestInternalIoctl`

This value is reserved for internal use only.

### `WdfRequestTypeNoFormat`

The request object's type has not been specified.

### `WdfRequestFlushBuffers`

The request object represents a request to flush cached buffers. The framework delivers this type of request to the driver's [IQueueCallbackDefaultIoHandler::OnDefaultIoHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdefaultiohandler-ondefaultiohandler) callback function.

### `WdfRequestQueryInformation`

The request object represents a request to obtain information about a file. The framework delivers this type of request to the driver's [IQueueCallbackDefaultIoHandler::OnDefaultIoHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdefaultiohandler-ondefaultiohandler) callback function.

### `WdfRequestSetInformation`

The request object represents a request to set information about a file. The framework delivers this type of request to the driver's [IQueueCallbackDefaultIoHandler::OnDefaultIoHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdefaultiohandler-ondefaultiohandler) callback function.

### `WdfRequestMaximum`

The maximum value for the enumeration is exceeded.

## Remarks

The **WDF_REQUEST_TYPE** enumeration is used as an input parameter of [IWDFDevice::ConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-configurerequestdispatching) and [IWDFIoQueue::ConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-configurerequestdispatching). It is also used for the return value of [IWDFIoRequest::GetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-gettype) and [IWDFRequestCompletionParams::GetCompletedRequestType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfrequestcompletionparams-getcompletedrequesttype).

For the KMDF version of this enumeration, see [WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type).

## See also

[IFileCallbackCleanup::OnCleanupFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ifilecallbackcleanup-oncleanupfile)

[IFileCallbackClose::OnCloseFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ifilecallbackclose-onclosefile)

[IQueueCallbackCreate::OnCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackcreate-oncreatefile)

[IQueueCallbackDeviceIoControl::OnDeviceIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackdeviceiocontrol-ondeviceiocontrol)

[IQueueCallbackRead::OnRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackread-onread)

[IQueueCallbackWrite::OnWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackwrite-onwrite)

[IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)