# IMFTimedText::GetTextTracks

## Description

Gets the list of all the timed-text tracks in the timed-text component.

## Parameters

### `textTracks` [out]

Type: **[IMFTimedTextTrackList](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtexttracklist)****

A pointer to a memory block that receives a pointer to the [IMFTimedTextTrackList](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtexttracklist) interface that can enumerate the list of all of the timed-text tracks.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedText](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtext)