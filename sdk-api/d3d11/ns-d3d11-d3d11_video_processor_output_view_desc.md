# D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC structure

## Description

Describes a video processor output view.

## Members

### `ViewDimension`

The resource type of the view, specified as a member of the [D3D11_VPOV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_vpov_dimension) enumeration.

### `Texture2D`

A [D3D11_TEX2D_VPOV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_vpov) structure that identifies the texture resource for the output view.

Use this member of the union when **ViewDimension** equals **D3D11_VPOV_DIMENSION_TEXTURE2D**.

### `Texture2DArray`

A [D3D11_TEX2D_ARRAY_VPOV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_array_vpov) structure that identifies the texture array for the output view.

Use this member of the union when **ViewDimension** equals **D3D11_VPOV_DIMENSION_TEXTURE2DARRAY**.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)

[ID3D11VideoDevice::CreateVideoProcessorOutputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessoroutputview)