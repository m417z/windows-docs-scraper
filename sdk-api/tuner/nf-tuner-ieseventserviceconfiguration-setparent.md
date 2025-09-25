# IESEventServiceConfiguration::SetParent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Sets a parent event service for an event service that implements the [IESEventService](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventservice) interface. Once an event service has set a parent, it can receive advise events from the parent.

## Parameters

### `pEventService` [in]

Pointer to the [IESEventService](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventservice) interface for the parent event service.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESEventService](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventservice)

[IESEventServiceConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventserviceconfiguration)