# D3DCompressShaders function

## Description

**Note** You can use this API to develop your Windows Store apps, but you can't use it in apps that you submit to the Windows Store.

Compresses a set of shaders into a more compact form.

## Parameters

### `uNumShaders` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of shaders to compress.

### `pShaderData` [in]

Type: [D3D_SHADER_DATA](https://learn.microsoft.com/windows/win32/api/d3dcompiler/ns-d3dcompiler-d3d_shader_data)*

An array of [D3D_SHADER_DATA](https://learn.microsoft.com/windows/win32/api/d3dcompiler/ns-d3dcompiler-d3d_shader_data) structures that describe the set of shaders to compress.

### `uFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that indicate how to compress the shaders. Currently, only the D3D_COMPRESS_SHADER_KEEP_ALL_PARTS (0x00000001) flag is defined.

### `ppCompressedData` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

The address of a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that is used to retrieve the compressed shader data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)