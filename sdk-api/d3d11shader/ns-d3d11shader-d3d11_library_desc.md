# D3D11_LIBRARY_DESC structure

## Description

Describes a library.

## Members

### `Creator`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the originator of the library.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3DCOMPILE Constants](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-constants) that are combined by using a bitwise OR operation. The resulting value specifies how the compiler compiles.

### `FunctionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of functions exported from the library.

## See also

[ID3D11LibraryReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11libraryreflection-getdesc)

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)