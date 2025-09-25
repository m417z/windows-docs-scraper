# IMSVidStreamBufferV2SourceEvent::TimeHole

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Fired when the SBE2 source filter receives a **STREAMBUFFER_EC_TIMEHOLE** event, which indicates playback has reached a gap in recorded content.

## Parameters

### `StreamOffsetMS` [in]

Time of the start of the gap relative to the content start, in milliseconds.

### `SizeMS` [in]

Duration of the gap, in milliseconds.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMSVidStreamBufferV2SourceEvent](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferv2sourceevent)

[Stream Buffer Engine Event Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-codes)