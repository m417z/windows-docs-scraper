# D3DGetBlobPart function

## Description

Retrieves a specific part from a compilation result.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to uncompiled shader data; either ASCII HLSL code or a compiled effect.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of uncompiled shader data that *pSrcData* points to.

### `Part` [in]

Type: **[D3D_BLOB_PART](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3d-blob-part)**

A [D3D_BLOB_PART](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3d-blob-part)-typed value that specifies the part of the buffer to retrieve.

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that indicate how to retrieve the blob part. Currently, no flags are defined.

### `ppPart` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

The address of a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that is used to retrieve the specified part of the buffer.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**D3DGetBlobPart** retrieves the part of a blob (arbitrary length data buffer) that contains the type of data that the *Part* parameter specifies.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)