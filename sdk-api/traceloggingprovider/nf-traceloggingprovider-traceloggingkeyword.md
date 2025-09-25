# TraceLoggingKeyword macro

## Syntax

```cpp
void TraceLoggingKeyword(
  [in]  UINT64 eventKeyword
);
```

## Description

[TraceLogging wrapper macro](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
that sets the keyword for the event.

## Parameters

### `eventKeyword` [in]

A 64-bit bitmask used to indicate an event's membership in a set of event
categories. This value must be a compile-time constant.

> [!IMPORTANT]
> ProviderId, Level and Keyword are the primary means for filtering
> events. Other kinds of filtering are possible but have much higher overhead.
> Always assign a meaningful non-zero level and keyword to every event.

See [EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/evntprov/ns-evntprov-event_descriptor) for details
about the event keyword.

## Remarks

`TraceLoggingKeyword(eventKeyword)` can be used as a parameter to an invocation
of a [TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro
to set the event's keyword. Event keyword is a primary means for filtering
events. Always assign a meaningful (non-zero) keyword to every event.

If no **TraceLoggingKeyword** macros are provided to a **TraceLoggingWrite**
call, the event's default keyword is 0. If multiple **TraceLoggingKeyword**
macros are provided, the values are OR'ed together.

The top 16 bits of the keyword (bitmask 0xFFFF000000000000) are defined by
Microsoft. The low 48 bits of the keyword (bitmask 0x0000FFFFFFFFFFFF) are
defined by the event provider. For example, the event provider might define bit
0 (bitmask 0x1) to be the "I/O" category, bit 1 (bitmask 0x2) to be the "UI"
category, and bit 2 (bitmask 0x4) to be the "performance measurement" category.
In this scenario, an event might have its keyword set to 0x5, indicating that
the event is in both the "I/O" and "performance measurement" categories.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/evntprov/ns-evntprov-event_descriptor)

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)