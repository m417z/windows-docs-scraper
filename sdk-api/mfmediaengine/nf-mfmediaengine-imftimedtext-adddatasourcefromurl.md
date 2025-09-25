# IMFTimedText::AddDataSourceFromUrl

## Description

Adds a timed-text data source from the specified URL.

## Parameters

### `url` [in]

Type: **LPCWSTR**

The URL of the timed-text data source.

### `label` [in, optional]

Type: **LPCWSTR**

Null-terminated wide-character string that contains the label of the data source.

### `language` [in, optional]

Type: **LPCWSTR**

Null-terminated wide-character string that contains the language of the data source.

### `kind` [in]

Type: **[MF_TIMED_TEXT_TRACK_KIND](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_track_kind)**

A [MF_TIMED_TEXT_TRACK_KIND](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/ne-mfmediaengine-mf_timed_text_track_kind)-typed value that specifies the kind of timed-text track.

### `isDefault` [in]

Type: **BOOL**

Specifies whether to add the default data source. Specify **TRUE** to add the default data source or **FALSE** otherwise.

### `trackId` [out]

Type: **DWORD***

Receives a pointer to the unique identifier for the added track.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTimedText](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imftimedtext)