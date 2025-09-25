# IMFMediaEngine::GetCurrentTime

## Description

Gets the current playback position.

## Return value

Returns the playback position, in seconds.

## Remarks

This method corresponds to the **currentTime** attribute of the **HTMLMediaElement** interface in HTML5.

Note that after you call [Pause](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-pause), the time returned by **GetCurrentTime** may not be precisely accurate. Apps that need a frame-accurate position value, such as media editors, should call [FrameStep](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengineex-framestep) immediately after calling **Pause** before calling **GetCurrentTime**.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)