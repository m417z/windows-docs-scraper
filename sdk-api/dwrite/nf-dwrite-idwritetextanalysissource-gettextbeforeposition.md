# IDWriteTextAnalysisSource::GetTextBeforePosition

## Description

Gets a block of text immediately preceding the specified position.

## Parameters

### `textPosition`

Type: **UINT32**

The position immediately after the last position of the block of text to obtain.

### `textString` [out]

Type: **const WCHAR****

When this method returns, contains an address of a pointer to the block of text, as an array of characters from the specified range. The text range will be from *textPosition* to the front of the block.

### `textLength` [out]

Type: **UINT32***

Number of UTF16 units of the retrieved block.
The length returned is from the specified position to the front of
the block.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

NULL indicates no chunk available at the specified position, either because *textPosition* equals 0, *textPosition* is greater than the entire text content length, or the queried position is not mapped into the application's backing
store.

Although applications can implement sparse textual content that maps only part of
the backing store, the application must map any text that is in the range passed
to any analysis functions.

## See also

[IDWriteTextAnalysisSource](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissource)