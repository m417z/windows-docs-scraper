# D3D11_VIDEO_CONTENT_PROTECTION_CAPS structure

## Description

Describes the content-protection capabilities of a graphics driver.

## Members

### `Caps`

A bitwise **OR** of zero or more flags from the [D3D11_CONTENT_PROTECTION_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_content_protection_caps) enumeration.

### `KeyExchangeTypeCount`

The number of cryptographic key-exchange types that are supported by the driver. To get the list of key-exchange types, call the [ID3D11VideoDevice::CheckCryptoKeyExchange](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-checkcryptokeyexchange) method.

### `BlockAlignmentSize`

The encryption block size, in bytes. The size of data to be encrypted must be a multiple of this value.

### `ProtectedMemorySize`

The total amount of memory, in bytes, that can be used to hold protected surfaces.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)

[ID3D11VideoDevice::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getcontentprotectioncaps)