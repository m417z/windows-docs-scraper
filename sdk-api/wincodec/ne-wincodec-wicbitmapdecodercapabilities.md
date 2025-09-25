# WICBitmapDecoderCapabilities enumeration

## Description

Specifies the capabilities of the decoder.

## Constants

### `WICBitmapDecoderCapabilitySameEncoder:0x1`

Decoder recognizes the image was encoded with an encoder produced by the same vendor.

### `WICBitmapDecoderCapabilityCanDecodeAllImages:0x2`

Decoder can decode all the images within an image container.

### `WICBitmapDecoderCapabilityCanDecodeSomeImages:0x4`

Decoder can decode some of the images within an image container.

### `WICBitmapDecoderCapabilityCanEnumerateMetadata:0x8`

Decoder can enumerate the metadata blocks within a container format.

### `WICBitmapDecoderCapabilityCanDecodeThumbnail:0x10`

Decoder can find and decode a thumbnail.

### `WICBITMAPDECODERCAPABILITIES_FORCE_DWORD:0x7fffffff`

## See also

[IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder)