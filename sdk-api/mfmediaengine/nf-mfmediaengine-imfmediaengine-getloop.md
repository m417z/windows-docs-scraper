# IMFMediaEngine::GetLoop

## Description

Queries whether the Media Engine will loop playback.

## Return value

Returns **TRUE** if looping is enabled, or **FALSE** otherwise.

## Remarks

This method corresponds to getting the **loop** attribute of the **HTMLMediaElement** interface in HTML5.

If looping is enabled, the Media Engine seeks to the start of the content when playback reaches the end.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)