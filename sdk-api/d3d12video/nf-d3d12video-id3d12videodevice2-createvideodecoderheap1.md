## Description

Allocates a video decoder heap that contains the resolution-dependent driver resources and state, with support for protected resources.

## Parameters

### `pVideoDecoderHeapDesc`

A pointer to a [D3D12\_VIDEO\_DECODER\_HEAP\_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decoder_heap_desc) describing the decoding configuration.

### `pProtectedResourceSession`

A [ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession) for managing access to protected resources.

### `riid`

The globally unique identifier (GUID) for the decode video state interface.

### `ppVideoDecoderHeap`

A pointer to a memory block that receives a pointer to the [ID3D12VideoDecoderHeap1](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videodecoderheap1) interface.

## Return value

This method returns an HRESULT.

## Remarks

## See also