## Description

A client driver's **PFND3D12DDI_DESTROYVIDEOENCODER_0080** callback function destroys a video encoder object.

## Parameters

### `hDrvDevice` [in]

Handle to the D3D12 device.

### `hDrvVideoEncoder` [in]

Handle to the D3D12 video encoder object created in a call to [**PFND3D12DDI_CREATEVIDEOENCODER_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoder_0082_0).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**PFND3D12DDI_CREATEVIDEOENCODER_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoder_0082_0)