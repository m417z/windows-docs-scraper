# IAMVideoDecimationProperties::SetDecimationUsage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDecimationUsage` method sets the decimation strategy.

## Parameters

### `Usage` [in]

Member of the [DECIMATION_USAGE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-decimation_usage) enumeration that specifies the decimation strategy.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface. The DirectShow implementation returns S_OK if successful, or E_INVALIDARG otherwise.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoDecimationProperties Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideodecimationproperties)