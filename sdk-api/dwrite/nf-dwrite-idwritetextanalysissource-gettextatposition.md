# IDWriteTextAnalysisSource::GetTextAtPosition

## Description

Gets a block of text starting at the specified text position.

## Parameters

### `textPosition`

Type: **UINT32**

The first position of the piece to obtain. All
positions are in **UTF16** code units, not whole characters, which
matters when supplementary characters are used.

### `textString` [out]

Type: **const WCHAR****

When this method returns, contains an address of the block of text as an array of characters to be retrieved from the text analysis.

### `textLength` [out]

Type: **UINT32***

When this method returns, contains the number of **UTF16** units of the retrieved chunk.
The returned length is not the length of the block, but the length remaining in the block, from the specified position until its end.
For example, querying for a position that is 75 positions into a 100-position block would return 25.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Returning **NULL** indicates the end of text, which is the position after the last character. This function is called iteratively for each consecutive block, tying together several fragmented blocks in the backing store into a virtual contiguous string.

Although applications can implement sparse textual content that maps only part of the backing store, the application must map any text that is in the range passed to any analysis functions.

## See also

[IDWriteTextAnalysisSource](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextanalysissource)