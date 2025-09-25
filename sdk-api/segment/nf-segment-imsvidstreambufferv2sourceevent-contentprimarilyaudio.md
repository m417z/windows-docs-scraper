# IMSVidStreamBufferV2SourceEvent::ContentPrimarilyAudio

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Fired when an SBE2 source filter receives a **STREAMBUFFER_EC_PRIMARY_AUDIO** event, which is fired through the [IMSVidStreamBufferSourceEvent3](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersourceevent3) interface, and indicates that SBE is processing primarily audio data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A STREAMBUFFER_EC_PRIMARY_AUDIO event is sent if video samples are captured at a low frame rate. This event generally occurs with audio services on a DVB stream, but it might also indicate a problem with capturing or encoding the video.

This event applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 or later.

## See also

[IMSVidStreamBufferV2SourceEvent](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferv2sourceevent)

[Stream Buffer Engine Event Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-codes)