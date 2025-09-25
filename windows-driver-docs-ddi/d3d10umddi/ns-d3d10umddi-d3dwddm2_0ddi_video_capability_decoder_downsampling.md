# D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLING structure

## Description

**D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_DOWNSAMPLING** describes the details of a video decoder downsampling operation.

## Members

### `pInputDesc` [in]

Contains the decode profile used and the resolution and format of the reference frames. This is the resolution/format to be downsampled (e.g. 4K, DXGI_FORMAT_P010).

### `InputColorSpace` [in]

Contains the color space information of the reference frame data.

### `pInputConfig` [in]

A [**D3D11_1DDI_VIDEO_DECODER_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_config) structure that contains the configuration data associated with the decode profile .

### `pFrameRate` [in]

Contains the frame rate of the video content.

### `pOutputDesc` [in]

A [**D3D11_1DDI_VIDEO_DECODER_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc) structure that contains the resolution and the format of the display frames. This is the destination resolution and format of the down sample operation.

The decode profile (**Guid**) member of **pOutputDesc** can be ignored.

### `OutputColorSpace` [in]

Contains the color space information of the display frame data.

### `Supported` [out]

The driver sets this to **TRUE** if the requested down sampling is supported. Otherwise, the driver should set this to **FALSE**.

### `RealTime` [out]

The driver sets this to **TRUE** if the requested down sampling is supported and the resulting decode operations can occur in real-time. Otherwise, the driver should set this to **FALSE**.

## See also

[**D3DWDDM2_0DDI_VIDEO_CAPABILITY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_video_capability_query)

[**D3D11_1DDI_VIDEO_DECODER_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_config)

[**D3D11_1DDI_VIDEO_DECODER_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_decoder_desc)

[**D3DDDI_COLOR_SPACE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type)