# IMFTimedTextCue::GetRegion

## Description

Gets info about the display region of the timed-text cue.

## Parameters

### `region` [out]

Type: **[IMFTimedTextRegion](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextregion)****

A pointer to a memory block that receives a pointer to the [IMFTimedTextRegion](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextregion) interface for the timed-text region. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextCue](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextcue)