## Description

The **EVT_ACX_OBJECT_PROCESS_EVENT_REQUEST** callback is used by the driver to handle event notifications.

## Parameters

### `Object`

An ACX object associated with the request.

### `Event`

The ACXEVENT object (described in [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects)). An AcxEvent object that represents an asynchronous notification available at the driver level. Events can be added to AcxCircuits, AcxStreams, AcxElements and AcxPins. Internally they are exposed as KS events to upper layers.

### `Verb`

A verb from the [ACX_EVENT_VERB](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_event_verb) enumeration that describes the type of operation.

### `EventData`

An optional ACXEVENTDATA ACX object that provides information about the event.

### `Request`

An optional WDFREQUEST object associated with this operation.

For more information about working with WDF request objects, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects) and [wdfrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/).

## Remarks

### Example

Example usage is shown below.

```cpp

EVT_ACX_OBJECT_PROCESS_EVENT_REQUEST CodecR_EvtMuteElementChangeEventCallback;

...

VOID
CodecR_EvtMuteElementChangeEventCallback(
    _In_        ACXOBJECT       Object,
    _In_        ACXEVENT        Event,
    _In_        ACX_EVENT_VERB  Verb,
    _In_opt_    ACXEVENTDATA    EventData,
    _In_opt_    WDFREQUEST      Request
    )
{
    NTSTATUS                    status = STATUS_NOT_SUPPORTED;
    PCODEC_MUTE_ELEMENT_CONTEXT muteCtx = NULL;
    CODEC_MUTE_EVENT_CONTEXT *  muteEventCtx;

    PAGED_CODE();

    muteCtx = GetCodecMuteElementContext(Object);
    ASSERT(muteCtx);

    // for testing.
    muteEventCtx = GetCodecMuteEventContext(Event);
    ASSERT(muteEventCtx);

    //
    // Take the correct action: enable/disable.
    //
    switch (Verb)
    {
    case AcxEventVerbEnable:
        AcxEventAddEventData(Event, EventData);
        WdfTimerStart(muteEventCtx->Timer, WDF_REL_TIMEOUT_IN_MS(10));
        status = STATUS_SUCCESS;
        break;

    case AcxEventVerbBasicSupport:
        status = STATUS_SUCCESS;
        break;

    case AcxEventVerbDisable:
        ASSERT(Request == NULL);
        //
        // Verb is AcxEventVerbDisable;
        // It is ok to generate events even if no one is listening.
        // If present, ACX completes the request associated with this action.
        //
        break;

    default:
        ASSERT(FALSE);
        status = STATUS_INVALID_DEVICE_REQUEST;
        break;
    }

    if (Request != NULL)
    {
        WdfRequestComplete(Request, status);
    }
}

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)