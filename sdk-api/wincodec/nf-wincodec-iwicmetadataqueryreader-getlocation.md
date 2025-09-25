# IWICMetadataQueryReader::GetLocation

## Description

Retrieves the current path relative to the root metadata block.

## Parameters

### `cchMaxLength` [in]

Type: **UINT**

The length of the *wzNamespace* buffer.

### `wzNamespace` [in, out]

Type: **WCHAR***

Pointer that receives the current namespace location.

### `pcchActualLength` [out]

Type: **UINT***

The actual buffer length that was needed to retrieve the current namespace location.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you pass **NULL** to *wzNamespace*, **GetLocation** ignores *cchMaxLength* and returns the required buffer length to store the path in the variable that *pcchActualLength* points to.

If the query reader is relative to the top of the metadata hierarchy, it will return a single-char string.

If the query reader is relative to a nested metadata block, this method will return the path to the current query reader.

## See also

**Conceptual**

[IWICMetadataQueryReader](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataqueryreader)

[Overview of Reading and Writing Image Metadata](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-readingwritingmetadata)

[WIC Metadata Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-about-metadata)