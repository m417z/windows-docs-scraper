# IBDA_UserActivityService::GetUserActivityInterval

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the interval that a Media Sink Device (MSD) in a Protected Broadcast Driver Architecture (PBDA) media graph waits before calling the [UserActivityDetected](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_useractivityservice-useractivitydetected) method after the MSD detects user activity. This interval is known as the *user activity interval*. An MSD must call this method before it calls **UserActivityDetected** for the first time, but does not need to call this method thereafter while the graph is running.

## Parameters

### `pdwActivityInterval` [out]

Gets the user activity interval, in seconds.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_UserActivityService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_useractivityservice)