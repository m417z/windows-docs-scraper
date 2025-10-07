# CD3DX12\_BOX structure

A helper structure to enable easy initialization of a [**D3D12\_BOX**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_box) structure.

## Members

**CD3DX12\_BOX()**

Creates a new, uninitialized, instance of a CD3DX12\_BOX.

**explicit CD3DX12\_BOX(const D3D12\_BOX& o)**

Creates a new instance of a CD3DX12\_BOX, initialized with the contents of another [**D3D12\_BOX**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_box) structure.

**explicit CD3DX12\_BOX(LONG Left, LONG Right)**

Creates a new instance of a CD3DX12\_BOX, initializing the following parameters:

LONG Left

LONG Right

**explicit CD3DX12\_BOX(LONG Left, LONG Top, LONG Right, LONG Bottom)**

Creates a new instance of a CD3DX12\_BOX, initializing the following parameters:

LONG Left

LONG Top

LONG Right

LONG Bottom

**explicit CD3DX12\_BOX(LONG Left, LONG Top, LONG Front, LONG Right, LONG Bottom, LONG Back)**

Creates a new instance of a CD3DX12\_BOX, initializing the following parameters:

LONG Left

LONG Top

LONG Front

LONG Right

LONG Bottom

LONG Back

**~CD3DX12\_BOX()**

Destroys an instance of a CD3DX12\_BOX.

**operator const D3D12\_BOX&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_BOX**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_box)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

