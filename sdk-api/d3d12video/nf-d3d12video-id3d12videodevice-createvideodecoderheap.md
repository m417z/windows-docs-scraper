# ID3D12VideoDevice::CreateVideoDecoderHeap

## Description

Allocates a video decoder heap that contains the resolution-dependent driver resources and state.

## Parameters

### `pVideoDecoderHeapDesc`

A pointer to a [D3D12\_VIDEO\_DECODER\_HEAP\_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decoder_heap_desc) describing the decoding configuration.

### `riid`

The globally unique identifier (GUID) for the decode video state interface.

### `ppVideoDecoderHeap`

A pointer to a memory block that receives a pointer to the [ID3D12VideoDecoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videodecoderheap) interface.

## Return value

This method returns an HRESULT.

## Remarks

## See also