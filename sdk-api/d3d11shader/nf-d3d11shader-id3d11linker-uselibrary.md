# ID3D11Linker::UseLibrary

## Description

Adds an instance of a library module to be used for linking.

## Parameters

### `pLibraryMI` [in]

Type: **[ID3D11ModuleInstance](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11moduleinstance)***

A pointer to the [ID3D11ModuleInstance](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11moduleinstance) interface for the library module instance.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11Linker](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nn-d3d11shader-id3d11linker)