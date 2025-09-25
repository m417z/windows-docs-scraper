# IMFTimedTextCue::GetOriginalId

## Description

Gets the cue identifier that is provided in the text-track data format, if available.

## Parameters

### `originalId` [out]

Type: **LPWSTR***

The cue identifier that is provided in the text-track data format.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method retrieves an identifier for the cue that is included in the source data, if one was specified. The system dynamically generates identifiers for cues that are guaranteed to be unique within a single time-text track. To obtain this system-generated ID, call [GetId](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imftimedtextcue-getid).

## See also

[GetId](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imftimedtextcue-getid)

[IMFTimedTextCue](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtextcue)