# TraceLoggingWriteActivity macro

## Syntax

```cpp
void TraceLoggingWriteActivity(
  [in]            TraceLoggingHProvider hProvider,
  [in]            String eventName,
  [in, optional]  const GUID* pActivityId,
  [in, optional]  const GUID* pRelatedActivityId,
  [in, optional]   args
);
```

## Description

Emits a TraceLogging event with specified activity IDs.

## Parameters

### `hProvider` [in]

The handle of the
[TraceLogging provider](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-tracelogging_define_provider)
to use for writing the event.

### `eventName` [in]

A short and unique name to use for identifying the event. This must be a string
literal and not a variable. It cannot have any embedded `'\0'` characters.

### `pActivityId` [in, optional]

The activity ID for the event, or NULL to use the default.

### `pRelatedActivityId` [in, optional]

The related activity ID for the event, or NULL for no related activity ID.

### `__VA_ARGS__` [in, optional]

Up to 99 additional parameters to configure or add fields to the event. Each
parameter must be one of the
[TraceLogging Wrapper Macros](https://learn.microsoft.com/windows/win32/tracelogging/tracelogging-wrapper-macros),
such as [TraceLoggingLevel](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-tracelogginglevel),
[TraceLoggingKeyword](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingkeyword), or
[TraceLoggingValue](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingvalue).

> [!IMPORTANT]
> ProviderId, Level and Keyword are the primary means for filtering
> events. Other kinds of filtering are possible but have much higher overhead.
> Always assign a non-zero level and keyword to every event.

## Remarks

Each invocation of the **TraceLoggingWriteActivity** macro expands to the code
necessary to write an event to ETW through the specified provider handle.

- **TraceLoggingWriteActivity** checks whether the specified provider is
registered. If the provider is not
[registered](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingregister),
  **TraceLoggingWriteActivity** does nothing.
- **TraceLoggingWriteActivity** checks whether any consumer is listening for the
event, as if by calling
[**TraceLoggingProviderEnabled**](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingproviderenabled).
If no consumer is listening for the event, **TraceLoggingWriteActivity** does
nothing.
- Otherwise, **TraceLoggingWriteActivity** evaluates the runtime expressions
specified in the arguments, saves the results, packs the necessary data into
an event, and calls
[EventWriteTransfer](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventwritetransfer) to send
the event to ETW.

The generated event will be constructed as follows:

- The event's provider ID, provider name, and provider group will come from the
_hProvider_ parameter.
- The event's name will come from the _eventName_ parameter.
- The event's activity ID will come from the _pActivityId_ parameter. If
_pActivityId_ is NULL, user-mode events will use the thread's implicit
activity ID and kernel-mode events will use GUID_NULL.
- The event's related activity ID will come from the _pRelatedActivityId_
parameter. If _pRelatedActivityId_ is NULL, the event will not have a related
activity ID.
- The event's level will come from the
[TraceLoggingLevel](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-tracelogginglevel) argument.
If no TraceLoggingLevel argument is present, the event's level will be 5
(WINEVENT_LEVEL_VERBOSE). If more than one TraceLoggingLevel argument is present,
the last argument will be used. To enable effective event filtering, always
assign a meaningful non-zero level to every event.
- The event's keyword will come from the
[TraceLoggingKeyword](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingkeyword)
argument. If no TraceLoggingKeyword argument is present, the event's keyword
will be 0 (NONE). If more than one TraceLoggingKeyword argument is present,
the values will be OR'ed together. To enable effective event filtering, always
assign a meaningful non-zero keyword to every event.
- Other event attributes may be set by arguments such as
[TraceLoggingOpcode](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingopcode),
[TraceLoggingDescription](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingdescription),
[TraceLoggingEventTag](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingeventtag), or
[TraceLoggingChannel](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingchannel).
- Event fields can be grouped using
[TraceLoggingStruct](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingstruct).
- Event fields are added by field arguments like
[TraceLoggingValue](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingvalue),
TraceLoggingInt32, TraceLoggingHResult, TraceLoggingString, etc. See
[TraceLogging Wrapper Macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)
for details.

For example:

```c
TraceLoggingWriteActivity(
    g_hProvider,
    "MyEvent1",
    &myActivityGuid,
    NULL, // no related activity ID
    TraceLoggingLevel(WINEVENT_LEVEL_WARNING), // Levels defined in <winmeta.h>
    TraceLoggingKeyword(MyNetworkingKeyword), // Provider-defined categories
    TraceLoggingHResult(hr, "NetStatus")); // Adds a "NetStatus" field.
```

An invocation of
`TraceLoggingWriteActivity(hProvider, "EventName", aid, rid, args...)` can be
thought of as expanding to code like the following:

```c
if (TraceLoggingProviderEnabled(hProvider, eventLevel, eventKeyword))
{
    static const metadata = { GetMetadataFromArgs(args...) };
    EVENT_DATA_DESCRIPTOR data[N] = { GetDataFromArgs(args...) };
    EventWriteTransfer(etwHandle, metadata.desc, aid, rid, N, data);
}
```

> [!NOTE]
> Each **TraceLoggingWriteActivity** macro automatically checks
> [**TraceLoggingProviderEnabled**](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingproviderenabled)
> so the event will only be written if a consumer is listening for events from
> the provider. As a result, it is usually unnecessary to directly call
> **TraceLoggingProviderEnabled**. Any runtime expressions in `args...` will be
> evaluated if and only if the event is enabled. Runtime expressions will not be
> evaluated more than once.

If generating complex events, you might get a compiler error indicating that the
line is too long or that the compiler is out of heap space. This occurs when the
**TraceLoggingWriteActivity** macro expands to a line longer than can be
supported by the compiler. If this happens you will need to simplify your event.

The **TraceLoggingWriteActivity** macro uses an array of
[EVENT_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/evntprov/ns-evntprov-event_data_descriptor) to
transfer data to ETW. The maximum number of descriptors accepted by ETW is 128.
Since each parameter may require the use of 0, 1, or 2 descriptors, it is
possible to hit the data descriptor limit (128) before hitting the argument
limit (99).

> [!IMPORTANT]
> Try to avoid large events. ETW is primarily designed for handling
> small events. **TraceLoggingWriteActivity** will silently drop any event that
> is too large. The event's size is based on the total of the event's headers
> (added by the ETW runtime), metadata (i.e. provider name, event name, field
> names, field types), and data (field values). If the event's total size is
> greater than 65535 or if the consumer session is using a buffer size smaller
> than the event's size, the event will not be recorded.

A call to
[**TraceLoggingWrite**](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite) is the
same as a call to **TraceLoggingWriteActivity** with NULL for the _pActivityId_
and _pRelatedActivityId_ parameters. Use **TraceLoggingWriteActivity** if you
need to specify activity IDs for an event.

See [EventWriteTransfer](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventwritetransfer) for
information about the semantics of the _ActivityId_ and _RelatedActivityId_
parameters.

See [EventActivityIdControl](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventactivityidcontrol)
for information about writing activities in ETW.

See [TraceLoggingActivity](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/) for C++ classes
that help manage TraceLogging ETW activities.

## See also

[EventActivityIdControl](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventactivityidcontrol)

[EventWriteTransfer](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventwritetransfer)

[TraceLoggingActivity](https://learn.microsoft.com/windows/win32/api/traceloggingactivity/)

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging Wrapper Macros](https://learn.microsoft.com/windows/win32/tracelogging/tracelogging-wrapper-macros)