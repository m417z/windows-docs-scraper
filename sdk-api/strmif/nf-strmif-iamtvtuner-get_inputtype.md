# IAMTVTuner::get_InputType

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_InputType` method retrieves the input type set in [IAMTVTuner::put_InputType](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtvtuner-put_inputtype).

## Parameters

### `lIndex` [in]

Index value that specifies the input pin that will be set.

### `pInputType` [out]

Pointer to a variable the receives a member of the [TunerInputType](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-tunerinputtype) enumeration.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTVTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtvtuner)

[IAMTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtuner)