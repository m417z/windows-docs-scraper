# IMSVidStreamBufferSourceEvent::TimeHole

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP Service Pack 1 or later.

The **TimeHole** method is called when playback reaches a gap in the recorded content.

## Parameters

### `StreamOffsetMS` [in]

Specifies the start of the gap, in milliseconds, relative to the content start.

### `SizeMS` [in]

Specifies the length of the gap, in milliseconds.

## Return value

Return S_OK or an error code.

## Remarks

This event corresponds to the STREAMBUFFER_EC_TIMEHOLE event in the Stream Buffer Engine. See [Stream Buffer Engine Event Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-codes).

## See also

[IMSVidStreamBufferSourceEvent Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersourceevent)