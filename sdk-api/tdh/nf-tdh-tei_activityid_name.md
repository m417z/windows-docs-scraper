# TEI_ACTIVITYID_NAME function (tdh.h)

## Description

Macro that retrieves the Trace Event Information (TEI) activity ID name.

## Parameters

### `EventInfo` [in]

A [TRACE_EVENT_INFO structure](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-trace_event_info) that contains the event information. To get this structure, call the [TdhGetEventInformation function](https://learn.microsoft.com/windows/win32/api/tdh/nf-tdh-tdhgeteventinformation).

## Return value

The TEI activity ID name, or NULL.

## Remarks

## See also