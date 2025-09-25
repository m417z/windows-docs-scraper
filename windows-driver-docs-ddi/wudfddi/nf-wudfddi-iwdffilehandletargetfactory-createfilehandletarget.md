# IWDFFileHandleTargetFactory::CreateFileHandleTarget

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateFileHandleTarget** method creates a file-handle-based I/O target object.

## Parameters

### `hTarget` [in]

A handle to the target device. The handle must have been previously opened with the FILE_FLAG_OVERLAPPED flag. For example, FILE_FLAG_OVERLAPPED must have been specified in the *dwFlagsAndAttributes* parameter of the Microsoft Win32 **CreateFile** function.

### `ppTarget` [out]

A pointer to a location that receives a pointer to the [IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget) interface of the I/O target object.

## Return value

**CreateFileHandleTarget** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [CreateFileHandleTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdffilehandletargetfactory-createfilehandletarget) successfully created a file-handle-based I/O target object. |
| **E_OUTOFMEMORY** | [CreateFileHandleTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdffilehandletargetfactory-createfilehandletarget) encountered an allocation failure. |

**CreateFileHandleTarget** might also return other HRESULT values that are defined in Winerror.h.

## Remarks

If your driver uses a file-handle-based I/O target, the **DDInstall.WDF** section of the driver's INF file must set the **UmdfDispatcher** directive to **FileHandle**. For more information about **UmdfDispatcher**, see [Specifying WDF Directives](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-wdf-directives-in-inf-files).

After the driver creates a file-handle-based I/O target object, it can format I/O requests and send them to the I/O target. Typically, if the driver calls [IWDFIoTarget::FormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforread), [IWDFIoTarget::FormatRequestForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforwrite), or [IWDFIoTarget::FormatRequestForIoctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforioctl), the driver sets the *pFile* parameter to **NULL**. The **NULL** causes the framework to use the filename that the driver specified to **CreateFileHandleTarget**. If the driver provides a non-**NULL** *pFile* parameter, the specified file replaces the file that the driver specified to **CreateFileHandleTarget**. (Drivers can also call [IWDFIoRequest::FormatUsingCurrentType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-formatusingcurrenttype) to format an I/O request.)

When the driver calls [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) to send the I/O request to the I/O target, the driver must not set the [WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_request_send_options_flags) value in the *Flags* parameter.

The Win32 handle that the driver passes to **CreateFileHandleTarget** must remain valid for the lifetime of the file-handle-based I/O target object. (The framework does not take a reference on this target handle, so your driver must ensure that the Win32 handle remains valid.)

When the driver has finished using the [IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget) interface that **CreateFileHandleTarget** provides, it must release the **IWDFIoTarget** interface.

For more information about **CreateFileHandleTarget** and I/O targets, see [Initializing a General I/O Target in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/initializing-a-general-i-o-target-in-umdf).

#### Examples

The following code example shows how to create a file-handle-based I/O target for a named pipe. In this example, *m_FxDevice* is the interface pointer that [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) provides.

```
HRESULT hr = S_OK;
CComPtr<IWDFFileHandleTargetFactory> pFileHandleTargetFactory;
//
// Create a pipe and get the handle.
//
m_WriteHandle = CreateNamedPipe(NP_NAME,
                                PIPE_ACCESS_DUPLEX|FILE_FLAG_OVERLAPPED,
                                PIPE_TYPE_MESSAGE|PIPE_READMODE_MESSAGE|PIPE_WAIT,
                                2,
                                MAX_TRANSFER_SIZE,
                                MAX_TRANSFER_SIZE,
                                1000,
                                NULL);
if (m_WriteHandle == INVALID_HANDLE_VALUE) {
    DWORD err = GetLastError();
    hr = HRESULT_FROM_WIN32(err);
}
//
// Obtain the IWDFFileHandleTargetFactory interface
// by calling IWDFDevice::QueryInterface.
//
if (SUCCEEDED(hr)) {
    hr = m_FxDevice->QueryInterface(IID_PPV_ARGS(&pFileHandleTargetFactory));
}
//
// Create a file handle target.
//
if (SUCCEEDED(hr)) {
    hr = pFileHandleTargetFactory->CreateFileHandleTarget(m_WriteHandle,
                                                          &m_WriteTarget);
}
```

## See also

[IWDFFileHandleTargetFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffilehandletargetfactory)

[IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send)

[IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget)