# IESEvent::SetCompletionStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Sets the completion status for an event that is derived from the [IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent) interface. The device handling the event sets the completion status in the **IESEvent** object that is passed in a call to [IESEventService::FireESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieseventservice-fireesevent).

If an event originates from a PBDA device, the event object automatically calls the [IBDA_EventingService::CompleteEvent](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_eventingservice-completeevent) method with the result set in the **SetCompletionStatus** call at the time it is released. If the client is a managed application, it should dispose of the event object immediately after it is finished with the event. This disposition ensures that the **IBDA_EventingService::CompleteEvent** method is called in a timely manner

## Parameters

### `dwResult` [in]

Completion status for the event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FireESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieseventservice-fireesevent)

[IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent)