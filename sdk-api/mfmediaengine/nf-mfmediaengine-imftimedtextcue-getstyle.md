# IMFTimedTextCue::GetStyle

## Description

Gets info about the style of the timed-text cue.

## Parameters

### `style` [out]

Type: **[IMFTimedTextStyle](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextstyle)****

A pointer to a memory block that receives a pointer to the [IMFTimedTextStyle](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextstyle) interface for the timed-text style. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextCue](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextcue)