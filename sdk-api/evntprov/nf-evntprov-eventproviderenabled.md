# EventProviderEnabled function

## Description

Determines whether an event provider should generate a particular event based on
the event's Level and Keyword.

Returns **FALSE** if ETW can quickly determine that no session is listening for a specified event from the given provider. Otherwise returns **TRUE**.

## Parameters

### `RegHandle` [in]

Registration handle of the provider. The handle comes from
[EventRegister](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventregister).

If _RegHandle_ is **NULL**, **EventProviderEnabled** will return **FALSE**.

### `Level` [in]

An 8-bit number used to describe an event's severity or importance. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
for more information about event level values.

### `Keyword` [in]

A 64-bit bitmask used to indicate an event's membership in a set of event
categories. See
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)
for more information about event keyword values.

## Return value

Returns **FALSE** if ETW can quickly determine that no session is listening for a specified event from the given provider. Otherwise returns **TRUE**.

## Remarks

This API provides a simple way to determine whether an event is enabled (i.e.
whether any event consumer sessions are interested in receiving the event) based
on the provider handle, the event level, and the event keyword.

> [!Note]
> This API performs a conservative quick test. It is possible for this
> API to return true in certain cases where subsequent in-depth filtering would
> determine that no sessions need to record the event.

This API provides functionality similar to the functionality provided by
[EventEnabled](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventenabled). When a
provider has access to an event's complete
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor),
the provider should use **EventEnabled**. When a provider has access only to the
event's Level and Keyword, the provider should use **EventProviderEnabled**.

Most event providers will not call **EventProviderEnabled** directly:

- The **EventWrite** APIs include their own **EventProviderEnabled** test and
return immediately if the event is not enabled.
- Most ETW providers use an ETW framework (e.g. manifests or TraceLogging)
instead of directly calling **EventWrite** or **EventProviderEnabled**. ETW
frameworks generally provide their own event-enabled API which should be used
instead of calling **EventProviderEnabled**.
- ETW framework implementations usually check their own provider state rather
than calling **EventProviderEnabled**.

For additional details, see
[EventEnabled](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventenabled).

## See also

[EventEnabled](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventenabled)

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)