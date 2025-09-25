# IMFTimedTextCue::GetData

## Description

Gets the data content of the timed-text cue.

## Parameters

### `data` [out]

Type: **[IMFTimedTextBinary](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextbinary)****

A pointer to a memory block that receives a pointer to the [IMFTimedTextBinary](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextbinary) interface for the data content of the timed-text cue. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextCue](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextcue)