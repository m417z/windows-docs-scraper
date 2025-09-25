# IMFMediaEngine::GetDefaultPlaybackRate

## Description

Gets the default playback rate.

## Return value

Returns the default playback rate, as a multiple of normal (1×) playback. A negative value indicates reverse playback.

## Remarks

This method corresponds to getting the **defaultPlaybackRate** attribute of the **HTMLMediaElement** interface in HTML5.

The default playback rate is used for the next call to the [IMFMediaEngine::Play](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-play) method. To change the current playback rate, call [IMFMediaEngine::SetPlaybackRate](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setplaybackrate).

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)