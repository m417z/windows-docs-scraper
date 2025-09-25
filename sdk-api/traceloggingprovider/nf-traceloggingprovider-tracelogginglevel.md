# TraceLoggingLevel macro

## Syntax

```cpp
void TraceLoggingLevel(
  [in]  UINT eventLevel
);
```

## Description

[TraceLogging wrapper macro](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
that sets the level for the event.

## Parameters

### `eventLevel` [in]

An 8-bit number used to describe an event's severity or importance. This value
must be a compile-time constant in the range 0 to 255. If no
**TraceLoggingLevel** arguments are provided to a **TraceLoggingWrite** call,
the event's level will default to 5 (WINEVENT_LEVEL_VERBOSE).

> [!IMPORTANT]
> ProviderId, Level and Keyword are the primary means for filtering
> events. Other kinds of filtering are possible but have much higher overhead.
> Always assign a meaningful non-zero level and keyword to every event.

See [EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/evntprov/ns-evntprov-event_descriptor) for details
about the event level.

## Remarks

`TraceLoggingLevel(eventLevel)` can be used as a parameter to an invocation of a
[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro to set
the event's level. Event level is a primary means for filtering events. Always
assign a meaningful (non-zero) level to every event.

If no **TraceLoggingLevel** macros are provided to a **TraceLoggingWrite** call,
the event's default level is 5 (WINEVENT_LEVEL_VERBOSE). If multiple
**TraceLoggingLevel** macros are provided, the last value is used.

Level values 0 through 5 are defined by Microsoft (see `evntrace.h` and
`winmeta.h`). Level values 6 through 15 are reserved for future definition by
Microsoft. Level values 16 through 255 can be defined by the event provider.

| Value | Semantics |
| ------------------ | ----------------------------------------------------------------------------- |
| **LOG_ALWAYS** (0) | Event bypasses level-based event filtering. Events should not use this level. |
| **CRITICAL** (1) | Critical error |
| **ERROR** (2) | Error |
| **WARNING** (3) | Warning |
| **INFO** (4) | Informational |
| **VERBOSE** (5) | Verbose |

Event collection sessions can set a level filter, meaning that the session will
only accept events where `eventDescriptor.Level <= session.LevelFilter`. Note
that events with a level of 0 will bypass level-based filtering.

### Examples

```c
TraceLoggingWrite(
    g_hMyProvider,
    "MyWarningEventName",
    TraceLoggingLevel(WINEVENT_LEVEL_WARNING), // Levels defined in <winmeta.h>
    TraceLoggingKeyword(MyNetworkingKeyword), // Provider-defined keyword
    TraceLoggingHResult(errorCode, "Error"));
```

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/evntprov/ns-evntprov-event_descriptor)

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)