# CD3DX12\_SHADER\_BYTECODE structure

A helper structure to enable easy initialization of a [**D3D12\_SHADER\_BYTECODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_bytecode) structure.

## Members

**CD3DX12\_SHADER\_BYTECODE()**

Creates a new, uninitialized, instance of a CD3DX12\_SHADER\_BYTECODE.

**explicit CD3DX12\_SHADER\_BYTECODE(const D3D12\_SHADER\_BYTECODE &o)**

Creates a new instance of a CD3DX12\_SHADER\_BYTECODE, initialized with the contents of another [**D3D12\_SHADER\_BYTECODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_bytecode) structure.

**CD3DX12\_SHADER\_BYTECODE(ID3DBlob\* pShaderBlob)**

Creates a new instance of a CD3DX12\_SHADER\_BYTECODE, initializing the following parameters:

[**ID3DBlob**](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))\* pShaderBlob

**CD3DX12\_SHADER\_BYTECODE(const void\* \_pShaderBytecode, SIZE\_T bytecodeLength)**

Creates a new instance of a CD3DX12\_SHADER\_BYTECODE, initializing the following parameters:

void\* \_pShaderBytecode

SIZE\_T bytecodeLength

**operator const D3D12\_SHADER\_BYTECODE&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_SHADER\_BYTECODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_bytecode)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

