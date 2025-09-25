# IMFTimedText::SelectTrack

## Description

Selects or deselects a track of text in the timed-text component.

## Parameters

### `trackId` [in]

Type: **DWORD**

The identifier of the track to select.

### `selected` [in]

Type: **BOOL**

Specifies whether to select or deselect a track of text. Specify **TRUE** to select the track or **FALSE** to deselect the track.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedText](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtext)