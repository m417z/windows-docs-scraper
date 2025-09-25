# IMFMetadata::GetAllPropertyNames

## Description

Gets a list of all the metadata property names on this object.

## Parameters

### `ppvNames` [out]

Pointer to a **PROPVARIANT** that receives an array of null-terminated wide-character strings. If no properties are available, the **PROPVARIANT** type is VT_EMPTY. Otherwise, the **PROPVARIANT** type is VT_VECTOR | VT_LPWSTR. The caller must free the **PROPVARIANT** by calling [PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata)

[Media Metadata](https://learn.microsoft.com/windows/desktop/medfound/media-metadata)