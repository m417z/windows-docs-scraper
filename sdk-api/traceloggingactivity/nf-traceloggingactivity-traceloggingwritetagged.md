# TraceLoggingWriteTagged macro

## Syntax

```cpp
void TraceLoggingWriteTagged(
  [in]            TraceLoggingActivity activity,
  [in]            String name,
  [in, optional]   args
);
```

## Description

Logs an event with an associated ETW activity id.

The activity must have been started, and must not have been stopped yet.

## Parameters

### `activity` [in]

The activity that this method will use to tag the event.

### `name` [in]

The name of the event. This must be a string literal and not a variable. It
cannot have any embedded nul characters.

#### - args [in, optional]

Additional parameters added to the event. The maximum number of optional
parameters is 99. All parameters must be wrapper macros as defined in
[TraceLogging Wrapper Macros](https://learn.microsoft.com/windows/win32/tracelogging/tracelogging-wrapper-macros).

**TraceLoggingWriteTagged** does not use the activity's level or keyword – the
default level is 5 (verbose) and the default keyword is 0 (none). Unlike with
**TraceLoggingWriteStart** and **TraceLoggingWriteStop**, it is ok to use
**TraceLoggingLevel** and **TraceLoggingKeyword** as args here.