# IWDFRequestCompletionParams::GetCompletionStatus

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetCompletionStatus** method retrieves the completion status of an I/O request.

## Return value

**GetCompletionStatus** returns S_OK for a successful completion status. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## See also

[IWDFRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfrequestcompletionparams)