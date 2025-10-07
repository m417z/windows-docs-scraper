# CD3DX12\_PIPELINE\_STATE\_STREAM\_IB\_STRIP\_CUT\_VALUE structure

A helper structure used to describe the index buffer strip cut value as a single object suitable for a stream description.

## Members

**CD3DX12\_PIPELINE\_STATE\_STREAM\_IB\_STRIP\_CUT\_VALUE**

Creates a new, uninitialized, instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_IB\_STRIP\_CUT\_VALUE.

**CD3DX12\_PIPELINE\_STATE\_STREAM\_IB\_STRIP\_CUT\_VALUE(D3D12\_INDEX\_BUFFER\_STRIP\_CUT\_VALUE const &i)**

Creates a new instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_IB\_STRIP\_CUT\_VALUE, initialized with a subobject type of **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE\_IB\_STRIP\_CUT\_VALUE** and subobject data copied from *i*, a [**D3D12\_INDEX\_BUFFER\_STRIP\_CUT\_VALUE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_index_buffer_strip_cut_value) structure.

**operator=(D3D12\_INDEX\_BUFFER\_STRIP\_CUT\_VALUE const& i)**

Copy-assignment operator.

**operator D3D12\_INDEX\_BUFFER\_STRIP\_CUT\_VALUE() const**

Implicit conversion to a [**D3D12\_INDEX\_BUFFER\_STRIP\_CUT\_VALUE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_index_buffer_strip_cut_value) structure.

## Remarks

CD3DX12\_PIPELINE\_STATE\_STREAM\_IB\_STRIP\_CUT\_VALUE is a typedef specialization of the [**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) template, and is defined as follows:

```C++
typedef CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT<D3D12_INDEX_BUFFER_STRIP_CUT_VALUE, D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE>
    CD3DX12_PIPELINE_STATE_STREAM_IB_STRIP_CUT_VALUE;

```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject)

[**D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type)

