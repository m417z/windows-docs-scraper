# IMSVidEVREvent::OnUserEvent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows Vista or later.

The **OnUserEvent** method forwards custom events from the enhanced video renderer (EVR) filter.

## Parameters

### `lEventCode` [in]

Event code.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The purpose of this method is to forward custom events from an EVR presenter to the application through the Video Control.

1. The presenter calls [IMediaEventSink::Notify](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaeventsink-notify) on the EVR with an event code of EC_USER or higher. (This range of values is reserved for custom graph events.)
2. The EVR forwards the event to the Filter Graph Manager.
3. The Filter Graph Manager forwards the event to the Video Control.
4. The Video Control forwards the event to the application by calling **OnUserEvent**.

The dispatch identifier (dispid) of this method is **dispidUserEvent**.

## See also

[IMSVidEVREvent](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidevrevent)