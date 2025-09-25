# IAMTuner::put_TuningSpace

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_TuningSpace` method sets a storage index for regional channel-to-frequency mappings.

## Parameters

### `lTuningSpace` [in]

Value indicating the current locale.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

As TV tuners move into portable systems, you must retain locale-specific mappings of available channels and their actual frequencies. Formulating different *lTuningSpace* values for each locale provides a way of switching the channel-to-frequency mappings when moving from region to region.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtuner)