# CD3DX12\_VIEWPORT structure

\[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.\]

A helper structure to enable easy initialization of a [**D3D12\_VIEWPORT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_viewport) structure.

## Members

**CD3DX12\_VIEWPORT()**

Creates a new, uninitialized, instance of a CD3DX12\_VIEWPORT.

**explicit CD3DX12\_VIEWPORT(const D3D12\_VIEWPORT& o)**

Creates a new instance of a CD3DX12\_VIEWPORT, initializing the following parameters:

const D3D12\_VIEWPORT& o

**explicit CD3DX12\_VIEWPORT(FLOAT topLeftX, FLOAT topLeftY, FLOAT width, FLOAT height, FLOAT minDepth = D3D12\_MIN\_DEPTH, FLOAT maxDepth = D3D12\_MAX\_DEPTH)**

Creates a new instance of a CD3DX12\_VIEWPORT, initializing the following parameters:

FLOAT topLeftX

FLOAT topLeftY

FLOAT width

FLOAT height

FLOAT minDepth = D3D12\_MIN\_DEPTH

FLOAT maxDepth = D3D12\_MAX\_DEPTH

**explicit CD3DX12\_VIEWPORT(ID3D12Resource\* pResource, UINT mipSlice = 0, FLOAT topLeftX = 0.0f, FLOAT topLeftY = 0.0f, FLOAT minDepth = D3D12\_MIN\_DEPTH, FLOAT maxDepth = D3D12\_MAX\_DEPTH)**

Creates a new instance of a CD3DX12\_VIEWPORT, initializing the following parameters:

ID3D12Resource\* pResource

UINT mipSlice = 0

FLOAT topLeftX = 0.0f

FLOAT topLeftY = 0.0f

FLOAT minDepth = D3D12\_MIN\_DEPTH

FLOAT maxDepth = D3D12\_MAX\_DEPTH

**~CD3DX12\_VIEWPORT()**

Destroys an instance of a D3DX12\_VIEWPORT.

**operator const D3D12\_VIEWPORT&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_VIEWPORT**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_viewport)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

