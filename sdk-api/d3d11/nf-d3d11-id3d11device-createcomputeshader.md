# ID3D11Device::CreateComputeShader

## Description

Create a [compute shader](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-compute-shader).

## Parameters

### `pShaderBytecode` [in]

Type: **const void***

A pointer to a compiled shader.

### `BytecodeLength` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the compiled shader in *pShaderBytecode*.

### `pClassLinkage` [in, optional]

Type: **[ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage)***

A pointer to a [ID3D11ClassLinkage](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11classlinkage), which represents class linkage interface; the value can be **NULL**.

### `ppComputeShader` [out, optional]

Type: **[ID3D11ComputeShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11computeshader)****

Address of a pointer to an [ID3D11ComputeShader](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11computeshader) interface. If this is **NULL**,
all other parameters will be validated; if validation passes, CreateComputeShader returns S_FALSE instead of S_OK.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns E_OUTOFMEMORY if there is insufficient memory to create the compute shader.
See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## Remarks

For an example, see [How To: Create a Compute Shader](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-advanced-stages-compute-create) and [HDRToneMappingCS11 Sample](https://msdn.microsoft.com/library/Ee416569(v=VS.85).aspx).

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)