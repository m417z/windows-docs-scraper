# IWDFIoRequest3::GetUserModeDriverInitiatedIo

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

 The
**GetUserModeDriverInitiatedIo** method determines whether an I/O request is marked as initiated by a UMDF driver.

## Return value

The method returns **TRUE** if the request is marked as UMDF driver-initiated and **FALSE** if the request is not marked as UMDF driver-initiated.

## Remarks

For additional information, see [SetUserModeDriverInitiatedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest3-setusermodedriverinitiatedio).

The UMDF 2 equivalent of this method is [WdfRequestGetUserModeInitiatedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetusermodedriverinitiatedio).

## See also

[IWDFIoRequest3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest3)

[SetUserModeDriverInitiatedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest3-setusermodedriverinitiatedio)