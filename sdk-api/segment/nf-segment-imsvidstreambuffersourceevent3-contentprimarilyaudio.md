# IMSVidStreamBufferSourceEvent3::ContentPrimarilyAudio

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **ContentPrimarilyAudio** method is called when the Stream Buffer Engine is processing primarily audio data.

## Return value

Return S_OK or an error code.

## Remarks

This event is sent when the [MSVidStreamBufferSource](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd695136(v=vs.85)) object receives an STREAMBUFFER_EC_PRIMARY_AUDIO event from the Stream Buffer Engine. For more information, see [Stream Buffer Engine Event Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-codes).

## See also

[IMSVidStreamBufferSourceEvent3 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersourceevent3)