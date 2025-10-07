# CD3DX12\_PIPELINE\_STATE\_STREAM\_PRIMITIVE\_TOPOLOGY structure

A helper structure used to describe the primitive topology as a single object suitable for a stream description.

## Members

**CD3DX12\_PIPELINE\_STATE\_STREAM\_PRIMITIVE\_TOPOLOGY**

Creates a new, uninitialized, instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_PRIMITIVE\_TOPOLOGY.

**CD3DX12\_PIPELINE\_STATE\_STREAM\_PRIMITIVE\_TOPOLOGY(D3D12\_PRIMITIVE\_TOPOLOGY\_TYPE const &i)**

Creates a new instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_PRIMITIVE\_TOPOLOGY, initialized with a subobject type of **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE\_PRIMITIVE\_TOPOLOGY** and subobject data copied from *i*, a [**D3D12\_PRIMITIVE\_TOPOLOGY\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_primitive_topology_type) structure.

**operator=(D3D12\_PRIMITIVE\_TOPOLOGY\_TYPE const& i)**

Copy-assignment operator.

**operator D3D12\_PRIMITIVE\_TOPOLOGY\_TYPE() const**

Implicit conversion to a [**D3D12\_PRIMITIVE\_TOPOLOGY\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_primitive_topology_type) structure.

## Remarks

CD3DX12\_PIPELINE\_STATE\_STREAM\_PRIMITIVE\_TOPOLOGY is a typedef specialization of the [**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) template, and is defined as follows:

```C++
typedef CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT<D3D12_PRIMITIVE_TOPOLOGY_TYPE, D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY>
    CD3DX12_PIPELINE_STATE_STREAM_PRIMITIVE_TOPOLOGY;

```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject)

[**D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type)

