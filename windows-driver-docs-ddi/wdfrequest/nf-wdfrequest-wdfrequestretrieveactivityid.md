# WdfRequestRetrieveActivityId function

## Description

[Applies to UMDF only]

The **WdfRequestRetrieveActivityId** method retrieves the current activity identifier associated with an I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `ActivityId` [out]

A pointer to a location to store the retrieved GUID.

## Return value

If the operation succeeds, **WdfRequestRetrieveActivityId** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_NOT_FOUND** | No activity ID is associated with the request. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Requests reflected from kernel mode have an activity identifier available only if the Kernel Trace provider is enabled or if the UMDF driver called [WdfRequestSetActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetactivityid) after receiving the request. For more information about Event Tracing for Windows (ETW), see [Event Tracing](https://learn.microsoft.com/windows/desktop/ETW/event-tracing-portal).

Requests initiated by the UMDF driver have an activity identifier available only if the UMDF driver previously called [WdfRequestSetActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetactivityid).

The framework does not clear a request's activity identifier when the driver calls [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse).

For more information about activity identifiers, see [Using Activity Identifiers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-activity-identifiers).

## See also

[WdfRequestSetActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetactivityid)