# KsFilterGenerateEvents function

## Description

The **KsFilterGenerateEvents** function generates events of an indicated type that are present in *Filter*'s event list.

## Parameters

### `Filter` [in]

A pointer to a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure on which to generate events.

### `EventSet` [in, optional]

A pointer to the event set GUID to match for determination of which events to generate. If this parameter is **NULL**, the event set GUID is not taken into account for determining matching events.

### `EventId` [in]

The event ID to match for determining which events to generate.

### `DataSize` [in]

The size of *Data* in bytes.

### `Data` [in]

A pointer to a data buffer. Specify if generating a data event.

### `CallBack` [in, optional]

A pointer to a caller-specified function that is called to determine whether a given event should be generated. If this is **NULL**, no callback verification is performed to determine whether an event should be generated (only *EventSet* and *EventId* are used). For more information, see the Remarks section below.

### `CallBackContext` [in, optional]

An optional pointer to a caller-specified context that is passed to the callback function *CallBack*. For more information, see the Remarks section below.

## Remarks

When calling this function, a minidriver must place *Data* and *CallBackContext* in a locked, nonpageable data segment. In addition, note that the *CallBack* is made at DISPATCH_LEVEL. The callback function must be in a locked segment and must be prepared to run at IRQL = DISPATCH_LEVEL. Note that there is an additional issue in DX8 *only*: *EventSet* must be in a locked data segment.

This is an inline function call to [KsGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgenerateevents) that performs the necessary typecasting. Minidrivers should usually call this version instead of directly calling **KsGenerateEvents**.

An event is generated if the following conditions hold:

* The event is present in *Filter*'s event list and *EventId* matches the event's ID

* *EventSet* either matches the event's set GUID or is **NULL**

* *CallBack* is either **NULL** or authorizes the match

*CallBack* is a caller-specified callback used for additional match determination. It is prototyped as follows:

```cpp
BOOLEAN CallBack (IN PVOID Context, IN PKSEVENT_ENTRY EventEntry);
```

AVStream passes the contents of the **KsFilterGenerateEvents** routine's parameter *CallBackContext* in this callback's *Context* parameter. *EventEntry* is a pointer to a [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure that specifies the event that would be generated. The callback function should return **TRUE** if this event should be generated.

For more information, see [Event Handling in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/event-handling-in-avstream) and [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events).

## See also

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KsAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddevent)

[KsGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgenerateevents)

[KsPinGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingenerateevents)