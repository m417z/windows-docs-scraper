# D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC structure

## Description

Describes a video processor input view.

## Members

### `FourCC`

The surface format. If zero, the driver uses the DXGI format that was used to create the resource. If you are using feature level 9, the value must be zero.

### `ViewDimension`

The resource type of the view, specified as a member of the [D3D11_VPIV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_vpiv_dimension) enumeration.

### `Texture2D`

A [D3D11_TEX2D_VPIV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex2d_vpiv) structure that identifies the texture resource.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)

[ID3D11VideoDevice::CreateVideoProcessorInputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessorinputview)