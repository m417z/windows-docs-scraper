# IConfigAviMux::SetMasterStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetMasterStream` method specifies a stream that will be used to synchronize the other streams in the file.

## Parameters

### `iStream` [in]

Specifies the index of the stream, or –1 to indicate no master stream. The AVI Mux writes one stream for each connected input pin. Stream numbers are indexed from zero.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | Success. |

## Remarks

If you are capturing audio and video from two different sources, use this method to synchronize the streams. Streams coming from separate capture sources may be captured at slightly different rates. If you specify a master stream, the AVI Mux adjusts the playback rates for the other streams, to compensate for any drift that might occur.

It is recommended to use the audio stream as the master stream, because minor adjustments to the video playback rate are less noticeable than changes to the audio playback rate. Also, modifying the audio playback rate will cause the audio to be resampled by the audio driver.

This method works by adjusting the *dwScale* and *dwRate* values in the [AVISTREAMHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/avifmt/ns-avifmt-avistreamheader) structure.

## See also

[AVI RIFF File Reference](https://learn.microsoft.com/windows/desktop/DirectShow/avi-riff-file-reference)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IConfigAviMux Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iconfigavimux)