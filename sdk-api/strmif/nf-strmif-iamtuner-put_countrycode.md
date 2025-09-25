# IAMTuner::put_CountryCode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_CountryCode` method sets the country/region code to establish the frequency to use.

## Parameters

### `lCountryCode` [in]

Value indicating the country/region code.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

This method establishes the base frequencies for the given country/region. Use the [IAMTVTuner::AutoTune](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtvtuner-autotune) method to determine the exact frequencies for specific regions, unless there are previously cached settings for the new country/region.

Because channels in different countries/regions map to different frequencies, worldwide mapping tables are provided in the appendix [International Analog TV Tuning](https://learn.microsoft.com/windows/desktop/DirectShow/international-analog-tv-tuning). Override the existing country/region code by selecting the new value from the appendix and passing it in as the parameter for the `put_CountryCode` method. This is useful when a country/region wants to receive broadcast video from a different national source.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtuner)