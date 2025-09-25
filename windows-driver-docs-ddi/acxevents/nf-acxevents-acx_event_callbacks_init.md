## Description

The **ACX_EVENT_CALLBACKS_INIT** function initializes a [ACX_EVENTS_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ns-acxevents-acx_event_callbacks). No inputs are used with this function.

## Parameters

### `Callbacks`

A pointer to an initialized [ACX_EVENTS_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ns-acxevents-acx_event_callbacks).

## Remarks

### Example

This example shows the use of ACX_EVENT_CALLBACKS_INIT.

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
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxevents.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/)