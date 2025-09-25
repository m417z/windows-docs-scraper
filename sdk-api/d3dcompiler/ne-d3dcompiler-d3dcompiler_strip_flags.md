# D3DCOMPILER_STRIP_FLAGS enumeration

## Description

Strip flag options.

## Constants

### `D3DCOMPILER_STRIP_REFLECTION_DATA:0x00000001`

Remove reflection data.

### `D3DCOMPILER_STRIP_DEBUG_INFO:0x00000002`

Remove debug information.

### `D3DCOMPILER_STRIP_TEST_BLOBS:0x00000004`

Remove test blob data.

### `D3DCOMPILER_STRIP_PRIVATE_DATA:0x00000008`

**Note** This value is supported by the D3dcompiler_44.dll or later version of the file.

Remove private data.

### `D3DCOMPILER_STRIP_ROOT_SIGNATURE:0x00000010`

**Note** This value is supported by the D3dcompiler_47.dll or later version of the file.

Remove the root signature. Refer to [Specifying Root Signatures in HLSL](https://learn.microsoft.com/windows/desktop/direct3d12/specifying-root-signatures-in-hlsl) for more information on using Direct3D12 with HLSL.

### `D3DCOMPILER_STRIP_FORCE_DWORD:0x7fffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

These flags are used by [D3DStripShader](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dstripshader).

## See also

[Enumerations](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-enums)