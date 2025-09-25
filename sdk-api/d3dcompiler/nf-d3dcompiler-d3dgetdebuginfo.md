# D3DGetDebugInfo function

## Description

**Note** You can use this API to develop your Windows Store apps, but you can't use it in apps that you submit to the Windows Store.

Gets shader debug information.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to source data; either uncompiled or compiled HLSL code.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of *pSrcData*.

### `ppDebugInfo` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a buffer that receives the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that contains debug information.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

Debug information is embedded in the body of the shader after calling [D3DCompile](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)