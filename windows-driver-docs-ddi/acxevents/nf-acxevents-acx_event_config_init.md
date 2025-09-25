## Description

The **ACX_EVENT_CONFIG_INIT** function initializes an [ACX_EVENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ns-acxevents-acx_event_config) structure. No inputs are used with this function.

## Parameters

### `Config`

An initialized [ACX_EVENT_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ns-acxevents-acx_event_config) that describes the configuration of the event.

## Remarks

### Example

This example shows the use of ACX_EVENT_CONFIG_INIT.

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