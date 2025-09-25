# ID3D11Linker::Link

## Description

Links the shader and produces a shader blob that the Direct3D runtime can use.

## Parameters

### `pEntry` [in]

Type: **[ID3D11ModuleInstance](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11moduleinstance)***

A pointer to the [ID3D11ModuleInstance](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11moduleinstance) interface for the shader module instance to link from.

### `pEntryName` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the shader module instance to link from.

### `pTargetName` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name for the shader blob that is produced.

### `uFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved.

### `ppShaderBlob` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a variable that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access the compiled shader code.

### `ppErrorBuffer` [out, optional]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a variable that receives a pointer to the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that you can use to access compiler error messages.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11Linker](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linker)