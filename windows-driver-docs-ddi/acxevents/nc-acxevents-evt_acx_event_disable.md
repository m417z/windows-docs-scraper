## Description

The **EVT_ACX_EVENT_DISABLE** callback is used by the driver to disable the ACXEVENT source.

## Parameters

### `Event`

The ACXEVENT object (described in [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects)).

## Remarks

### Example

This sample shows the use of the EVT_ACX_EVENT_DISABLE callback.

```cpp
    //
    // Add enable/disable callbacks for this element.
    //
    ACX_EVENT_CALLBACKS_INIT(&eventCallbacks);
    eventCallbacks.EvtAcxEventEnable = &TestElement::EvtEventEnableCallback;
    eventCallbacks.EvtAcxEventDisable = &TestElement::EvtEventDisableCallback;

    ACX_EVENT_CONFIG_INIT(&eventCfg);

NTSTATUS
TestElement::EvtEventDisableCallback(
    _In_ ACXEVENT Event
    )
{
    TEST_EVENT_CONTEXT * eventCtx;
    TestElement * This;

    PAGED_CODE();

    eventCtx = GetTestEventContext(Event);
    ASSERT(eventCtx != NULL);
    ASSERT(eventCtx->TestElement != NULL);

    This = eventCtx->TestElement;

    // Add code to disable event source.

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxevents.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/)