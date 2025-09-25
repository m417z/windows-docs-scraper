# IWICBitmapDecoderInfo::MatchesPattern

## Description

Retrieves a value that indicates whether the codec recognizes the pattern within a specified stream.

## Parameters

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The stream to pattern match within.

### `pfMatches` [out]

Type: **BOOL***

A pointer that receives **TRUE** if the patterns match; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.