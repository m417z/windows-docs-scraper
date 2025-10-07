# CD3DX12\_ROOT\_DESCRIPTOR1 structure

A helper structure to enable easy initialization of a [**D3D12\_ROOT\_DESCRIPTOR1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor1) structure.

## Members

**CD3DX12\_ROOT\_DESCRIPTOR1()**

Creates a new, uninitialized, instance of a CD3DX12\_ROOT\_DESCRIPTOR1.

**explicit CD3DX12\_ROOT\_DESCRIPTOR1(const D3D12\_ROOT\_DESCRIPTOR1 &o)**

Creates a new instance of a CD3DX12\_ROOT\_DESCRIPTOR1, initialized with the contents of another [**D3D12\_ROOT\_DESCRIPTOR1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor1) structure.

**CD3DX12\_ROOT\_DESCRIPTOR1(UINT shaderRegister, UINT registerSpace = 0, D3D12\_ROOT\_DESCRIPTOR\_FLAGS flags = D3D12\_ROOT\_DESCRIPTOR\_FLAG\_NONE)**

Creates a new instance of a CD3DX12\_ROOT\_DESCRIPTOR1, initializing the following parameters:

UINT shaderRegister

UINT registerSpace = 0

[**D3D12\_ROOT\_DESCRIPTOR\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_descriptor_flags) flags = D3D12\_ROOT\_DESCRIPTOR\_FLAG\_NONE

**inline Init(UINT shaderRegister, UINT registerSpace = 0, D3D12\_ROOT\_DESCRIPTOR\_FLAGS flags = D3D12\_ROOT\_DESCRIPTOR\_FLAG\_NONE)**

Specifies a function that initializes the following parameters:

UINT shaderRegister

UINT registerSpace = 0

[**D3D12\_ROOT\_DESCRIPTOR\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_descriptor_flags) flags = D3D12\_ROOT\_DESCRIPTOR\_FLAG\_NONE

**static inline Init(D3D12\_ROOT\_DESCRIPTOR1 &table, UINT shaderRegister, UINT registerSpace = 0, D3D12\_ROOT\_DESCRIPTOR\_FLAGS flags = D3D12\_ROOT\_DESCRIPTOR\_FLAG\_NONE)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_DESCRIPTOR1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor1) &table

UINT shaderRegister

UINT registerSpace = 0

[**D3D12\_ROOT\_DESCRIPTOR\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_descriptor_flags) flags = D3D12\_ROOT\_DESCRIPTOR\_FLAG\_NONE

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_ROOT\_DESCRIPTOR1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor1)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

