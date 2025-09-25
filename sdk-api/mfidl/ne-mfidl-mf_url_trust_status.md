# MF_URL_TRUST_STATUS enumeration

## Description

Indicates whether the URL is from a trusted source.

## Constants

### `MF_LICENSE_URL_UNTRUSTED:0`

The validity of the URL cannot be guaranteed because it is not signed. The application should warn the user.

### `MF_LICENSE_URL_TRUSTED`

The URL is the original one provided with the content.

### `MF_LICENSE_URL_TAMPERED`

The URL was originally signed and has been tampered with. The file should be considered corrupted, and the application should not navigate to the URL without issuing a strong warning the user.

## See also

[IMFContentEnabler::GetEnableURL](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentenabler-getenableurl)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)