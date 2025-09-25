# TraceLoggingEventTag macro

## Syntax

```cpp
void TraceLoggingEventTag(
  [in]  UINT eventTag
);
```

## Description

[TraceLogging wrapper macro](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
that sets the event tag for the event.

## Parameters

### `eventTag` [in]

This is a compile-time constant specifying the event tag value.

In C++, this can be any value in the range 0 through 0x0FFFFFFF.

In C, this can be any value in the range 0 through 0x0FFFA000 with the low 14
bits set to 0.

## Remarks

`TraceLoggingEventTag(eventTag)` can be used as a parameter to an invocation of
a [TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro to
set the event's tag.

The semantics of the tag are defined by the event consumer. During event
processing, the tag value can be retrieved from the
[TRACE_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-trace_event_info) Tags field.

The TraceLogging schema convention encodes tags as 28-bit field by using a chain
of up to four bytes with the upper-most bit used as a 'chain' bit (4 bytes \* 7
usable bits per byte = 28 bits). Data is encoded most-significant byte first. In
C, [TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) is
limited to a 2-byte encoding for the tag, so the low 14 bits of the tag must
be 0.

If no TraceLoggingEventTag parameters are provided for an event, no tag is
transmitted for the event and the event will have a tag of 0. If multiple
TraceLoggingEventTag parameters are provided, the tag values are OR'ed together.

## See also

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)

[TRACE_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/tdh/ns-tdh-trace_event_info)