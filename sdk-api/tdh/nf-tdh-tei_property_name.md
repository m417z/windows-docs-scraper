# TEI_PROPERTY_NAME function (tdh.h)

## Description

Macro that retrieves the Trace Event Information (TEI) property name.

## Parameters

### `EventInfo` [in]

A [TRACE_EVENT_INFO structure](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-trace_event_info) that contains the event information. To get this structure, call the [TdhGetEventInformation function](https://learn.microsoft.com/windows/win32/api/tdh/nf-tdh-tdhgeteventinformation).

### `Property`

An [EVENT_PROPERTY_INFO structure](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-event_property_info) that contains the event property information.

## Return value

The TEI property name, or NULL.

## Remarks

## See also