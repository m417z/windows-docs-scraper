# TEI_MAP_NAME function (tdh.h)

## Description

Macro that retrieves the Trace Event Information (TEI) map name.

## Parameters

### `EventInfo` [in]

A [TRACE_EVENT_INFO structure](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-trace_event_info) that contains the event information. To get this structure, call the [TdhGetEventInformation function](https://learn.microsoft.com/windows/win32/api/tdh/nf-tdh-tdhgeteventinformation).

### `Property` [in]

An [EVENT_PROPERTY_INFO structure](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-event_property_info) that contains the event property information.

## Return value

The TEI map name, or NULL.

## Remarks

## See also