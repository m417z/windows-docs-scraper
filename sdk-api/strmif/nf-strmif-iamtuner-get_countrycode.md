# IAMTuner::get_CountryCode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_CountryCode` method retrieves the country/region code that establishes the current channel-to-frequency mapping.

## Parameters

### `plCountryCode` [out]

Pointer to a variable that receives the country/region code currently in use by the [TV Tuner](https://learn.microsoft.com/windows/desktop/DirectShow/tv-tuner-filter) filter.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

The [IAMTuner::put_CountryCode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtuner-put_countrycode) method determines which channel-to-frequency mapping table to use. This establishes the base frequencies for the given country/region. Use the [IAMTVTuner::AutoTune](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtvtuner-autotune) method to determine the exact frequencies for specific regions.

Override the country/region code when a country/region wants to receive broadcast video from a different national source. For a list of country/region codes, see [International Analog TV Tuning](https://learn.microsoft.com/windows/desktop/DirectShow/international-analog-tv-tuning).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtuner)