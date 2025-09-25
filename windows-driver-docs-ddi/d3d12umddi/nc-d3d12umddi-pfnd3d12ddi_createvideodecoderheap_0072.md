# PFND3D12DDI_CREATEVIDEODECODERHEAP_0072 callback function

## Description

A client driver's **PFND3D12DDI_CREATEVIDEODECODERHEAP_0072** creates a video decoder heap.

## Parameters

### `hDrvDevice` [in]

Handle to the D3D12 device.

### `unnamedParam2` [in]

Pointer to a [**D3D12DDIARG_CREATE_VIDEO_DECODER_HEAP_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_decoder_heap_0072) structure with the arguments used to create a video decoder heap.

### `hDrvVideoDecoderHeap` [out]

Handle to the created video decoder heap.

## Return value

Returns an [**HRESULT**](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) value.

## Remarks

See the [Video Protected Resource Support specification](https://microsoft.github.io/DirectX-Specs/d3d/D3D12_Video_ProtectedResourceSupport.html) for more information.

## See also

[**D3D12DDIARG_CREATE_VIDEO_DECODER_HEAP_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_decoder_heap_0072)