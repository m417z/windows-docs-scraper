# IAMTuner::get_TuningSpace

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_TuningSpace` method retrieves the tuning space.

## Parameters

### `plTuningSpace` [out]

Pointer to a variable that receives the current tuning space.

## Return value

Returns an **HRESULT** value.

## Remarks

The application defines the value retrieved by this method; it is set through a call to [IAMTuner::put_TuningSpace](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtuner-put_tuningspace).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtuner)