# IMSVidStreamBufferV2SourceEvent::BroadcastEvent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Fired when the SBE2 source filter receives any event fired through the [IBroadcastEvent](https://learn.microsoft.com/previous-versions/dd376294(v=vs.85)) interface, other than the **EVENTID_DTFilterRatingChange** event.

## Parameters

### `Guid` [in]

**BSTR** object that contains the GUID that identifies the event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBroadcastEvent](https://learn.microsoft.com/previous-versions/dd376294(v=vs.85))

[IMSVidStreamBufferV2SourceEvent](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferv2sourceevent)