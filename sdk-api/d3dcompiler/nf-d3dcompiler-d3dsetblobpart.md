# D3DSetBlobPart function

## Description

Sets information in a compilation result.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to compiled shader data.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The length of the compiled shader data that *pSrcData* points to.

### `Part` [in]

Type: **[D3D_BLOB_PART](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3d-blob-part)**

A [D3D_BLOB_PART](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3d-blob-part)-typed value that specifies the part to set. Currently, you can update only private data; that is, **D3DSetBlobPart** currently only supports the [D3D_BLOB_PRIVATE_DATA](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3d-blob-part) value.

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that indicate how to set the blob part. Currently, no flags are defined; therefore, set to zero.

### `pPart` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to data to set in the compilation result.

### `PartSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The length of the data that *pPart* points to.

### `ppNewShader` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a buffer that receives the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface for the new shader in which the new part data is set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**D3DSetBlobPart** modifies data in a compiled shader. Currently, **D3DSetBlobPart** can update only the private data in a compiled shader. You can use **D3DSetBlobPart** to attach arbitrary uninterpreted data to a compiled shader.

**Note** The D3dcompiler_44.dll or later version of the file contains the **D3DSetBlobPart** compiler function.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)