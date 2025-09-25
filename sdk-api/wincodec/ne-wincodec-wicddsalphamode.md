# WICDdsAlphaMode enumeration

## Description

Specifies the meaning of pixel color component values contained in the DDS image.

## Constants

### `WICDdsAlphaModeUnknown:0`

Alpha behavior is unspecified and must be determined by the reader.

### `WICDdsAlphaModeStraight:0x1`

The alpha data is straight.

### `WICDdsAlphaModePremultiplied:0x2`

The alpha data is premultiplied.

### `WICDdsAlphaModeOpaque:0x3`

The alpha data is opaque (UNORM value of 1). This can be used by a compliant reader as a performance optimization. For example, blending operations can be converted to copies.

### `WICDdsAlphaModeCustom:0x4`

The alpha channel contains custom data that is not alpha.

### `WICDDSALPHAMODE_FORCE_DWORD:0x7fffffff`

## See also

[IWICDdsDecoder::GetParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicddsdecoder-getparameters)

[WICDdsParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsparameters)