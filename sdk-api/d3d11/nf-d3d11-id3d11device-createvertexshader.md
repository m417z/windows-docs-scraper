# ID3D11Device::CreateVertexShader

## Description

Create a vertex-shader object from a compiled shader.

## Parameters

### `pShaderBytecode` [in]

Type: **const void***

A pointer to the compiled shader.

### `BytecodeLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the compiled vertex shader.

### `pClassLinkage` [in, optional]

Type: **[ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)***

A pointer to a class linkage interface (see [ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)); the value can be **NULL**.

### `ppVertexShader` [out, optional]

Type: **[ID3D11VertexShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11vertexshader)****

Address of a pointer to a [ID3D11VertexShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11vertexshader) interface. If this is **NULL**, all other parameters will be validated, and if all parameters pass validation this API will return **S_FALSE** instead of **S_OK**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The Direct3D 11.1 runtime, which is available starting with Windows 8, provides the following new functionality for **CreateVertexShader**.

The following shader model 5.0 instructions are available to just pixel shaders and compute shaders in the Direct3D 11.0 runtime. For the Direct3D 11.1 runtime, because unordered access views (UAV) are available at all shader stages, you can use these instructions in all shader stages.

Therefore, if you use the following shader model 5.0 instructions in a vertex shader, you can successfully pass the compiled vertex shader to *pShaderBytecode*. That is, the call to **CreateVertexShader** succeeds.

If you pass a compiled shader to *pShaderBytecode* that uses any of the following instructions on a device that doesn’t support UAVs at every shader stage (including existing drivers that are not implemented to support UAVs at every shader stage), **CreateVertexShader** fails. **CreateVertexShader** also fails if the shader tries to use a UAV slot beyond the set of UAV slots that the hardware supports.

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

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)