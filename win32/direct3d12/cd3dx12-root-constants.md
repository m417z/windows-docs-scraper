# CD3DX12\_ROOT\_CONSTANTS structure

A helper structure to enable easy initialization of a [**D3D12\_ROOT\_CONSTANTS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_constants) structure.

## Members

**CD3DX12\_ROOT\_CONSTANTS()**

Creates a new, uninitialized, instance of a CD3DX12\_ROOT\_CONSTANTS.

**explicit CD3DX12\_ROOT\_CONSTANTS(const D3D12\_ROOT\_CONSTANTS &o)**

Creates a new instance of a CD3DX12\_ROOT\_CONSTANTS, initialized with the contents of another [**D3D12\_ROOT\_CONSTANTS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_constants) structure.

**CD3DX12\_ROOT\_CONSTANTS(UINT num32BitValues, UINT shaderRegister, UINT registerSpace = 0)**

Creates a new instance of a CD3DX12\_ROOT\_CONSTANTS, initializing the following parameters:

UINT num32BitValues

UINT shaderRegister

(opt) UINT registerSpace = 0

**inline Init(UINT num32BitValues, UINT shaderRegister, UINT registerSpace = 0)**

Specifies a function that initializes the following parameters:

UINT num32BitValues

UINT shaderRegister

(opt) UINT registerSpace = 0

**static inline Init(D3D12\_ROOT\_CONSTANTS &rootConstants, UINT num32BitValues, UINT shaderRegister, UINT registerSpace = 0)**

Specifies a function that initializes the following parameters:

[**D3D12\_ROOT\_CONSTANTS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_constants) &rootConstants

UINT num32BitValues

UINT shaderRegister

(opt) UINT registerSpace = 0

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_ROOT\_CONSTANTS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_constants)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

