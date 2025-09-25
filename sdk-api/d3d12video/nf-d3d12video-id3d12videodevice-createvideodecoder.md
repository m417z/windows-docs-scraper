# ID3D12VideoDevice::CreateVideoDecoder

## Description

Creates a video decoder instance that contains the resolution-independent driver resources and state.

## Parameters

### `pDesc`

A pointer to a [D3D12\_VIDEO\_DECODER\_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decoder_desc) structure describing the decode profile and bitstream encryption for the decoder.

### `riid`

The globally unique identifier (GUID) for the decode video state interface.

### `ppVideoDecoder`

A pointer to a memory block that receives a pointer to the [ID3D12VideoDecoder](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videodecoder) interface.

## Return value

This method returns HRESULT.

## Remarks

Decoding a new stream requires instantiating a new decoder object.

## See also