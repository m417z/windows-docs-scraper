# IESEventServiceConfiguration::RemoveGraph

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Removes an event service that implements the [IESEventService](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventservice) interface from a filter graph. This method prevents the processing of events from Protected Broadcast Driver Architecture (PBDA) devices in the graph.

## Parameters

### `pGraph` [in]

Pointer to the [IFilterGraph](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph) interface for the event service that is removed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESEventService](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventservice)

[IESEventServiceConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieseventserviceconfiguration)

[IFilterGraph](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph)