# GetEventProcessorIndex function (evntcons.h)

## Description

Retrieves the Event Processor index.

## Parameters

### `EventRecord`

The [EVENT_RECORD](https://learn.microsoft.com/windows/win32/api/evntcons/ns-evntcons-event_record).

## Return value

Returns the **ProcessorIndex** or **ProcessorNumber** from the [ETW_BUFFER_CONTEXT](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-etw_buffer_context) **BufferContext** member of the provided _EventRecord_.

## Remarks

## See also