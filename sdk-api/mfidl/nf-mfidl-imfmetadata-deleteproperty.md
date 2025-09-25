# IMFMetadata::DeleteProperty

## Description

Deletes a metadata property.

## Parameters

### `pwszName` [in]

Pointer to a null-terminated string containing the name of the property.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_PROPERTY_NOT_FOUND** | The property was not found. |

## Remarks

For a media source, deleting a property from the metadata collection does not change the original content.

## See also

[IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata)

[Media Metadata](https://learn.microsoft.com/windows/desktop/medfound/media-metadata)