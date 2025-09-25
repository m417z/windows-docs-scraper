## Description

The **ACX_EVENT_CALLBACKS** structure identifies the driver callbacks for ACX event operations.

## Members

### `Size`

The length, in bytes, of this structure.

### `EvtAcxEventEnable`

The [EVT_ACX_EVENT_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/nc-acxevents-evt_acx_event_enable) callback.

### `EvtAcxEventDisable`

The [EVT_ACX_EVENT_DISABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/nc-acxevents-evt_acx_event_disable) callback.

### `EvtAcxEventProcessRequest`

The [EVT_ACX_OBJECT_PROCESS_EVENT_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_process_event_request) callback.

## Remarks

An ACXEVENT represents an asynchronous notification available at the driver level. Events can be added to ACXCIRCUITs, ACXSTREAMs, ACXELEMENTs and ACXPINs. Internally they are exposed as KS Events to upper layers. For more information about KS Events, see [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events).

### Example

This example shows the use of ACX_EVENT_CALLBACKS.

```cpp
    ACX_EVENT_CALLBACKS         eventCallbacks;
    ACX_EVENT_CONFIG            eventCfg;

    //
    // Add enable/disable callbacks for this element.
    //
    ACX_EVENT_CALLBACKS_INIT(&eventCallbacks);
    eventCallbacks.EvtAcxEventEnable = &TestElement::EvtEventEnableCallback;
    eventCallbacks.EvtAcxEventDisable = &TestElement::EvtEventDisableCallback;

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