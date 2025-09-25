# IMFTimedTextCue::GetLine

## Description

Gets a line of text in the cue from the index of the line.

## Parameters

### `index` [in]

Type: **DWORD**

The index of the line of text in the cue to retrieve.

### `line` [out]

Type: **[IMFTimedTextFormattedText](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextformattedtext)****

A pointer to a memory block that receives a pointer to the [IMFTimedTextFormattedText](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextformattedtext) interface for the line of text in the cue.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedTextCue](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextcue)