# IMediaObject::Flush

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Flush` method flushes all internally buffered data.

## Return value

Returns S_OK if successful. Otherwise, returns an **HRESULT** value indicating the cause of the error.

## Remarks

The DMO performs the following actions when this method is called:

* Releases any [IMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediabuffer) references it holds.
* Discards any values that specify the time stamp or sample length for a media buffer.
* Reinitializes any internal states that depend on the contents of a media sample.

Media types, maximum latency, and locked state do not change.

When the method returns, every input stream accepts data. Output streams cannot produce any data until the application calls the [IMediaObject::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processinput) method on at least one input stream.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)