# MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS structure

## Description

Contains parameters for the [IMFInputTrustAuthority::BindAccess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfinputtrustauthority-bindaccess) or [IMFInputTrustAuthority::UpdateAccess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfinputtrustauthority-updateaccess) method.

## Members

### `dwSize`

Size of the structure, in bytes.

### `dwVer`

Version number. This value must be zero.

### `cbSignatureOffset`

Offset of the signature from the start of the structure, in bytes.

### `cbSignatureSize`

Size of the signature, in bytes.

### `cbExtensionOffset`

Offset of the extension blob from the start of the structure, in bytes.

### `cbExtensionSize`

Size of the extension blob, in bytes.

### `cActions`

Number of elements in the **rgOutputActions** array.

### `rgOutputActions`

Array of [MFINPUTTRUSTAUTHORITY_ACCESS_ACTION](https://learn.microsoft.com/windows/win32/api/mfidl/ns-mfidl-mfinputtrustauthority_access_action) structures. The number of elements in the array is specified in the **cActions** member.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)