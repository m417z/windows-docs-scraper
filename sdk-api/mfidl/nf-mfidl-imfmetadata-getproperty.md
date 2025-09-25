# IMFMetadata::GetProperty

## Description

Gets the value of a metadata property.

## Parameters

### `pwszName` [in]

A pointer to a null-terminated string that contains the name of the property.
To get the list of property names, call [IMFMetadata::GetAllPropertyNames](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmetadata-getallpropertynames).

### `ppvValue` [out]

Pointer to a **PROPVARIANT** that receives the value of the property. The **PROPVARIANT** type depends on the property. For multivalued properties, the **PROPVARIANT** is a **VT_VECTOR** type. The caller must free the **PROPVARIANT** by calling [PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_PROPERTY_NOT_FOUND** | The requested property was not found. |

## See also

[IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata)

[Media Metadata](https://learn.microsoft.com/windows/desktop/medfound/media-metadata)