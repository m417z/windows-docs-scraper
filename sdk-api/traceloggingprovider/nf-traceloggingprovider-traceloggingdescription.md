# TraceLoggingDescription macro

## Syntax

```cpp
void TraceLoggingDescription(
  [in]  string eventDescription
);
```

## Description

[TraceLogging wrapper macro](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
that sets the description for the event.

## Parameters

### `eventDescription` [in]

The description of the event. This value must be a string literal.

## Remarks

`TraceLoggingDescription("event description")` can be used as a parameter to an
invocation of a
[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro.

If multiple description args are provided, they are concatenated together into a
single string.

Event descriptions are stored in the
[PDB](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols). They are not available at
runtime.

## See also

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)