# ID3D11Device::CreateGeometryShaderWithStreamOutput

## Description

Creates a geometry shader that can write to streaming output buffers.

## Parameters

### `pShaderBytecode` [in]

Type: **const void***

A pointer to the compiled geometry shader for a standard geometry shader plus stream output. For info on how to get this pointer, see [Getting a Pointer to a Compiled Shader](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-using-shaders-10).

To create the stream output without using a geometry shader, pass a pointer to the output signature for the prior stage. To obtain this output signature, call the [D3DGetOutputSignatureBlob](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dgetoutputsignatureblob) compiler function. You can also pass a pointer to the compiled shader for the prior stage (for example, the [vertex-shader stage](https://learn.microsoft.com/previous-versions/bb205146(v=vs.85)) or [domain-shader stage](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-tessellation)). This compiled shader provides the output signature for the data.

### `BytecodeLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the compiled geometry shader.

### `pSODeclaration` [in, optional]

Type: **const [D3D11_SO_DECLARATION_ENTRY](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_so_declaration_entry)***

Pointer to a [D3D11_SO_DECLARATION_ENTRY](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_so_declaration_entry) array. Cannot be **NULL** if NumEntries > 0.

### `NumEntries` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of entries in the stream output declaration ( ranges from 0 to D3D11_SO_STREAM_COUNT * D3D11_SO_OUTPUT_COMPONENT_COUNT ).

### `pBufferStrides` [in, optional]

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

An array of buffer strides; each stride is the size of an element for that buffer.

### `NumStrides` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of strides (or buffers) in *pBufferStrides* (ranges from 0 to D3D11_SO_BUFFER_SLOT_COUNT).

### `RasterizedStream` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index number of the stream to be sent to the rasterizer stage (ranges from 0 to D3D11_SO_STREAM_COUNT - 1).
Set to D3D11_SO_NO_RASTERIZED_STREAM if no stream is to be rasterized.

### `pClassLinkage` [in, optional]

Type: **[ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)***

A pointer to a class linkage interface (see [ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)); the value can be **NULL**.

### `ppGeometryShader` [out, optional]

Type: **[ID3D11GeometryShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11geometryshader)****

Address of a pointer to an [ID3D11GeometryShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11geometryshader) interface, representing the geometry shader that was created.
Set this to **NULL** to validate the other parameters; if validation passes, the method will return S_FALSE instead of S_OK.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

For more info about using **CreateGeometryShaderWithStreamOutput**, see [Create a Geometry-Shader Object with Stream Output](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-stream-stage-getting-started).

The Direct3D 11.1 runtime, which is available starting with Windows 8, provides the following new functionality for **CreateGeometryShaderWithStreamOutput**.

The following shader model 5.0 instructions are available to just pixel shaders and compute shaders in the Direct3D 11.0 runtime. For the Direct3D 11.1 runtime, because unordered access views (UAV) are available at all shader stages, you can use these instructions in all shader stages.

Therefore, if you use the following shader model 5.0 instructions in a geometry shader, you can successfully pass the compiled geometry shader to *pShaderBytecode*. That is, the call to **CreateGeometryShaderWithStreamOutput** succeeds.

If you pass a compiled shader to *pShaderBytecode* that uses any of the following instructions on a device that doesn’t support UAVs at every shader stage (including existing drivers that are not implemented to support UAVs at every shader stage), **CreateGeometryShaderWithStreamOutput** fails. **CreateGeometryShaderWithStreamOutput** also fails if the shader tries to use a UAV slot beyond the set of UAV slots that the hardware supports.

* [dcl_uav_typed](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dcl-uav-typed--sm5---asm-)
* [dcl_uav_raw](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dcl-uav-raw--sm5---asm-)
* [dcl_uav_structured](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dcl-uav-structured--sm5---asm-)
* [ld_raw](https://learn.microsoft.com/windows/desktop/direct3dhlsl/ld-raw--sm5---asm-)
* [ld_structured](https://learn.microsoft.com/windows/desktop/direct3dhlsl/ld-structured--sm5---asm-)
* [ld_uav_typed](https://learn.microsoft.com/windows/desktop/direct3dhlsl/ld-uav-typed--sm5---asm-)
* [store_raw](https://learn.microsoft.com/windows/desktop/direct3dhlsl/store-raw--sm5---asm-)
* [store_structured](https://learn.microsoft.com/windows/desktop/direct3dhlsl/store-structured--sm5---asm-)
* [store_uav_typed](https://learn.microsoft.com/windows/desktop/direct3dhlsl/store-uav-typed--sm5---asm-)
* [sync_uglobal](https://learn.microsoft.com/windows/desktop/direct3dhlsl/sync--sm5---asm-)
* All atomics and immediate atomics (for example, [atomic_and](https://learn.microsoft.com/windows/desktop/direct3dhlsl/atomic-and--sm5---asm-) and [imm_atomic_and](https://learn.microsoft.com/windows/desktop/direct3dhlsl/imm-atomic-and--sm5---asm-))

**Windows Phone 8:** This API is supported.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)