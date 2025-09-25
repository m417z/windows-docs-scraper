## Description

The **AcxEventAddEventData** function adds event data to an ACXEVENT object.

## Parameters

### `Event`

The ACXEVENT object (described in [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects)).

### `EventData`

The ACXEVENTDATA ACX object.

## Remarks

An ACXEVENTDATA represents the EVENT obj from the client.

An ACXEVENT represents an asynchronous notification available at the driver level. Events can be added to ACXCIRCUITs, ACXSTREAMs, ACXELEMENTs and ACXPINs. Internally they are exposed as KS Events to upper layers. For more information about KS Events, see [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events).

### Example

This sample shows the use of AcxEventAddEventData.

```cpp
VOID
CodecR_EvtMuteElementChangeEventCallback(
    _In_        ACXOBJECT       Object,
    _In_        ACXEVENT        Event,
    _In_        ACX_EVENT_VERB  Verb,
    _In_opt_    ACXEVENTDATA    EventData,
    _In_opt_    WDFREQUEST      Request
    )
{
...
        AcxEventAddEventData(Event, EventData);
...
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxevents.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/)