# CD3DX12\_RECT structure

A helper structure to enable easy initialization of a [**D3D12\_RECT**](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-rect) structure.

## Members

**CD3DX12\_RECT()**

Creates a new, uninitialized, instance of a CD3DX12\_RECT.

**explicit CD3DX12\_RECT(const D3D12\_RECT& o)**

Creates a new instance of a CD3DX12\_RECT, initialized with the contents of another [**D3D12\_RECT**](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-rect) structure.

**explicit CD3DX12\_RECT(LONG Left, LONG Top, LONG Right, LONG Bottom)**

Creates a new instance of a CD3DX12\_RECT, initializing the following parameters:

LONG Left

LONG Top

LONG Right

LONG Bottom

**~CD3DX12\_RECT()**

Destroys an instance of a CD3DX12\_RECT.

**operator const D3D12\_RECT&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_RECT**](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-rect)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

