# CD3DX12\_RESOURCE\_BARRIER structure

A helper structure to enable easy initialization of a [**D3D12\_RESOURCE\_BARRIER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_barrier) structure.

## Members

**CD3DX12\_RESOURCE\_BARRIER()**

Creates a new, uninitialized, instance of a CD3DX12\_RESOURCE\_BARRIER.

**explicit CD3DX12\_RESOURCE\_BARRIER(const D3D12\_RESOURCE\_BARRIER &o)**

Creates a new instance of a CD3DX12\_RESOURCE\_BARRIER, initialized with the contents of another [**D3D12\_RESOURCE\_BARRIER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_barrier).

**static inline Transition(ID3D12Resource\* pResource, D3D12\_RESOURCE\_STATES stateBefore, D3D12\_RESOURCE\_STATES stateAfter, UINT subresource = D3D12\_RESOURCE\_BARRIER\_ALL\_SUBRESOURCES, D3D12\_RESOURCE\_BARRIER\_FLAGS flags = D3D12\_RESOURCE\_BARRIER\_FLAG\_NONE)**

Transitions between resource states, using the following parameters:

[**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)\* pResource

[**D3D12\_RESOURCE\_STATES**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) stateBefore

[**D3D12\_RESOURCE\_STATES**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) stateAfter

(opt) UINT subresource = [**D3D12\_RESOURCE\_BARRIER\_ALL\_SUBRESOURCES**](https://learn.microsoft.com/windows/win32/direct3d12/constants)

(opt) [**D3D12\_RESOURCE\_BARRIER\_FLAGS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_barrier_flags) flags = D3D12\_RESOURCE\_BARRIER\_FLAG\_NONE

**static inline Aliasing(ID3D12Resource\* pResourceBefore, ID3D12Resource\* pResourceAfter)**

Creates aliases for the resource before and after the barrier transition. Parameters:

[**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)\* pResourceBefore

[**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)\* pResourceAfter

**static inline UAV(ID3D12Resource\* pResource)**

Creates an unordered-access-view (UAV) for the resource. Parameters:

[**ID3D12Resource**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)\* pResource

**operator const D3D12\_RESOURCE\_BARRIER&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_RESOURCE\_BARRIER**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_barrier)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

