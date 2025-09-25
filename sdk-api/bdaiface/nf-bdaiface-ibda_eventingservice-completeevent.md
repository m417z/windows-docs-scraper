# IBDA_EventingService::CompleteEvent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Notifies the media transform device (MTD) when the media sink device (MSD) completes an event.

## Parameters

### `ulEventID` [in]

The identifier of the event.

### `ulEventResult` [in]

The result code of the event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_EventingService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_eventingservice)