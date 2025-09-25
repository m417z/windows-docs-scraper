# IWDFIoRequest3::SetActivityId

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

 The
**SetActivityId** method associates an activity identifier with an I/O request.

## Parameters

### `ActivityId` [in]

A pointer to the activity identifier GUID to store in the I/O request.

## Remarks

Calling **SetActivityId** does not set an association with any previously present activity identifier. When the driver calls **SetActivityId**, any existing activity identifier is overwritten.

To set an association, retrieve the existing identifier by calling [RetrieveActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest3-retrieveactivityid) and then associate the existing identifier with the new one by calling [EventWriteTransfer](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventwritetransfer).

The framework does not clear a request's activity identifier when the driver calls [IWdfIoRequest2::Reuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-reuse).

For more information about activity identifiers, see [Using Activity Identifiers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-activity-identifiers).

The UMDF 2 equivalent of this method is [WdfRequestSetActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetactivityid).

#### Examples

For a code example that uses **SetActivityId**, see [RetrieveActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest3-retrieveactivityid).

## See also

[IWDFIoRequest3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest3)

[IWDFIoRequest3::RetrieveActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest3-retrieveactivityid)

[WdfRequestSetActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetactivityid)