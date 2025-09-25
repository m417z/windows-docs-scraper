# IWDFIoRequest2::IsFromUserModeDriver

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **IsFromUserModeDriver** method indicates whether an I/O request came from a user-mode driver or an application.

## Return value

A Boolean value that, if **TRUE**, indicates that the current I/O request is from a user-mode driver. If this value is **FALSE**, the current I/O request came from an application.

## Remarks

If your driver supports [kernel-mode clients](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-kernel-mode-clients-in-umdf-1-x-drivers), it should call **IsFromUserModeDriver** only if [IWDFIoRequest2::GetRequestorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getrequestormode) returns **WdfUserMode**.

The UMDF 2 equivalent of this method is [WdfRequestIsFromUserModeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestisfromusermodedriver).

#### Examples

For a code example that uses **IsFromUserModeDriver**, see the example at [IWDFIoRequest2::GetRequestorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getrequestormode).

## See also

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)

[IWDFIoRequest2::GetRequestorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getrequestormode)

[WdfRequestIsFromUserModeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestisfromusermodedriver)