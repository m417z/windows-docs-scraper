# IDWriteFactory5::AnalyzeContainerType

## Description

The AnalyzeContainerType method analyzes the specified file data to determine whether it is a known font container format (e.g., WOFF or WOFF2).

## Parameters

### `fileData` [in]

Type: **void**

Pointer to the file data to analyze.

### `fileDataSize`

Type: **UINT32**

Size of the buffer passed in fileData.

## Return value

Type: **[DWRITE_CONTAINER_TYPE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_container_type)**

Returns the container type if recognized. DWRITE_CONTAINER_TYPE_UNKOWNN is returned for all other files, including uncompressed font files.

## See also

[IDWriteFactory5](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory5)