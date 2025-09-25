# D3D11_BIND_FLAG enumeration

## Description

Identifies how to bind a resource to the pipeline.

## Constants

### `D3D11_BIND_VERTEX_BUFFER:0x1L`

Bind a buffer as a vertex buffer to the input-assembler stage.

### `D3D11_BIND_INDEX_BUFFER:0x2L`

Bind a buffer as an index buffer to the input-assembler stage.

### `D3D11_BIND_CONSTANT_BUFFER:0x4L`

Bind a buffer as a constant buffer to a shader stage; this flag may NOT be combined with any other bind flag.

### `D3D11_BIND_SHADER_RESOURCE:0x8L`

Bind a buffer or texture to a shader stage; this flag cannot be used with the [D3D11_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map) flag.

**Note** The Direct3D 11.1 runtime, which is available starting with Windows 8, enables mapping dynamic constant buffers and shader resource views (SRVs) of dynamic buffers with [D3D11_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map). The Direct3D 11 and earlier runtimes limited mapping to vertex or index buffers. To determine if a Direct3D device supports these features, call [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) with [D3D11_FEATURE_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature). **CheckFeatureSupport** fills members of a [D3D11_FEATURE_DATA_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options) structure with the device's features. The relevant members here are **MapNoOverwriteOnDynamicConstantBuffer** and **MapNoOverwriteOnDynamicBufferSRV**.

### `D3D11_BIND_STREAM_OUTPUT:0x10L`

Bind an output buffer for the stream-output stage.

### `D3D11_BIND_RENDER_TARGET:0x20L`

Bind a texture as a render target for the output-merger stage.

### `D3D11_BIND_DEPTH_STENCIL:0x40L`

Bind a texture as a depth-stencil target for the output-merger stage.

### `D3D11_BIND_UNORDERED_ACCESS:0x80L`

Bind an [unordered access](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-cs-resources) resource.

### `D3D11_BIND_DECODER:0x200L`

Set this flag to indicate that a [2D texture](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-textures-intro) is used to receive output from the decoder API. The common way to create resources for a decoder output is by calling the [ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d) method to create an array of 2D textures. However, you cannot use texture arrays that are created with this flag in calls to [ID3D11Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createshaderresourceview).

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_BIND_VIDEO_ENCODER:0x400L`

Set this flag to indicate that a [2D texture](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-textures-intro) is used to receive input from the video encoder API. The common way to create resources for a video encoder is by calling the [ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d) method to create an array of 2D textures. However, you cannot use texture arrays that are created with this flag in calls to [ID3D11Device::CreateShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createshaderresourceview).

**Direct3D 11:** This value is not supported until Direct3D 11.1.

## Remarks

In general, binding flags can be combined using a bitwise OR (except the constant-buffer flag); however, you should use a single flag to allow the device to optimize the resource usage.

This enumeration is used by a:

* [Buffer description](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_desc) when creating a buffer.
* Texture description when creating a texture (see [D3D11_TEXTURE1D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture1d_desc) or [D3D11_TEXTURE2D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture2d_desc) or [D3D11_TEXTURE3D_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texture3d_desc)).

A shader-resource buffer is NOT a constant buffer; rather, it is a texture or buffer resource that is bound to a shader, that contains texture or buffer data (it is not limited to a single element type in the buffer). A shader-resource buffer is created with the D3D11_BIND_SHADER_RESOURCE flag and is bound to the pipeline using one of these APIs: [ID3D11DeviceContext::GSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-gssetshaderresources), [ID3D11DeviceContext::PSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-pssetshaderresources), or [ID3D11DeviceContext::VSSetShaderResources](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-vssetshaderresources). Furthermore, a shader-resource buffer cannot use the [D3D11_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map) flag.

**Note** The Direct3D 11.1 runtime, which is available starting with Windows 8, enables mapping dynamic constant buffers and shader resource views (SRVs) of dynamic buffers with [D3D11_MAP_WRITE_NO_OVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_map). The Direct3D 11 and earlier runtimes limited mapping to vertex or index buffers. To determine if a Direct3D device supports these features, call [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) with [D3D11_FEATURE_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature). **CheckFeatureSupport** fills members of a [D3D11_FEATURE_DATA_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options) structure with the device's features. The relevant members here are **MapNoOverwriteOnDynamicConstantBuffer** and **MapNoOverwriteOnDynamicBufferSRV**.

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)