# IMPEG2PIDMap::MapPID

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `MapPID` method maps one or more PIDs to the pin.

## Parameters

### `culPID` [in]

The number of elements in the *pulPID* array.

### `pulPID` [in]

Pointer to an array of size *culPID*, allocated by the caller. Each element in the array contains a PID to be mapped.

### `MediaSampleContent` [in]

Variable of type [MEDIA_SAMPLE_CONTENT](https://learn.microsoft.com/windows/desktop/DirectShow/media-sample-content) that specifies the contents of the stream.

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

There may be no more than 255 distinct PIDs mapped at any given time. This includes the PIDs that the Demux maps internally for its own use; this number varies depending on the transport stream. This limitation should not present a problem in practice, because applications will typically map no more than a dozen PIDs on any given transport stream.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMPEG2PIDMap Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdaiface/nn-bdaiface-impeg2pidmap)