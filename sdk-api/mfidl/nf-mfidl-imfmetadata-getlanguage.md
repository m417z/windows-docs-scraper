# IMFMetadata::GetLanguage

## Description

Gets the current language setting.

## Parameters

### `ppwszRFC1766` [out]

Receives a pointer to a null-terminated string containing an RFC 1766-compliant language tag. The caller must release the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The metadata provider does not support multiple languages. |
| **MF_E_INVALIDREQUEST** | No language was set. |

## Remarks

For more information about language tags, see RFC 1766, "Tags for the Identification of Languages."

The [IMFMetadata::SetLanguage](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmetadata-setlanguage) and [IMFMetadata::GetProperty](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmetadata-getproperty) methods set and get metadata for the current language setting.

## See also

[IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata)

[Media Metadata](https://learn.microsoft.com/windows/desktop/medfound/media-metadata)