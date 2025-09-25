# IESEvents::OnESEventReceived

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Defines a handler for an event that is derived from the [IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent) interface.
In a Protected Broadcast Driver Architecture graph, Media Sink Devices that implement the [IESEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevents) interface use this method to obtain data from Event System events that these devices receive. In this context, *Event System events* refer to event objects that that implement the **IESEvent** interface.

If an event originates from a PBDA device, the event object automatically calls the [IBDA_EventingService::CompleteEvent](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_eventingservice-completeevent) method with the result set in the [SetCompletionStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-iesevent-setcompletionstatus) call at the time it is released. If the client is a managed application, it should dispose of the event object immediately after it is finished with the event. This disposition ensures that the **IBDA_EventingService::CompleteEvent** method is called in a timely manner

This method is called from an event service thread that is initialized with multithreaded COM concurrency. The receiving object must use the multithreaded threading model or the single-threaded model with proper marshaling.

## Parameters

### `guidEventType` [in]

GUID for the type of event being handled.

### `pESEvent` [in]

Pointer to an [IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent) object that contains data from the event being handled.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent)

[IESEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevents)