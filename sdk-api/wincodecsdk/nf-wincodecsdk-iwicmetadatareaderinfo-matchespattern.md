# IWICMetadataReaderInfo::MatchesPattern

## Description

Determines if a stream contains a metadata item pattern.

## Parameters

### `guidContainerFormat` [in]

Type: **REFGUID**

The container format of the metadata item.

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The stream to search for the metadata pattern.

### `pfMatches` [out]

Type: **BOOL***

Pointer that receives `TRUE` if the stream contains the pattern; otherwise, `FALSE`.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.