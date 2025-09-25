# IESEvent::GetEventId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the unique identifier from an event that is derived from the [IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent) interface. The event identifier is contained in an **IESEvent** object, which ispassed in a call to [IESEventService::FireESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieseventservice-fireesevent).

## Parameters

### `pdwEventId` [out, retval]

Receives the event identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FireESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieseventservice-fireesevent)

[IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent)