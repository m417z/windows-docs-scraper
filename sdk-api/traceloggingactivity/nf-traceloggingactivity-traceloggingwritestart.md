# TraceLoggingWriteStart macro

## Syntax

```cpp
void TraceLoggingWriteStart(
  [in]            TraceLoggingActivity activity,
  [in]            String name,
  [in, optional]   args
);
```

## Description

Starts an activity and logs the start event.

The activity must not have already been started.

## Parameters

### `activity` [in]

The activity to start.

### `name` [in]

The name of the event. This must be a string literal and not a variable. It
cannot have any embedded nul characters.

#### - args [in, optional]

Additional parameters added to the event. The maximum number of optional
parameters is 99. All parameters must be wrapper macros as defined in
[TraceLogging Wrapper Macros](https://learn.microsoft.com/windows/win32/tracelogging/tracelogging-wrapper-macros).

The args should not include **TraceLoggingLevel**, **TraceLoggingKeyword**, or
**TraceLoggingOpcode**. The level and keyword are set on the activity itself,
and the opcode for a start event is always "Start".

## See also

[TraceLoggingWriteStop](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/nf-traceloggingactivity-traceloggingwritestop)