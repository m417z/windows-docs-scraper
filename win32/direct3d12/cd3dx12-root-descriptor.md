# CD3DX12\_ROOT\_DESCRIPTOR structure

A helper structure to enable easy initialization of a [**D3D12\_ROOT\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor) structure.

## Members

**CD3DX12\_ROOT\_DESCRIPTOR()**

Creates a new, uninitialized, instance of a CD3DX12\_ROOT\_DESCRIPTOR.

**explicit CD3DX12\_ROOT\_DESCRIPTOR(const D3D12\_ROOT\_DESCRIPTOR &o)**

Creates a new instance of a CD3DX12\_ROOT\_DESCRIPTOR, initialized with the contents of another [**D3D12\_ROOT\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor) structure.

**CD3DX12\_ROOT\_DESCRIPTOR(UINT shaderRegister, UINT registerSpace = 0)**

Creates a new instance of a CD3DX12\_ROOT\_DESCRIPTOR, initializing the following parameters:

UINT shaderRegister

(opt) UINT registerSpace = 0

**inline Init(UINT shaderRegister, UINT registerSpace = 0)**

Specifies a function that initializes the following parameters:

UINT shaderRegister

(opt) UINT registerSpace = 0

**static inline Init(D3D12\_ROOT\_DESCRIPTOR &table, UINT shaderRegister, UINT registerSpace = 0)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor) &table

UINT shaderRegister

(opt) UINT registerSpace = 0

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_ROOT\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

