# TEI_TASK_NAME function (tdh.h)

## Description

Macro that retrieves the Trace Event Information (TEI) task name.

## Parameters

### `EventInfo` [in]

A [TRACE_EVENT_INFO structure](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-trace_event_info) that contains the event information. To get this structure, call the [TdhGetEventInformation function](https://learn.microsoft.com/windows/win32/api/tdh/nf-tdh-tdhgeteventinformation).

## Return value

The TEI task name, or NULL.

## Remarks

## See also