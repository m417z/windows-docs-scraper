# D3DGetInputAndOutputSignatureBlob function

## Description

**Note** **D3DGetInputAndOutputSignatureBlob** may be altered or unavailable for releases after Windows 8.1. Instead use [D3DGetBlobPart](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dgetblobpart) with the [D3D_BLOB_INPUT_AND_OUTPUT_SIGNATURE_BLOB](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3d-blob-part) value.

Gets the input and output signatures from a compilation result.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to source data as compiled HLSL code.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of *pSrcData*.

### `ppSignatureBlob` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a buffer that receives the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that contains a compiled shader.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)