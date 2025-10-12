# KsPinGenerateEvents function

## Description

The **KsPinGenerateEvents** function generates events of an indicated type that are present in *Pin*'s event list.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure on which to generate events.

### `EventSet` [in, optional]

A pointer to the event set GUID to match to determine which events to generate. If this parameter is **NULL**, set GUID is not taken into account for determining matching events.

### `EventId` [in]

The event ID to match to determine which events to generate.

### `DataSize` [in]

The size in bytes of the data with which to generate the data event.

### `Data` [in, optional]

A pointer to a data buffer. Specify if generating a data event.

### `CallBack` [in, optional]

A pointer to a caller-specified function that is called to determine whether a given event should be generated. If **NULL**, no callback verification is performed to determine whether an event should be generated (only *EventSet* and *EventId* are used). Prototype as follows:

```cpp
BOOLEAN CallBack
(IN PVOID Context,
    IN PKSEVENT_ENTRY EventEntry);
```

**KsPinGenerateEvents** passes the *CallBackContext* parameter unchanged as the *Context* parameter for the callback. The callback function returns **TRUE** if *EventEntry* should be generated. Otherwise, it returns **FALSE**.

### `CallBackContext` [in, optional]

A pointer to a caller-specified context that is passed to the callback function *CallBack*.

## Remarks

When calling this function, a minidriver must place *Data* and *CallBackContext* in a locked, nonpageable data segment. The *CallBack* is made at DISPATCH_LEVEL. The callback function must be in a locked segment and must be prepared to run at IRQL = DISPATCH_LEVEL. Note that there is an additional issue in DX8 *only*: *EventSet* must be in a locked data segment.

This is an inline function call to [KsGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgenerateevents), which performs the necessary typecasting. Minidrivers should usually call this version instead of directly calling **KsGenerateEvents**.

An event is generated if the following three conditions hold:

* The event is present in *Pin's *event list and *EventId* matches the event's ID.

* *EventSet* either matches the event's set GUID or is **NULL**.

* *CallBack* is either **NULL** or authorizes the match.

For more information, see [Event Handling in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/event-handling-in-avstream) and [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events).

## See also

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KsAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddevent)

[KsFilterGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergenerateevents)

[KsGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgenerateevents)