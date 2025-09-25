# IAMTVTuner::AutoTune

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AutoTune` method scans for a precise signal on the channel's frequency.

## Parameters

### `lChannel` [in]

TV channel number.

### `plFoundSignal` [out]

Pointer to a variable indicating whether the channel's frequency was found; nonzero indicates found, zero indicates not found.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

TV channels generally map to a unique frequency depending on regional variances. To avoid interference between multiple transmitters that are assigned the same channel when they are in close geographic proximity, small frequency offsets are introduced at each transmitter. In the United States, this offset ranges up to +/– 26.25 kilohertz (kHz).

This method handles the channel-to-frequency conversion and scans for the most precise frequency. Store these values by calling the [IAMTVTuner::StoreAutoTune](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtvtuner-storeautotune) method. You can find base frequencies for channels in the appendix [International Analog TV Tuning](https://learn.microsoft.com/windows/desktop/DirectShow/international-analog-tv-tuning).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTVTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtvtuner)

[IAMTuner Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtuner)