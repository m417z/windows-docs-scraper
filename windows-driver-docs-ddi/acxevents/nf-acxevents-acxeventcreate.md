## Description

The **AcxEventCreate** function creates an ACX event.

## Parameters

### `Object`

An ACXOBJECT that is described in [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) that are used to set the various object's values: cleanup and destroy callbacks, context type, and to specify its parent object.

### `Config`

An [ACX_EVENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ns-acxevents-acx_event_config) structure that defines the ACX event configuration.

### `Event`

The newly created ACXEVENT object (described in [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects)).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

An ACXEVENT represents an asynchronous notification available at the driver level. Events can be added to ACXCIRCUITs, ACXSTREAMs, ACXELEMENTs and ACXPINs. Internally they are exposed as KS Events to upper layers. For more information about KS Events, see [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events).

### Example

This example code snip, shows how ACX uses AcxEventCreate to create an audio jack change event.

```cpp
    NTSTATUS status = STATUS_SUCCESS;

    PAGED_CODE();

    ACX_EVENT_CALLBACKS         eventCallbacks;
    ACX_EVENT_CONFIG            eventCfg;
    AFX_PIN_EVENT_CONTEXT       *eventCtx;
    ACXEVENT                    jackEvent;
    WDF_OBJECT_ATTRIBUTES       attributes;

    //
    // Add jack info change event to this jack object
    //
    ACX_EVENT_CALLBACKS_INIT(&eventCallbacks);
    eventCallbacks.EvtAcxEventEnable = &AfxPin::EvtJackEventEnableCallback;
    eventCallbacks.EvtAcxEventDisable = &AfxPin::EvtJackEventDisableCallback;

    ACX_EVENT_CONFIG_INIT(&eventCfg);
    eventCfg.Set = &KSEVENTSETID_PinCapsChange;
    eventCfg.Id = KSEVENT_PINCAPS_JACKINFOCHANGE;
    eventCfg.Callbacks = &eventCallbacks;

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, AFX_PIN_EVENT_CONTEXT);
    attributes.ParentObject = GetObjectHandle();
    status = AcxEventCreate(GetObjectHandle(), &attributes, &eventCfg, &jackEvent);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxevents.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/)