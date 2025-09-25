# IMpeg2Demultiplexer::SetOutputPinMediaType

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetOutputPinMediaType` method updates the media type of the specified output pin. (DirectX 9.0 and later.)

## Parameters

### `pszPinName` [in]

The friendly name of the pin as specified when the pin was created in a call to **CreateOutputPin**.

### `pMediaType` [in]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that specifies the new media type information for the pin.

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

Pins can be reconfigured at any time with a new media type. If no connection exists, the media type is simply updated. If the pin is connected, the success or failure of the call will depend on the downstream input pin's acceptance or rejection of the specified media type.

The media type is not interpreted in any way by the Demultiplexer filter. It is used only during connection negotiation by the output pin. It has no effect on the content of the media samples. Media sample content is defined when a PID is mapped via the MEDIA_SAMPLE_CONTENT parameter in the [IMPEG2PIDMap::MapPID](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdaiface/nf-bdaiface-impeg2pidmap-mappid) method, or via the defined values in an [IMPEG2StreamIdMap::MapStreamId](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-impeg2streamidmap-mapstreamid) call.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMpeg2Demultiplexer Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-impeg2demultiplexer)