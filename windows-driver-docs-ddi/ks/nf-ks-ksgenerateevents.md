# KsGenerateEvents function

## Description

The **KsGenerateEvents** function generates events of an indicated type that are present in *Object*'s event list.

## Parameters

### `Object` [in]

The object on which to generate events. This can be an AVStream filter or pin object.

### `EventSet` [in, optional]

The event set GUID to match to determine which events to generate. If this parameter is **NULL**, set GUID is not taken into account for determining matching events.

### `EventId` [in]

The event ID to match to determine which events to generate.

### `DataSize` [in]

The size in bytes of the data with which to generate the data event.

### `Data` [in, optional]

A pointer to a data buffer to include in the event notification. If the driver does not need to convey additional information via the notification, set this optional parameter to **NULL**.

### `CallBack` [in, optional]

A pointer to a caller-specified function that is called to determine whether a given event should be generated. If this is **NULL**, no callback verification is performed to determine whether an event should be generated (only *EventSet* and *EventId* are used).

### `CallBackContext` [in, optional]

A pointer to a caller-specified context that is passed to the callback function *CallBack*.

## Remarks

When calling this function, a minidriver must place *Data* and *CallBackContext* in a locked, nonpageable data segment. In addition, note that the *CallBack* is made at DISPATCH_LEVEL. The callback function must be in a locked segment and must be prepared to run at IRQL = DISPATCH_LEVEL. Note that there is an additional issue in DX8 *only*: *EventSet* must be in a locked data segment.

Minidrivers typically do not call this function directly and instead use one of the versions that performs appropriate casting: [KsFilterGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergenerateevents) or [KsPinGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingenerateevents).

An event is generated if it is present in *Object's *event list and *EventId* matches the event's ID, *EventSet* either matches the event's set GUID or is **NULL**, and *CallBack* is either **NULL** or authorizes the match.

*CallBack* is a caller-specified callback used for additional match determination. It is prototyped as follows:

```cpp
BOOLEAN CallBack (IN PVOID Context, IN PKSEVENT_ENTRY EventEntry);
```

AVStream passes the contents of the **KsGenerateEvents** routine's parameter *CallBackContext* in this callback's *Context* parameter. *EventEntry* is a pointer to a [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure that specifies the event that would be generated. The callback function should return **TRUE** if this event should be generated.

For more information, see [Event Handling in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/event-handling-in-avstream) and [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events).

## See also

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KsAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddevent)

[KsFilterGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergenerateevents)

[KsPinGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingenerateevents)