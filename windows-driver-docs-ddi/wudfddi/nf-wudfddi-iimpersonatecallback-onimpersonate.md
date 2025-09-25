# IImpersonateCallback::OnImpersonate

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnImpersonate** method handles impersonation.

## Parameters

### `Context` [in, optional]

A pointer to a context that was previously supplied in the [IWDFIoRequest::Impersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-impersonate) method. This parameter is optional and can be **NULL** if a context is not required.

## Remarks

Typically, the driver uses this callback to call a Win32 function directly. For example, if the driver must open a data file on behalf of an application that sent an I/O operation, the driver requires impersonation only to open the file handle.

To ensure that impersonation does not leak across driver callback functions or between device drivers, **OnImpersonate** should not call any framework methods.

A driver registers the [IImpersonateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iimpersonatecallback) interface when the driver calls the [IWDFIoRequest::Impersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-impersonate) method.

For more information about how UMDF and UMDF drivers handle impersonation, see [Handling Impersonation](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-client-impersonation-in-umdf-drivers).

## See also

[IImpersonateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iimpersonatecallback)

[IWDFIoRequest::Impersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-impersonate)