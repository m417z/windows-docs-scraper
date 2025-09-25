# EVENT_FILTER_HEADER structure

## Description

Defines the header data that must precede the filter data that is defined in the
instrumentation manifest.

## Members

### `Id`

The identifier that identifies the filter in the manifest for a schematized
filter. The **value** attribute of the **filter** element contains the
identifier.

### `Version`

The version number of the filter for a schematized filter. The **version**
attribute of the **filter** element contains the version number.

### `Reserved`

Reserved

### `InstanceId`

An identifier that identifies the session that passed the filter. ETW sets this
value; the session must set this member to zero.

Providers use this value to set the _Filter_ parameter of
[EventWriteEx](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwriteex) to
prevent the event from being written to the session if the event data does not
match the filter criteria (the provider determines the semantics of how the
filter data is used in determining whether the event is written to the session).

### `Size`

The size, in bytes, of this header and the filter data that is appended to the
end of this header.

### `NextOffset`

The offset from the beginning of this filter object to the next filter object.
The value is zero if there are no more filter blocks. ETW sets this value; the
session must set this member to zero.

## Remarks

The filter data that you pass to the provider also includes a header. The
following shows an example of how you would define a filter that contained three
integers:

```c
struct _MY_FILTER {
    EVENT_FILTER_HEADER FilterHeader;
    ULONG Int1;
    ULONG Int2;
    ULONG Int3;
} MY_FILTER, *MY_FILTER;

MY_FILTER FilterData;
```

## See also

[ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters)

[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)

[EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace)

[EnableTraceEx](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex-func)

[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2)