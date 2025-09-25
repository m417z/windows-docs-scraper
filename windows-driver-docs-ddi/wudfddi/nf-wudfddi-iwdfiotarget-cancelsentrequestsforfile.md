# IWDFIoTarget::CancelSentRequestsForFile

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CancelSentRequestsForFile** method cancels all I/O requests that have been sent on behalf of the specified file object.

## Parameters

### `pFile` [in]

A pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface for the file object to cancel all I/O requests for.

## See also

[IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)

[IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget)