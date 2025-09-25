# EVENT_DESCRIPTOR structure

## Description

The **EVENT_DESCRIPTOR** structure contains information (metadata) about an ETW
event.

## Members

### `Id`

A 16-bit number used to identify manifest-based events.

For manifest-based ETW, the combination Provider.DecodeGuid + Event.Id +
Event.Version should uniquely identify an event, i.e. all events with the same
DecodeGuid, Id, and Version should have the same set of fields with no changes
in field names, field types, or field ordering.

For manifest-free ETW (i.e. TraceLogging), the Id field is usually not
meaningful and will normally be set to 0. TraceLogging events are generally
identified by their event name, not the event ID.

### `Version`

An 8-bit number used to specify the version of a manifest-based event.

The version indicates a revision to the definition of an event with a particular
Id. All events with a given Id should have similar semantics, but a change in
version can be used to indicate a minor modification of the event details, e.g.
a change to the type of a field or the addition of a new field.

### `Channel`

An 8-bit number used to enable special event processing.

- Manifest-based events normally use channel 0.
- TraceLogging-based events normally use channel 11.
- Manifest-based events with provider traits normally use channel 12.
- Other channel values may be used with Event Log events.

Channel values below 16 are reserved for use by Microsoft to enable special
treatment by the ETW runtime. Channel values 16 and above will be ignored by the
ETW runtime (treated the same as channel 0) and can be given user-defined
semantics.

### `Level`

An 8-bit number used to describe an event's severity or importance.

> [!Important]
> Event level is a primary means for filtering events. Always assign a
> meaningful (non-zero) level to every event.

Level values 0 through 5 are defined by Microsoft (see `evntrace.h` and
`winmeta.h`). Level values 6 through 15 are reserved. Level values 16 through
255 can be defined by the event provider.

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

### `Opcode`

An 8-bit number used to mark events with special semantics. This value can be
used by trace decoders to organize and correlate events. Globally-recognized
opcode values are defined in winmeta.h. Most events use INFO (0). Opcode values
10 through 239 can be given user-defined semantics.

Opcodes START (1) and STOP (2) are used to indicate the beginning and end of ETW
activities as follows:

1. Generate an activity ID that is unique within the trace, typically using
[EventActivityIdControl](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventactivityidcontrol).
1. Write a start event with opcode = START, activity ID = the generated activity
ID, and related activity ID = the parent activity ID (if any).
1. Write any number of activity information events with opcode = INFO, activity
ID = the generated activity ID.
1. Write a stop event with opcode = STOP, activity ID = the generated activity
ID.

Trace decoding tools can then organize these events into groups based on their
activity IDs.

### `Task`

A 16-bit number used to annotate an event or related group of events.

The event task code can be used for any purpose defined by the provider. The
task code 0 is the default, used to indicate that no special task code has been
assigned to the event. The ETW manifest supports assigning localized strings to
each task code. The task code might be used to group events into categories or
to simply associate a localized "task" string with each event.

### `Keyword`

A 64-bit bitmask used to indicate an event's membership in a set of event
categories.

> [!Important]
> Event keyword is a primary means for filtering events. Always assign a
> meaningful (non-zero) keyword to every event.

The top 16 bits of the keyword (bitmask 0xFFFF000000000000) are defined by
Microsoft. The low 48 bits of the keyword (bitmask 0x0000FFFFFFFFFFFF) are
defined by the event provider. For example, the event provider might define bit
0 (bitmask 0x1) to be the "I/O" category, bit 1 (bitmask 0x2) to be the "UI"
category, and bit 2 (bitmask 0x4) to be the "performance measurement" category.
In this scenario, an event might have its keyword set to 0x5, indicating that
the event is in both the "I/O" and "performance measurement" categories.

Event collection sessions can set MatchAnyKeyword and MatchAllKeyword filters,
meaning that the session will only accept events where the following expression
is true:

```C
eventDescriptor.Keyword == 0 || (
    (eventDescriptor.Keyword & session.MatchAnyKeyword) != 0 &&
    (eventDescriptor.Keyword & session.MatchAllKeyword) == session.MatchAllKeyword
)
```

Note that events with a keyword of 0 will normally bypass keyword-based
filtering.

> [!Tip]
> Starting with Windows 10 version 1507 and later, an event collection
> session can exclude events that have their keyword set to 0. To do this,
> include the `EVENT_ENABLE_PROPERTY_IGNORE_KEYWORD_0` flag in the
> `EnableProperty` field of the
> [ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-enable_trace_parameters)
> structure that is passed to
> [EnableTraceEx2](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletraceex2) when
> configuring the provider.

## Remarks

This structure is used when calling
[EventWrite](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwrite) to write the
event. You can also use it when calling
[EventEnabled](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventenabled) to
determine whether the event should be generated (i.e. to determine whether any
event listeners are interested in the event).

> [!Note]
> Most event providers will not use **EVENT_DESCRIPTOR** directly.
> Instead, most event providers are implemented using an ETW framework that
> wraps the calls to **EventRegister**, **EventWriteEx**, and
> **EventUnregister**. For example, you might
> [write an event manifest](https://learn.microsoft.com/windows/win32/etw/writing-manifest-based-events)
> and then use the
> [Message Compiler](https://learn.microsoft.com/windows/win32/wes/message-compiler--mc-exe-) to generate
> C/C++ code for the events, or you might use
> [TraceLogging](https://learn.microsoft.com/windows/win32/tracelogging/trace-logging-portal) to avoid the
> need for a manifest. For details on how the members of this structure relate
> to the instrumentation manifest, see the attributes of the
> [EventDefinitionType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-eventdefinitiontype-complextype)
> complex type.

This structure is included in the
[EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header) structure
that is returned with the event record when you consume events using
[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) with the
[EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) callback.

> [!Note]
> When processing MOF-based events, the event identity is contained in
> the **Opcode** field, not the **Id** field.

## See also

[EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header)

[EventDescCreate](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdesccreate)

[EventDescGetChannel](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetchannel)

[EventDescGetId](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetid)

[EventDescGetKeyword](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetkeyword)

[EventDescGetLevel](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetlevel)

[EventDescGetOpcode](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetopcode)

[EventDescGetTask](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgettask)

[EventDescGetVersion](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetversion)

[EventDescOrKeyword](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescorkeyword)

[EventDescSetChannel](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetchannel)

[EventDescSetId](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetid)

[EventDescSetKeyword](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetkeyword)

[EventDescSetLevel](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetlevel)

[EventDescSetOpcode](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetopcode)

[EventDescSetTask](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsettask)

[EventDescSetVersion](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetversion)

[EventDescZero](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdesczero)

[EventEnabled](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventenabled)

[EventWrite](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwrite)

[EventWriteTransfer](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwritetransfer)

[PROVIDER_EVENT_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_event_info)

[TdhEnumerateManifestProviderEvents](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumeratemanifestproviderevents)

[TdhGetManifestEventInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetmanifesteventinformation)