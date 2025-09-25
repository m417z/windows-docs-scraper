# D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_CAPS structure

## Description

**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_CAPS** describes the capabilities of the video decoder. The driver provides these capabilities when its [**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities) function is called.

## Members

### `DecodeProfile`

[in] The decode profile for which capabilities are being queried.

### `SampleWidth`

[in] The width in pixels of the video frame.

### `SampleHeight`

[in] The height in pixels of the video frame.

### `FrameRate`

[in] The frame rate of the video content.

### `BitRate`

[in] The bit rate of the video content.

### `pCryptoType`

[in] A pointer to a GUID that specifies the type of encryption algorithm. This field can have the following value.

| Value | Meaning |
| ----- | ------- |
| D3D11_1DDI_CRYPTO_TYPE_AES128_CTR | Queries whether the driver supports 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher encryption. |

### `Caps`

[out] Field in which the driver returns a bitwise OR of [**D3DWDDM2_0DDI_VIDEO_DECODER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_video_decoder_caps) enumeration values that reflect the video decoder's capabilities.

## See also

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_video_capability_query)

[**D3DWDDM2_0DDI_VIDEO_DECODER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_video_decoder_caps)

[**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities)