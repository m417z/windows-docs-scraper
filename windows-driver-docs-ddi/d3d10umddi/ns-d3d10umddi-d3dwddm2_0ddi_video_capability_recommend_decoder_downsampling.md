# D3DWDDM2_0DDI_VIDEO_CAPABILITY_RECOMMEND_DECODER_DOWNSAMPLING structure

## Description

**D3DWDDM2_0DDI_VIDEO_CAPABILITY_RECOMMEND_DECODER_DOWNSAMPLING** is used by the user-mode driver to recommend downsampling parameters that can be used to decode the stream in real-time. The driver provides these capabilities when its [**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities) function is called.

## Members

### `pInputDesc`

[in] Pointer to a [**D3D11_1DDI_VIDEO_DECODER_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc) structure containing the decode profile used and the resolution and format of the reference frames. This is the resolution/format to be downsampled (e.g. 4K, DXGI_FORMAT_P010).

### `InputColorSpace`

[in] A [**D3DDDI_COLOR_SPACE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dddi_color_space_type) value that specifies the color space information of the reference frame data.

### `pInputConfig`

[in] Pointer to a [**D3D11_1DDI_VIDEO_DECODER_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_config) structure containing the configuration data associated with the decode profile.

### `pFrameRate`

[in] Pointer to a [**DXGI_RATIONAL**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure containing the frame rate of the video content.

### `pOutputDesc`

[out] Pointer to a [**D3D11_1DDI_VIDEO_DECODER_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc) structure in which the driver returns the recommended resolution and the format of the output/display frames.

The decode profile (**Guid**) member of **pOutputDesc** can be ignored.

### `OutputColorSpace`

[out] Location in which the driver returns the recommended [**D3DDDI_COLOR_SPACE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dddi_color_space_type) color space information of the display frame data.

## Remarks

The driver recommends the down sample parameters such that the video stream can be decoded in real-time. If no down sample solution exists that can result in real-time decode, the driver should recommend the configuration that is closest to the real-time solution.

## See also

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_video_capability_query)

[**PFND3DWDDM2_0DDI_QUERYVIDEOCAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_queryvideocapabilities)