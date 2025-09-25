# D3DWriteBlobToFile function

## Description

**Note** You can use this API to develop your Windows Store apps, but you can't use it in apps that you submit to the Windows Store.

Writes a memory blob to a file on disk.

## Parameters

### `pBlob` [in]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))***

A pointer to a [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that contains the memory blob to write to the file that the *pFileName* parameter specifies.

### `pFileName` [in]

Type: **LPCWSTR**

A pointer to a constant null-terminated string that contains the name of the file to which to write.

### `bOverwrite` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean value that specifies whether to overwrite information in the *pFileName* file. TRUE specifies to overwrite information and FALSE specifies not to overwrite information.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**Note** The D3dcompiler_44.dll or later version of the file contains the **D3DWriteBlobToFile** compiler function.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)