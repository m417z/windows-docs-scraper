# IMediaObject::SetInputMaxLatency

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetInputMaxLatency` method sets the maximum latency on a specified input stream. For the definition of maximum latency, see [IMediaObject::GetInputMaxLatency](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getinputmaxlatency).

## Parameters

### `dwInputStreamIndex`

Zero-based index of an input stream on the DMO.

### `rtMaxLatency`

Maximum latency.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index |
| **E_FAIL** | Failure |
| **E_NOTIMPL** | Not implemented |
| **S_OK** | Success |

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)

[IMediaObject::GetInputMaxLatency](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getinputmaxlatency)