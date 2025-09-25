# WdfRequestSetActivityId function

## Description

[Applies to UMDF only]

The **WdfRequestSetActivityId** method associates an activity identifier with an I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `ActivityId` [in]

A pointer to the activity identifier GUID to store in the I/O request.

## Remarks

Calling **WdfRequestSetActivityId** does not set an association with any previously present activity identifier. When the driver calls **WdfRequestSetActivityId**, any existing activity identifier is overwritten.

To set an association, retrieve the existing identifier by calling [WdfRequestRetrieveActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveactivityid) and then associate the existing identifier with the new one by calling [EventWriteTransfer](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventwritetransfer).

The framework does not clear a request's activity identifier when the driver calls [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse).

For more information about activity identifiers, see [Using Activity Identifiers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-activity-identifiers).

## See also

[WdfRequestRetrieveActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveactivityid)