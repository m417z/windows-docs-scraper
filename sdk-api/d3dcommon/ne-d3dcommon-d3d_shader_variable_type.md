# D3D_SHADER_VARIABLE_TYPE enumeration

## Description

Values that identify various data, texture, and buffer types that can be assigned to a shader variable.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_SVT_VOID:0`

The variable is a void pointer.

### `D3D_SVT_BOOL:1`

The variable is a boolean.

### `D3D_SVT_INT:2`

The variable is an integer.

### `D3D_SVT_FLOAT:3`

The variable is a floating-point number.

### `D3D_SVT_STRING:4`

The variable is a string.

### `D3D_SVT_TEXTURE:5`

The variable is a texture.

### `D3D_SVT_TEXTURE1D:6`

The variable is a 1D texture.

### `D3D_SVT_TEXTURE2D:7`

The variable is a 2D texture.

### `D3D_SVT_TEXTURE3D:8`

The variable is a 3D texture.

### `D3D_SVT_TEXTURECUBE:9`

The variable is a texture cube.

### `D3D_SVT_SAMPLER:10`

The variable is a sampler.

### `D3D_SVT_SAMPLER1D:11`

The variable is a 1D sampler.

### `D3D_SVT_SAMPLER2D:12`

The variable is a 2D sampler.

### `D3D_SVT_SAMPLER3D:13`

The variable is a 3D sampler.

### `D3D_SVT_SAMPLERCUBE:14`

The variable is a cube sampler.

### `D3D_SVT_PIXELSHADER:15`

The variable is a pixel shader.

### `D3D_SVT_VERTEXSHADER:16`

The variable is a vertex shader.

### `D3D_SVT_PIXELFRAGMENT:17`

The variable is a pixel fragment.

### `D3D_SVT_VERTEXFRAGMENT:18`

The variable is a vertex fragment.

### `D3D_SVT_UINT:19`

The variable is an unsigned integer.

### `D3D_SVT_UINT8:20`

The variable is an 8-bit unsigned integer.

### `D3D_SVT_GEOMETRYSHADER:21`

The variable is a geometry shader.

### `D3D_SVT_RASTERIZER:22`

The variable is a rasterizer-state object.

### `D3D_SVT_DEPTHSTENCIL:23`

The variable is a depth-stencil-state object.

### `D3D_SVT_BLEND:24`

The variable is a blend-state object.

### `D3D_SVT_BUFFER:25`

The variable is a buffer.

### `D3D_SVT_CBUFFER:26`

The variable is a constant buffer.

### `D3D_SVT_TBUFFER:27`

The variable is a texture buffer.

### `D3D_SVT_TEXTURE1DARRAY:28`

The variable is a 1D-texture array.

### `D3D_SVT_TEXTURE2DARRAY:29`

The variable is a 2D-texture array.

### `D3D_SVT_RENDERTARGETVIEW:30`

The variable is a render-target view.

### `D3D_SVT_DEPTHSTENCILVIEW:31`

The variable is a depth-stencil view.

### `D3D_SVT_TEXTURE2DMS:32`

The variable is a 2D-multisampled texture.

### `D3D_SVT_TEXTURE2DMSARRAY:33`

The variable is a 2D-multisampled-texture array.

### `D3D_SVT_TEXTURECUBEARRAY:34`

The variable is a texture-cube array.

### `D3D_SVT_HULLSHADER:35`

The variable holds a compiled hull-shader binary.

### `D3D_SVT_DOMAINSHADER:36`

The variable holds a compiled domain-shader binary.

### `D3D_SVT_INTERFACE_POINTER:37`

The variable is an interface.

### `D3D_SVT_COMPUTESHADER:38`

The variable holds a compiled compute-shader binary.

### `D3D_SVT_DOUBLE:39`

The variable is a double precision (64-bit) floating-point number.

### `D3D_SVT_RWTEXTURE1D:40`

The variable is a 1D read-and-write texture.

### `D3D_SVT_RWTEXTURE1DARRAY:41`

The variable is an array of 1D read-and-write textures.

### `D3D_SVT_RWTEXTURE2D:42`

The variable is a 2D read-and-write texture.

### `D3D_SVT_RWTEXTURE2DARRAY:43`

The variable is an array of 2D read-and-write textures.

### `D3D_SVT_RWTEXTURE3D:44`

The variable is a 3D read-and-write texture.

### `D3D_SVT_RWBUFFER:45`

The variable is a read-and-write buffer.

### `D3D_SVT_BYTEADDRESS_BUFFER:46`

The variable is a byte-address buffer.

### `D3D_SVT_RWBYTEADDRESS_BUFFER:47`

The variable is a read-and-write byte-address buffer.

### `D3D_SVT_STRUCTURED_BUFFER:48`

The variable is a structured buffer.

For more information about structured buffer, see the **Remarks** section.

### `D3D_SVT_RWSTRUCTURED_BUFFER:49`

The variable is a read-and-write structured buffer.

### `D3D_SVT_APPEND_STRUCTURED_BUFFER:50`

The variable is an append structured buffer.

### `D3D_SVT_CONSUME_STRUCTURED_BUFFER:51`

The variable is a consume structured buffer.

### `D3D_SVT_MIN8FLOAT:52`

The variable is an 8-byte FLOAT.

### `D3D_SVT_MIN10FLOAT:53`

The variable is a 10-byte FLOAT.

### `D3D_SVT_MIN16FLOAT:54`

The variable is a 16-byte FLOAT.

### `D3D_SVT_MIN12INT:55`

The variable is a 12-byte INT.

### `D3D_SVT_MIN16INT:56`

The variable is a 16-byte INT.

### `D3D_SVT_MIN16UINT:57`

The variable is a 16-byte INT.

### `D3D10_SVT_VOID`

The variable is a void pointer.

### `D3D10_SVT_BOOL`

The variable is a boolean.

### `D3D10_SVT_INT`

The variable is an integer.

### `D3D10_SVT_FLOAT`

The variable is a floating-point number.

### `D3D10_SVT_STRING`

The variable is a string.

### `D3D10_SVT_TEXTURE`

The variable is a texture.

### `D3D10_SVT_TEXTURE1D`

The variable is a 1D texture.

### `D3D10_SVT_TEXTURE2D`

The variable is a 2D texture.

### `D3D10_SVT_TEXTURE3D`

The variable is a 3D texture.

### `D3D10_SVT_TEXTURECUBE`

The variable is a texture cube.

### `D3D10_SVT_SAMPLER`

The variable is a sampler.

### `D3D10_SVT_SAMPLER1D`

The variable is a 1D sampler.

### `D3D10_SVT_SAMPLER2D`

The variable is a 2D sampler.

### `D3D10_SVT_SAMPLER3D`

The variable is a 3D sampler.

### `D3D10_SVT_SAMPLERCUBE`

The variable is a cube sampler.

### `D3D10_SVT_PIXELSHADER`

The variable is a pixel shader.

### `D3D10_SVT_VERTEXSHADER`

The variable is a vertex shader.

### `D3D10_SVT_PIXELFRAGMENT`

The variable is a pixel fragment.

### `D3D10_SVT_VERTEXFRAGMENT`

The variable is a vertex fragment.

### `D3D10_SVT_UINT`

The variable is an unsigned integer.

### `D3D10_SVT_UINT8`

The variable is an 8-bit unsigned integer.

### `D3D10_SVT_GEOMETRYSHADER`

The variable is a geometry shader.

### `D3D10_SVT_RASTERIZER`

The variable is a rasterizer-state object.

### `D3D10_SVT_DEPTHSTENCIL`

The variable is a depth-stencil-state object.

### `D3D10_SVT_BLEND`

The variable is a blend-state object.

### `D3D10_SVT_BUFFER`

The variable is a buffer.

### `D3D10_SVT_CBUFFER`

The variable is a constant buffer.

### `D3D10_SVT_TBUFFER`

The variable is a texture buffer.

### `D3D10_SVT_TEXTURE1DARRAY`

The variable is a 1D-texture array.

### `D3D10_SVT_TEXTURE2DARRAY`

The variable is a 2D-texture array.

### `D3D10_SVT_RENDERTARGETVIEW`

The variable is a render-target view.

### `D3D10_SVT_DEPTHSTENCILVIEW`

The variable is a depth-stencil view.

### `D3D10_SVT_TEXTURE2DMS`

The variable is a 2D-multisampled texture.

### `D3D10_SVT_TEXTURE2DMSARRAY`

The variable is a 2D-multisampled-texture array.

### `D3D10_SVT_TEXTURECUBEARRAY`

The variable is a texture-cube array.

### `D3D11_SVT_HULLSHADER`

The variable holds a compiled hull-shader binary.

### `D3D11_SVT_DOMAINSHADER`

The variable holds a compiled domain-shader binary.

### `D3D11_SVT_INTERFACE_POINTER`

The variable is an interface.

### `D3D11_SVT_COMPUTESHADER`

The variable holds a compiled compute-shader binary.

### `D3D11_SVT_DOUBLE`

The variable is a double precision (64-bit) floating-point number.

### `D3D11_SVT_RWTEXTURE1D`

The variable is a 1D read-and-write texture.

### `D3D11_SVT_RWTEXTURE1DARRAY`

The variable is an array of 1D read-and-write textures.

### `D3D11_SVT_RWTEXTURE2D`

The variable is a 2D read-and-write texture.

### `D3D11_SVT_RWTEXTURE2DARRAY`

The variable is an array of 2D read-and-write textures.

### `D3D11_SVT_RWTEXTURE3D`

The variable is a 3D read-and-write texture.

### `D3D11_SVT_RWBUFFER`

The variable is a read-and-write buffer.

### `D3D11_SVT_BYTEADDRESS_BUFFER`

The variable is a byte-address buffer.

### `D3D11_SVT_RWBYTEADDRESS_BUFFER`

The variable is a read and write byte-address buffer.

### `D3D11_SVT_STRUCTURED_BUFFER`

The variable is a structured buffer.

### `D3D11_SVT_RWSTRUCTURED_BUFFER`

The variable is a read-and-write structured buffer.

### `D3D11_SVT_APPEND_STRUCTURED_BUFFER`

The variable is an append structured buffer.

### `D3D11_SVT_CONSUME_STRUCTURED_BUFFER`

The variable is a consume structured buffer.

### `D3D_SVT_FORCE_DWORD:0x7fffffff`

This value is not used by a programmer; it exists to force the enumeration to compile to 32 bits.

## Remarks

A call to the
[ID3D11ShaderReflectionType::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflectiontype-getdesc) method returns a
**D3D_SHADER_VARIABLE_TYPE** value in the **Type** member of a
[D3D11_SHADER_TYPE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_shader_type_desc) structure.

The types in a structured buffer describe the structure of the elements in the buffer.
The layout of these types generally match their C++ struct counterparts.
The following examples show structured buffers:

```
struct mystruct {float4 val; uint ind;}; RWStructuredBuffer<mystruct> rwbuf;
                                         RWStructuredBuffer<float3> rwbuf2;
```

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)