# D3D12_FORMAT_SUPPORT1 enumeration

## Description

Specifies resources that are supported for a provided format.

## Constants

### `D3D12_FORMAT_SUPPORT1_NONE:0`

No resources are supported.

### `D3D12_FORMAT_SUPPORT1_BUFFER:0x1`

Buffer resources supported.

### `D3D12_FORMAT_SUPPORT1_IA_VERTEX_BUFFER:0x2`

Vertex buffers supported.

### `D3D12_FORMAT_SUPPORT1_IA_INDEX_BUFFER:0x4`

Index buffers supported.

### `D3D12_FORMAT_SUPPORT1_SO_BUFFER:0x8`

Streaming output buffers supported.

### `D3D12_FORMAT_SUPPORT1_TEXTURE1D:0x10`

1D texture resources supported.

### `D3D12_FORMAT_SUPPORT1_TEXTURE2D:0x20`

2D texture resources supported.

### `D3D12_FORMAT_SUPPORT1_TEXTURE3D:0x40`

3D texture resources supported.

### `D3D12_FORMAT_SUPPORT1_TEXTURECUBE:0x80`

Cube texture resources supported.

### `D3D12_FORMAT_SUPPORT1_SHADER_LOAD:0x100`

The HLSL [Load](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-load) function for texture objects is supported.

### `D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE:0x200`

The HLSL [Sample](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-sample) function for texture objects is supported.

**Note** If the device supports the format as a resource (1D, 2D, 3D, or cube map) but doesn't support this option, the resource can still use the [Sample](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-sample) method but must use only the point filtering sampler state to perform the sample.

### `D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_COMPARISON:0x400`

The HLSL [SampleCmp](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmp) and [SampleCmpLevelZero](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmplevelzero) functions for texture objects are supported.

**Note** Windows 8 and later might provide limited support for these functions on Direct3D [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9_1, 9_2, and 9_3. For more info, see [Implementing shadow buffers for Direct3D feature level 9](https://learn.microsoft.com/previous-versions/windows/apps/jj262110(v=win.10)).

### `D3D12_FORMAT_SUPPORT1_SHADER_SAMPLE_MONO_TEXT:0x800`

Reserved.

### `D3D12_FORMAT_SUPPORT1_MIP:0x1000`

Mipmaps are supported.

### `D3D12_FORMAT_SUPPORT1_RENDER_TARGET:0x4000`

Render targets are supported.

### `D3D12_FORMAT_SUPPORT1_BLENDABLE:0x8000`

Blend operations supported.

### `D3D12_FORMAT_SUPPORT1_DEPTH_STENCIL:0x10000`

Depth stencils supported.

### `D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RESOLVE:0x40000`

Multisample antialiasing (MSAA) resolve operations are supported. For more info, see [ID3D12GraphicsCommandList::ResolveSubresource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-resolvesubresource).

### `D3D12_FORMAT_SUPPORT1_DISPLAY:0x80000`

Format can be displayed on screen.

### `D3D12_FORMAT_SUPPORT1_CAST_WITHIN_BIT_LAYOUT:0x100000`

Format can be cast to another format.

### `D3D12_FORMAT_SUPPORT1_MULTISAMPLE_RENDERTARGET:0x200000`

Format can be used as a multi-sampled render target.

### `D3D12_FORMAT_SUPPORT1_MULTISAMPLE_LOAD:0x400000`

Format can be used as a multi-sampled texture and read into a shader with the HLSL [Load](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-load) function.

### `D3D12_FORMAT_SUPPORT1_SHADER_GATHER:0x800000`

Format can be used with the HLSL gather function. This value is available in DirectX 10.1 or higher.

### `D3D12_FORMAT_SUPPORT1_BACK_BUFFER_CAST:0x1000000`

Format supports casting when the resource is a back buffer.

### `D3D12_FORMAT_SUPPORT1_TYPED_UNORDERED_ACCESS_VIEW:0x2000000`

Format can be used for an unordered access view.

### `D3D12_FORMAT_SUPPORT1_SHADER_GATHER_COMPARISON:0x4000000`

Format can be used with the HLSL gather with comparison function.

### `D3D12_FORMAT_SUPPORT1_DECODER_OUTPUT:0x8000000`

Format can be used with the decoder output.

### `D3D12_FORMAT_SUPPORT1_VIDEO_PROCESSOR_OUTPUT:0x10000000`

Format can be used with the video processor output.

### `D3D12_FORMAT_SUPPORT1_VIDEO_PROCESSOR_INPUT:0x20000000`

Format can be used with the video processor input.

### `D3D12_FORMAT_SUPPORT1_VIDEO_ENCODER:0x40000000`

Format can be used with the video encoder.

## Remarks

This enum is used by the [D3D12_FEATURE_DATA_FORMAT_SUPPORT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_format_support) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[D3D12_HEAP_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags)