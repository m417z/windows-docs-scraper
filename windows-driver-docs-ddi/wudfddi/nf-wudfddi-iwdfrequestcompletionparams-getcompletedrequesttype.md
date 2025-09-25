# IWDFRequestCompletionParams::GetCompletedRequestType

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetCompletedRequestType** method retrieves the type of operation that the request to be completed contains.

## Return value

**GetCompletedRequestType** returns a [WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type)-typed value that identifies the request type and why the request was sent to the driver.

## See also

[IWDFRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfrequestcompletionparams)

[WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type)