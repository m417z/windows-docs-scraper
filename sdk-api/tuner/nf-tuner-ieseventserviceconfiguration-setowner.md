# IESEventServiceConfiguration::SetOwner

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Adds an owner to an event service, where *event service* refers to a generic Windows event service that implements the [IESEventService](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventservice) interface. The owner is the [IESEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevents) object that the parent event service uses to pass advise events to its child event service for handling.

## Parameters

### `pESEvents` [in]

Pointer to the [IESEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevents) interface that the parent event service uses to advise its child.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESEventServiceConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventserviceconfiguration)

[IESEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevents)

[SetParent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ieseventserviceconfiguration-setparent)