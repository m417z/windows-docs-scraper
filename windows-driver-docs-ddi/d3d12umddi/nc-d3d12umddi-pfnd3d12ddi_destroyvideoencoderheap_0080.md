## Description

A client driver's **PFND3D12DDI_DESTROYVIDEOENCODERHEAP_0080** callback function destroys a video encoder heap object.

## Parameters

### `hDrvDevice` [in]

Handle to the D3D12 device.

### `hDrvVideoEncoderHeap` [in]

Handle to the D3D12 video encoder heap object created in a call to [**PFND3D12DDI_CREATEVIDEOENCODERHEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoderheap_0080_2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**PFND3D12DDI_CREATEVIDEOENCODERHEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoderheap_0080_2)