# D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA structure

## Description

Represents key exchange input data for hardware content protection.

## Members

### `PrivateDataSize`

The size of the private data reserved for IHV usage. This size is determined from the *pPrivateInputSize* parameter returned by the [ID3D11VideoDevice1::GetCryptoSessionPrivateDataSize](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11videodevice1-getcryptosessionprivatedatasize) function.

### `HWProtectionDataSize`

The size of the DRM command data.

### `pbInput`

If **PrivateDataSize** is greater than 0, pbInput[0] – **pbInput**[**PrivateDataSize** - 1] is reserved for IHV use.

**pbInput**[**PrivateDataSize**] – **pbInput**[**HWProtectionDataSize** + **PrivateDataSize** - 1] contains the input data for the DRM command. The format and size of the DRM command is defined by the DRM specification.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)