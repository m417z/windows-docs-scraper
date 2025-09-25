# D3DDecompressShaders function

## Description

**Note** You can use this API to develop your Windows Store apps, but you can't use it in apps that you submit to the Windows Store.

Decompresses one or more shaders from a compressed set.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to uncompiled shader data; either ASCII HLSL code or a compiled effect.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of uncompiled shader data that *pSrcData* points to.

### `uNumShaders` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of shaders to decompress.

### `uStartIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first shader to decompress.

### `pIndices` [in, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

An array of indexes that represent the shaders to decompress.

### `uFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that indicate how to decompress. Currently, no flags are defined.

### `ppShaders` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

The address of a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that is used to retrieve the decompressed shader data.

### `pTotalShaders` [out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that receives the total number of shaders that **D3DDecompressShaders** decompressed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)