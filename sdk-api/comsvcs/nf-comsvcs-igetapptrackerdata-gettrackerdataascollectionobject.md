# IGetAppTrackerData::GetTrackerDataAsCollectionObject

## Description

Retrieves tracking data for all COM+ applications in the form of a collection object.

## Parameters

### `TopLevelCollection` [out]

On return, the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface for a collection of tracker data.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## Remarks

This method is primarily intended to enable applications that subscribe to the [IComTrackingInfoEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomtrackinginfoevents) event interface to add support for [IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata) with minimal changes to their code. The object returned by this method is identical to the object sent in calls to subscribers' [IComTrackingInfoEvent::OnNewTrackingInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icomtrackinginfoevents-onnewtrackinginfo) method, so that code for navigating and parsing this collection may be reused.

Applications should not expect this method to return newly updated tracking data any more frequently than the server's suggested polling interval (see [IGetAppTrackerData::GetSuggestedPollingInterval](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-igetapptrackerdata-getsuggestedpollinginterval)).

Note that the collection object returned by this method does not contain all tracking data that is available by calling the other methods. In particular, recycling details and hang monitoring configuration are not provided.

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)