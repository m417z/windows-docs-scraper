# IESEvent::GetEventType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the GUID that identifies an event that is derived from the [IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent) interface. The GUID is contained in an **IESEvent** object, which ispassed in a call to [IESEventService::FireESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieseventservice-fireesevent).

## Parameters

### `pguidEventType` [out, retval]

Pointer to the GUID that uniquely identifies the event type.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent)

[IESEventService::FireESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieseventservice-fireesevent)