# IDiscMasterProgressEvents::NotifyTrackProgress

## Description

Notifies an application that a track has started or finished during the burn of an audio disc.

## Parameters

### `nCurrentTrack` [in]

Number of tracks that have been completely burned.

### `nTotalTracks` [in]

Total number of tracks that must be burned.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

The notification for zero out of *nTotalTracks* indicates the start of track 1. The notification for track N out of *nTotalTracks* indicates that track N is complete and track N+1 is beginning. Finally, the notification for *nTotalTracks* out of *nTotalTracks* indicates the last track has been written.

## See also

[IDiscMasterProgressEvents](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmasterprogressevents)