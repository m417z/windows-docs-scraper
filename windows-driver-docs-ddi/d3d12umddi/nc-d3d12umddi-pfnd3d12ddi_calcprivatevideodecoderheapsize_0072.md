# PFND3D12DDI_CALCPRIVATEVIDEODECODERHEAPSIZE_0072 callback function

## Description

**PFND3D12DDI_CALCPRIVATEVIDEODECODERHEAPSIZE_0072** calculates the size of a video decoder heap.

## Parameters

### `hDrvDevice`

Handle to the hardware device being processed.

### `pArgs` [in]

Pointer to a [**D3D12DDIARG_CREATE_VIDEO_DECODER_HEAP_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_decoder_heap_0072) structure with arguments used by this callback function.

## Return value

Returns the size of the heap in bytes.

## Remarks

The D3D runtime allocates memory for storing the driver's CPU object representing the video decoder heap. This method is used to calculate the driver object size.

See the [Video Protected Resource Support specification](https://microsoft.github.io/DirectX-Specs/d3d/D3D12_Video_ProtectedResourceSupport.html) for more information.

## See also

[**D3D12DDIARG_CREATE_VIDEO_DECODER_HEAP_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_decoder_heap_0072)