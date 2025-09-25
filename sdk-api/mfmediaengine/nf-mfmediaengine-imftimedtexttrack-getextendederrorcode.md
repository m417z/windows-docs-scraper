# IMFTimedTextTrack::GetExtendedErrorCode

## Description

Gets the extended error code for the latest error associated with the track.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

The extended error code for the latest error associated with the track.

## Remarks

If the most recent error was associated with a track, this value will be the same [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) as returned by the [IMFTimedTextNotify::Error](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imftimedtextnotify-error) method.

## See also

[IMFTimedTextTrack](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtexttrack)