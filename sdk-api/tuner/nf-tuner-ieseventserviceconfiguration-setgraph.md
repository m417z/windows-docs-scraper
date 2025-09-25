# IESEventServiceConfiguration::SetGraph

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Attaches an event service that implements the [IESEventService](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventservice) interface to a filter graph. This method allows the processing of events that support the [IESEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesevent) interface from devices in the graph.

## Parameters

### `pGraph` [in]

Pointer to the [IFilterGraph](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph) interface that is attached to the [IESEventService](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventservice) event service.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESEventService](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventservice)

[IESEventServiceConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventserviceconfiguration)

[IFilterGraph](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph)