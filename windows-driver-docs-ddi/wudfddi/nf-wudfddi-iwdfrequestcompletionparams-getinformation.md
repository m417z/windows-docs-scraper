# IWDFRequestCompletionParams::GetInformation

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetInformation** method retrieves information that is associated with the completion of an I/O request.

## Return value

**GetInformation** returns information (for example, the number of bytes transferred) that is associated with the completion of the I/O request.

## See also

[IWDFRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfrequestcompletionparams)