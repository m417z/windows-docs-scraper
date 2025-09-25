# ID3D11Module::CreateInstance

## Description

Initializes an instance of a shader module that is used for resource rebinding.

## Parameters

### `pNamespace` [in, optional]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of a shader module to initialize. This can be **NULL** if you don't want to specify a name for the module.

### `ppModuleInstance` [out]

Type: **[ID3D11ModuleInstance](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11moduleinstance)****

The address of a pointer to an [ID3D11ModuleInstance](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11moduleinstance) interface to initialize.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11Module](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11module)