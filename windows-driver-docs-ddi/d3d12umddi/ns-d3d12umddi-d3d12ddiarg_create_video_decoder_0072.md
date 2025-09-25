## Description

Structure used to create a video decoder.

## Members

### `NodeMask`

Represents the set of nodes. For a single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Configuration`

The decode profile and bitstream encryption. See [**D3D12DDI_VIDEO_DECODE_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_configuration_0020).

### `hDrvProtectedResourceSession`

Handle to the protected resource session acquired at object creation time.

## Remarks

See the [D3D Video Protected Resource Support Specification](https://microsoft.github.io/DirectX-Specs/d3d/ProtectedResources.html) for more information.

## See also

[**D3D12DDI_VIDEO_DECODE_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_configuration_0020)

[**PFND3D12DDI_CALCPRIVATEVIDEODECODERSIZE_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideodecodersize_0072)

[**PFND3D12DDI_CREATEVIDEODECODER_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideodecoder_0072)