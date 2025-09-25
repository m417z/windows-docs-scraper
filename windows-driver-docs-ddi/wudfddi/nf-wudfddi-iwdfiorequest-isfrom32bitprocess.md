# IWDFIoRequest::IsFrom32BitProcess

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **IsFrom32BitProcess** method determines whether a request originated from a 32-bit process.

## Return value

**IsFrom32BitProcess** returns a BOOL value that indicates whether the request originated from a 32-bit process. **TRUE** indicates the request originated from a 32-bit process. **FALSE** indicates the request did not originate from a 32-bit process.

## See also

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)