# IMFMetadata::SetProperty

## Description

Sets the value of a metadata property.

## Parameters

### `pwszName` [in]

Pointer to a null-terminated string containing the name of the property.

### `ppvValue` [in]

Pointer to a **PROPVARIANT** that contains the value of the property. For multivalued properties, use a **PROPVARIANT** with a VT_VECTOR type.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata)

[Media Metadata](https://learn.microsoft.com/windows/desktop/medfound/media-metadata)