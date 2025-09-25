# D3D12_LIBRARY_DESC structure

## Description

Describes a library.

## Members

### `Creator`

The name of the originator of the library.

### `Flags`

A combination of [D3DCOMPILE Constants](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-constants) that are combined by using a bitwise OR operation. The resulting value specifies how the compiler compiles.

### `FunctionCount`

The number of functions exported from the library.

## Remarks

This structure is returned by [ID3D12LibraryReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12libraryreflection-getdesc).

## See also

[ID3D12LibraryReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12libraryreflection-getdesc)

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-shader-structures)