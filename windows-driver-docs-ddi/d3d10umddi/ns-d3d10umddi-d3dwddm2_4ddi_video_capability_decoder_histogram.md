# D3DWDDM2_4DDI_VIDEO_CAPABILITY_DECODER_HISTOGRAM structure

## Description

**D3DWDDM2_4DDI_VIDEO_CAPABILITY_DECODER_HISTOGRAM** describes the video decoder histogram capabilities. The driver provides these capabilities when its [**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities) function is called.

## Members

### `DecoderDesc`

[in] A [**D3D11_1DDI_VIDEO_DECODER_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc) structure containing the description for the decoder to be used with decode histogram.

### `Components`

[out] A [**D3DWDDM2_4DDI_VIDEO_DECODER_HISTOGRAM_COMPONENT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_4ddi_video_decoder_histogram_component_flags) value that specifies the components (or channels) of a DXGI_FORMAT that the hardware supports.

### `BinCount`

[out] The number of per component bins supported. **BinCount** must be >= 64 and must be a power of 2 (64, 128, 256, 512, etc.).

### `CounterBitDepth`

[out] The bit depth of the bin counter. The counter is always stored in a 32-bit value and is therefore 32 bits or less. The counter is stored in the lower bits of the 32 bit storage. The upper bits are set to zero. If the in count exceeds this bit depth, the value is set to the maximum counter value. Valid values for **CounterBitDepth** are 16, 24, and 32.

## See also

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_video_capability_query)

[**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities)