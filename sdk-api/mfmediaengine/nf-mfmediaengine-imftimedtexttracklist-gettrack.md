# IMFTimedTextTrackList::GetTrack

## Description

Gets a text track in the list from the index of the track.

## Parameters

### `index` [in]

Type: **DWORD**

The index of the track in the list to retrieve.

### `track` [out]

Type: **[IMFTimedTextTrack](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtexttrack)****

A pointer to a memory block that receives a pointer to the [IMFTimedTextTrack](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtexttrack) interface for the timed-text track.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextTrackList](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtexttracklist)