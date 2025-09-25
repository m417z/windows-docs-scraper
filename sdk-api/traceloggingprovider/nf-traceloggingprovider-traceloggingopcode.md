# TraceLoggingOpcode macro

## Syntax

```cpp
void TraceLoggingOpcode(
  [in]  UINT eventOpcode
);
```

## Description

[TraceLogging wrapper macro](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
that sets the opcode for the event.

## Parameters

### `eventOpcode` [in]

An 8-bit number used to mark events with special semantics. This value must be a
compile-time constant in the range 0 to 255.

The opcode will be used by trace decoders to organize and correlate events.
Globally-recognized opcode values are defined in `winmeta.h`. Most events use 0
(WINEVENT_OPCODE_INFO) to indicate that the event has no special semantics.
Opcode values 10 through 239 can be given user-defined semantics.

See [EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/evntprov/ns-evntprov-event_descriptor) for details
about the event opcode.

## Remarks

`TraceLoggingOpcode(eventOpcode)` can be used as a parameter to an invocation of
a [TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) macro to
set the event's opcode.

If no **TraceLoggingOpcode** macros are provided to a **TraceLoggingWrite**
call, the event's default opcode is 0 (WINEVENT_OPCODE_INFO). If multiple
**TraceLoggingOpcode** macros are provided, the last value is used.

Opcodes WINEVENT_OPCODE_START (1) and WINEVENT_OPCODE_STOP (2) are used to
indicate the beginning and end of ETW activities as follows:

1. Generate an activity ID that is unique within the trace, typically using
[EventActivityIdControl](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventactivityidcontrol)
or [UuidCreate](https://learn.microsoft.com/windows/win32/api/rpcdce/nf-rpcdce-uuidcreate).
2. Write a start event with opcode = START, activity ID = the generated activity
ID, and related activity ID = the parent activity ID (or NULL if no parent
activity ID).
3. Write any number of activity information events with opcode = INFO, activity
ID = the generated activity ID.
4. Write a stop event with opcode = STOP, activity ID = the generated activity
ID.

Trace decoding tools will then be able to organize these events into groups
based on their activity IDs.

## See also

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/evntprov/ns-evntprov-event_descriptor)

[EventActivityIdControl](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventactivityidcontrol)

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)