# IMFTimedText::RemoveTrack

## Description

Removes the timed-text track with the specified identifier.

## Parameters

### `track` [in]

Type: **DWORD**

The identifier of the track to remove.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Get the identifier for a track by calling [GetId](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imftimedtexttrack-getid).

When a track is removed, all buffered data from the track is also removed.

## See also

[IMFTimedText](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtext)