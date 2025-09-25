# MFT_REGISTRATION_INFO structure

## Description

Contains parameters for the [IMFLocalMFTRegistration::RegisterMFTs](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imflocalmftregistration-registermfts) method.

## Members

### `clsid`

CLSID of the Media Foundation transform (MFT) to register.

### `guidCategory`

GUID that specifies the category of the MFT. For a list of MFT categories, see [MFT_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mft-category).

### `uiFlags`

Bitwise **OR** of zero or more flags from the [_MFT_ENUM_FLAG](https://learn.microsoft.com/windows/win32/api/mfapi/ne-mfapi-_mft_enum_flag) enumeration.

### `pszName`

Wide-character string that contains the friendly name of the MFT.

### `cInTypes`

Number of elements in the **pInTypes** array.

### `pInTypes`

Pointer to an array of [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structures. Each member of the array specifies an input format that the MFT supports. If this member is **NULL**, the **cInTypes** member must be zero.

### `cOutTypes`

Number of elements in the **pOutTypes** array.

### `pOutTypes`

Pointer to an array of [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structures. Each member of the array defines an output format that the MFT supports. If this member is **NULL**, the **cOutTypes** member must be zero.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)