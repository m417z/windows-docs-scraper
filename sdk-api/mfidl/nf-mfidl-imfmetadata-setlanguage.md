# IMFMetadata::SetLanguage

## Description

Sets the language for setting and retrieving metadata.

## Parameters

### `pwszRFC1766` [in]

Pointer to a null-terminated string containing an RFC 1766-compliant language tag.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For more information about language tags, see RFC 1766, "Tags for the Identification of Languages".

## See also

[IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata)

[Media Metadata](https://learn.microsoft.com/windows/desktop/medfound/media-metadata)