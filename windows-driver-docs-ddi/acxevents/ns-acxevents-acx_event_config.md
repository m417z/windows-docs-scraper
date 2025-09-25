## Description

The **ACX_EVENT_CONFIG** structure is used to configure an ACXEVENT.

## Members

### `Size`

The length, in bytes, of this structure.

### `Flags`

Bitwise OR of [ACX_PNPEVENT_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ne-acxevents-acx_pnpevent_config_flags).

### `Set`

Specifies the event set. This member is a pointer to a GUID that uniquely identifies the event set. See the list of event-set GUIDs in [Audio Drivers Event Sets](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-drivers-event-sets).

This is a KSEVENTSETID, for example KSEVENTSETID_AudioControlChange. For more information about, see [KSEVENTDATA structure (ks.h)](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata).

### `Id`

Specifies the event ID. This member identifies an event item within the event set. If the event set contains N items, valid event IDs are integers in the range 0 to N-1.

### `Type`

The event value type (operation data) is a [KSEVENTDATA structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) that specifies the notification method to use for this event.

### `Callbacks`

The [ACX_EVENT_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ns-acxevents-acx_event_callbacks) that identifies the driver callbacks for ACX event operations.

## Remarks

### Example

The example shows how ACX uses the ACX_EVENT_CONFIG structure.

```cpp
    ACX_EVENT_CONFIG            eventCfg;
    ACX_EVENT_CALLBACKS         eventCallbacks;

    //
    // Add an audio control change event to this volume element.
    //
    ACX_EVENT_CALLBACKS_INIT(&eventCallbacks);
    eventCallbacks.EvtAcxEventEnable = &AfxVolume::EvtVolumeEventEnableCallback;
    eventCallbacks.EvtAcxEventDisable = &AfxVolume::EvtVolumeEventDisableCallback;

    ACX_EVENT_CONFIG_INIT(&eventCfg);
    eventCfg.Set = &KSEVENTSETID_AudioControlChange;
    eventCfg.Id  = KSEVENT_CONTROL_CHANGE;
    eventCfg.Callbacks = &eventCallbacks;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxevents.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/)