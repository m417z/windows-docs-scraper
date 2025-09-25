# TraceLoggingFunction macro

## Syntax

```cpp
void TraceLoggingFunction(
  [in]            TraceLoggingHProvider providerHandle,
  [in, optional]   args
);
```

## Description

Creates a
[TraceLoggingThreadActivity](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/nl-traceloggingactivity-traceloggingthreadactivity)
named after the current function and writes a Start event for the activity. A
Stop activity will be written at the end of the current scope.

## Parameters

### `providerHandle` [in]

A provider registration handle.

#### - args [in, optional]

Additional parameters that will be used to configure the activity’s Start event.
Use
[TraceLogging Wrapper Macros](https://learn.microsoft.com/windows/win32/tracelogging/tracelogging-wrapper-macros)
to add values to the activity’s Start event or to configure the level/keyword of
the activity’s Start and Stop events. The maximum number of optional parameters
is 99. All parameters must be wrapper macros as defined in **TraceLogging
Wrapper Macros**.

## Remarks

Invoke this macro at the beginning of a function to define an activity. This
macro will then automatically create a
[TraceLoggingThreadActivity](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/nl-traceloggingactivity-traceloggingthreadactivity)
object based on the name of the function, and start logging for the activity. It
will also automatically generate and log a stop event when the function
completes.

[TraceLoggingThreadActivity](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/nl-traceloggingactivity-traceloggingthreadactivity)
object, you must ensure that no child activity will outlast the associated
function, even in error cases or edge cases.