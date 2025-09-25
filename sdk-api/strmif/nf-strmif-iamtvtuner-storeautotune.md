# IAMTVTuner::StoreAutoTune

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `StoreAutoTune` method saves the fine-tuning information for all channels.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

Override the channel-to-frequency information stored by this method by setting a new country/region code in the [IAMTuner::put_CountryCode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtuner-put_countrycode) method. For a listing of country/region codes, see [International Analog TV Tuning](https://learn.microsoft.com/windows/desktop/DirectShow/international-analog-tv-tuning).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTVTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtvtuner)

[IAMTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtuner)