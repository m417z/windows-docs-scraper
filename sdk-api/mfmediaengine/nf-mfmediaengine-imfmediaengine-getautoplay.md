# IMFMediaEngine::GetAutoPlay

## Description

Queries whether the Media Engine automatically begins playback.

## Return value

Returns **TRUE** if the Media Engine automatically begins playback, or **FALSE** otherwise.

## Remarks

This method corresponds to the **autoplay** attribute of the **HTMLMediaElement** interface in HTML5.

If this method returns **TRUE**, playback begins automatically after the [IMFMediaEngine::Load](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-load) method completes. Otherwise, playback begins when the application calls [IMFMediaEngine::Play](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-play).

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)

[IMFMediaEngine::SetAutoPlay](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-setautoplay)