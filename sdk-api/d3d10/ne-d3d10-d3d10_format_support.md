# D3D10_FORMAT_SUPPORT enumeration

## Description

Which resources are supported for a given format and given device (see [ID3D10Device::CheckFormatSupport](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-checkformatsupport)).

## Constants

### `D3D10_FORMAT_SUPPORT_BUFFER:0x1`

Buffer resources supported.

### `D3D10_FORMAT_SUPPORT_IA_VERTEX_BUFFER:0x2`

Vertex buffers supported.

### `D3D10_FORMAT_SUPPORT_IA_INDEX_BUFFER:0x4`

Index buffers supported.

### `D3D10_FORMAT_SUPPORT_SO_BUFFER:0x8`

Streaming output buffers supported.

### `D3D10_FORMAT_SUPPORT_TEXTURE1D:0x10`

1D texture resources supported.

### `D3D10_FORMAT_SUPPORT_TEXTURE2D:0x20`

2D texture resources supported.

### `D3D10_FORMAT_SUPPORT_TEXTURE3D:0x40`

3D texture resources supported.

### `D3D10_FORMAT_SUPPORT_TEXTURECUBE:0x80`

Cube texture resources supported.

### `D3D10_FORMAT_SUPPORT_SHADER_LOAD:0x100`

The intrinsic HLSL function [load](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-load) is supported.

### `D3D10_FORMAT_SUPPORT_SHADER_SAMPLE:0x200`

The intrinsic HLSL functions [Sample](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-sample) supported.

### `D3D10_FORMAT_SUPPORT_SHADER_SAMPLE_COMPARISON:0x400`

The intrinsic HLSL functions [SampleCmp](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmp)
and [SampleCmpLevelZero](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmplevelzero) are supported.

### `D3D10_FORMAT_SUPPORT_SHADER_SAMPLE_MONO_TEXT:0x800`

Reserved.

### `D3D10_FORMAT_SUPPORT_MIP:0x1000`

Mipmaps are supported.

### `D3D10_FORMAT_SUPPORT_MIP_AUTOGEN:0x2000`

Automatic generation of mipmaps is supported.

### `D3D10_FORMAT_SUPPORT_RENDER_TARGET:0x4000`

Rendertargets are supported.

### `D3D10_FORMAT_SUPPORT_BLENDABLE:0x8000`

Render target blend operations supported.

### `D3D10_FORMAT_SUPPORT_DEPTH_STENCIL:0x10000`

Depth stencils supported.

### `D3D10_FORMAT_SUPPORT_CPU_LOCKABLE:0x20000`

CPU locking supported.

### `D3D10_FORMAT_SUPPORT_MULTISAMPLE_RESOLVE:0x40000`

Multisampling resolution supported.

### `D3D10_FORMAT_SUPPORT_DISPLAY:0x80000`

Format can be displayed on screen.

### `D3D10_FORMAT_SUPPORT_CAST_WITHIN_BIT_LAYOUT:0x100000`

Format cannot be cast to another format.

### `D3D10_FORMAT_SUPPORT_MULTISAMPLE_RENDERTARGET:0x200000`

Format can be used as a multisampled rendertarget.

### `D3D10_FORMAT_SUPPORT_MULTISAMPLE_LOAD:0x400000`

Format can be used as a multisampled texture and read into a shader with the [load](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-load) function.

### `D3D10_FORMAT_SUPPORT_SHADER_GATHER:0x800000`

Format can be used with the [gather](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-gather) function. This value is available in DirectX 10.1 or higher.

### `D3D10_FORMAT_SUPPORT_BACK_BUFFER_CAST:0x1000000`

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)