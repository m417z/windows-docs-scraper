# IWDFIoRequest2::GetRequestorMode

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetRequestorMode** method indicates whether an I/O request came from a kernel-mode driver or a user-mode component (either an application or a user-mode driver).

## Return value

**GetRequestorMode** returns a [WDF_KPROCESSOR_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_kprocessor_mode)-typed value that indicates whether the current I/O request came from a kernel-mode driver or a user-mode component.

## Remarks

A UMDF-based driver can receive an I/O request from a kernel-mode driver only if the UMDF-based driver supports [kernel-mode clients](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-kernel-mode-clients-in-umdf-1-x-drivers).

If **GetRequestorMode** returns **WdfUserMode**, the driver can call [IWDFIoRequest2::IsFromUserModeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-isfromusermodedriver) to determine if the I/O request came from an application or a user-mode driver.

#### Examples

The following code example shows how an [IQueueCallbackWrite::OnWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackwrite-onwrite) callback function can determine whether an I/O request is from kernel mode or user mode. If the request is from user mode, the example determines whether the request is from an application or another user-mode driver.

```
VOID
STDMETHODCALLTYPE
  CMyQueue::OnWrite(
    __in IWDFIoQueue *pWdfQueue,
    __in IWDFIoRequest *pWdfRequest,
    __in SIZE_T BytesToWrite
    )
{
 WDF_KPROCESSOR_MODE processorMode;
    BOOL fromApp = FALSE;
    //
    // Declare an IWDFIoRequest2 interface pointer and obtain the
    // IWDFIoRequest2 interface from the IWDFIoRequest interface.
    //
    CComQIPtr<IWDFIoRequest2> r2 = pWdfRequest;

    processorMode = r2->GetRequestorMode();
    if (processorMode == WdfUserMode)
    {
        fromApp = r2->IsFromUserModeDriver();
    }
...
}
```

## See also

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)

[IWDFIoRequest2::IsFromUserModeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-isfromusermodedriver)