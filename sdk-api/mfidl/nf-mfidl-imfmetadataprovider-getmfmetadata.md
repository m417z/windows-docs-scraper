# IMFMetadataProvider::GetMFMetadata

## Description

Gets a collection of metadata, either for an entire presentation, or for one stream in the presentation.

## Parameters

### `pPresentationDescriptor` [in]

Pointer to the [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of the media source's presentation descriptor.

### `dwStreamIdentifier` [in]

If this parameter is zero, the method retrieves metadata that applies to the entire presentation. Otherwise, this  parameter specifies a stream identifier, and the method retrieves metadata for that stream. To get the stream identifier for a stream, call [IMFStreamDescriptor::GetStreamIdentifier](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamdescriptor-getstreamidentifier).

### `dwFlags` [in]

Reserved. Must be zero.

### `ppMFMetadata` [out]

Receives a pointer to the [IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata) interface. Use this interface to access the metadata. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_PROPERTY_NOT_FOUND** | No metadata is available for the requested stream or presentation. |

## See also

[IMFMetadataProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadataprovider)

[Media Metadata](https://learn.microsoft.com/windows/desktop/medfound/media-metadata)