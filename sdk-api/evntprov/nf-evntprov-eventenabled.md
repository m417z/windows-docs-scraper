# EventEnabled function

## Description

Determines whether an event provider should generate a particular event based on
the event's EVENT_DESCRIPTOR.

Returns **FALSE** if ETW can quickly determine that no session is listening for
a specified event from the given provider. Otherwise returns **TRUE**.

## Parameters

### `RegHandle` [in]

Registration handle of the provider. The handle comes from
[EventRegister](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventregister).

If _RegHandle_ is **NULL**, **EventEnabled** will return **FALSE**.

### `EventDescriptor` [in]

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
that provides information that will be used to determine whether the event is
enabled. This includes the event's Level (severity) and Keyword (categories).

## Return value

Returns **FALSE** if the provider should skip generating the event, i.e. returns
**FALSE** if ETW can quickly determine that no event collection session would
record an event from the given provider with the specified descriptor. Otherwise
returns **TRUE**, indicating that the provider should generate the event.

## Remarks

This API provides a simple way to determine whether an event is enabled (i.e.
whether any event consumer sessions are interested in receiving the event) based
on the provider handle and the event descriptor.

> [!Note]
> This API performs a conservative quick test. It is possible for this
> API to return true in certain cases where subsequent in-depth filtering would
> determine that no sessions need to record the event.

This API provides functionality similar to the functionality provided by
[EventProviderEnabled](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventproviderenabled).
When a provider has access to an event's complete
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor),
the provider should use **EventEnabled**. When a provider has access only to the
event's Level and Keyword, the provider should use **EventProviderEnabled**.

Most event providers will not call **EventEnabled** directly:

- The **EventWrite** APIs include their own **EventEnabled** test and return
immediately if the event is not enabled.
- Most ETW providers use an ETW framework (e.g. manifests or TraceLogging)
instead of directly calling **EventWrite** or **EventEnabled**. ETW frameworks
generally provide their own event-enabled API which should be used instead of
calling **EventEnabled**.
- ETW framework implementations usually check their own provider state rather
than calling **EventEnabled**.

### -details

While **EventEnabled** provides useful functionality, usually you will not need
to call it directly.

All of the **EventWrite** APIs begin by quickly checking whether the event is
enabled and returning immediately if the event is not enabled, so there is no
benefit in calling EventEnabled if it will be immediately followed by a call to
**EventWrite**.

```c
// EventEnabled is not useful here.
if (EventEnabled(provider, &descriptor))
{
    EventWrite(provider, &descriptor, dataCount, &data);
}
```

The **EventEnabled** API might be useful in a scenario where non-trivial work
should be done only if the event is enabled:

```c
// EventEnabled may be useful to avoid calling ExpensiveDataPreparation().
if (EventEnabled(provider, &descriptor))
{
    ExpensiveDataPreparation(data);
    EventWrite(provider, &descriptor, dataCount, &data);
}
```

However, most event providers do not call **EventWrite** directly. Instead, most
event providers are implemented using an ETW framework that wraps the calls to
**EventRegister**, **EventWrite**, and **EventUnregister**. These event
providers provide their own optimized systems for skipping disabled events.

If you use [Message Compiler](https://learn.microsoft.com/windows/win32/wes/message-compiler--mc-exe-)
(MC.exe) to generate code from a
[manifest](https://learn.microsoft.com/windows/win32/etw/writing-manifest-based-events), each of the
generated `EventWriteEVENT_NAME` macros includes its own optimized event
enablement test such that the macro arguments are not evaluated and EventWrite
is not invoked if the event is disabled.

```c
// This use of an MC-generated EventWrite macro is optimal. Note that the
// ExpensiveDataPreparation() function is not invoked unless the event is
// enabled.
EventWriteMY_EVENT(ExpensiveDataPreparation());
```

In addition, the MC-generated header includes `EventEnabledEVENT_NAME` macros
that support more-complicated scenarios:

```c
// Efficiently avoid calling ExpensiveDataPreparation() when event is disabled.
if (EventEnabledMY_EVENT())
{
    std::wstring s = ExpensiveDataPreparation();
    EventWriteMY_EVENT(s.size(), s.c_str());
}
```

Similarly, if using
[TraceLogging](https://learn.microsoft.com/windows/win32/tracelogging/trace-logging-portal), the
[TraceLoggingWrite](https://docs.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)
macro includes an optimized enablement test that runs before argument
evaluation. For more-complex scenarios, TraceLogging provides a
[TraceLoggingProviderEnabled](https://docs.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingproviderenabled)
function.

```c
// This use of TraceLoggingWrite is optimal. Note that the
// ExpensiveDataPreparation() function is not invoked unless the event is
// enabled.
TraceLoggingWrite(
    provider,
    "EventName",
    TraceLoggingLevel(TRACE_LEVEL_VERBOSE),
    TraceLoggingKeyword(MyEventKeyword),
    TraceLoggingValue(ExpensiveDataPreparation(), "data"));

// Efficiently avoid calling ExpensiveDataPreparation() when event is disabled.
if (TraceLoggingProviderEnabled(provider, TRACE_LEVEL_VERBOSE, MyEventKeyword))
{
    std::wstring s = ExpensiveDataPreparation();
    TraceLoggingWrite(
        provider,
        "EventName",
        TraceLoggingLevel(TRACE_LEVEL_VERBOSE),
        TraceLoggingKeyword(MyEventKeyword),
        TraceLoggingCountedWideString(s.data(), s.size(), "data"));
    }
```

ETW framework implementations do not normally call **EventEnabled** or
**EventProviderEnabled**. Instead, the framework implementation will implement a
[provider callback](https://learn.microsoft.com/windows/win32/api/evntprov/nc-evntprov-penablecallback). The callback should record
the provider's Level, MatchAnyKeyword, and MatchAllKeyword values. Then the
framework should provide its own event-enabled routine with the following logic:

```c
return
    provider.Enabled &&
    event.Level <= provider.Level &&
    (event.Keyword == 0 || (
        (event.Keyword & provider.MatchAnyKeyword) != 0 &&
        (event.Keyword & provider.MatchAllKeyword) == provider.MatchAllKeyword
    ));
```

A test like this will be more efficient than calling **EventEnabled** or
**EventProviderEnabled** because it avoids the overhead of looking up the
provider settings from the _RegHandle_ parameter. In some circumstances, the ETW
framework implementation can apply additional optimizations to further improve
performance. For example, the code generated by MC.exe for manifest-based events
performs additional calculations within the callback so that the
EventEnabledMY_EVENT test only needs to test a bit in a global variable.

## See also

[EventProviderEnabled](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventproviderenabled)

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)