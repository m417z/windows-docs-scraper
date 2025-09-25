## Description

The **SeEtwWriteKMCveEvent** function is a tracing function for publishing events when an attempted security vulnerability exploit is detected in your kernel-mode drivers.

## Parameters

### `CveId` [in]

A pointer to a string mentioning the CVE-ID associated with the vulnerability for which this event is being raised. Foe more information, see [Technical Guidance for Handling the New CVE ID Syntax](https://cve.mitre.org/cve/identifiers/tech-guidance.html).

### `AdditionalDetails` [in, optional]

A pointer to a string giving additional details that the event producer may want to provide to the consumer of this event.

## Return value

**SeEtwWriteKMCveEvent** returns one of the following values:

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The driver was successfully published |
| **ERROR_INVALID_PARAMETER** | Invalid pointer to CVE-ID passed. Events can be lost for several reasons; for example, if the event rate is too high or if the event size is greater than the buffer size. In these cases, the **EventsLost** counter, a member of the [EVENT_TRACE_PROPERTIES](https://learn.microsoft.com/windows/desktop/ETW/event-trace-properties) structure for the corresponding logger, is updated with the number of events that were not recorded. |

## Remarks

The **SeEtwWriteKMCveEvent** function publishes a CVE-based event. This function should be called only in scenarios where an attempt to exploit a known, patched vulnerability is detected by the application. Ideally, this function call should be added as part of the fix (update) itself.
The default consumer for this event is EventLog-System. To enable another consumer, the provider can be added to the consumer session.

Provider GUID: 85a62a0d-7e17-485f-9d4f-749a287193a6

Source Name: Microsoft-Windows-Audit-CVE or CVE-Audit

### Examples

```cpp
NTStatus status;
UNICODE_STRING CVEID;
UNICODE_STRING EventDetails;

…

RtlInitUnicodeString(&CVEID, L"CVE-2015-0000");
RtlInitUnicodeString(&EventDetails, L"Vulnerable request with data is logged in %temp%\abc.log");

status = SeEtwWriteKMCveEvent( &CVEID, &EventDetails);

```