# CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_MASK structure

A helper structure used to describe a sample mask as a single object suitable for a stream description.

## Members

**CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_MASK**

Creates a new, uninitialized, instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_MASK.

**CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_MASK(UINT const &i)**

Creates a new instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_MASK, initialized with a subobject type of **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE\_SAMPLE\_MASK** and subobject data copied from *i*, a **UINT** sample mask.

**operator=(UINT const& i)**

Copy-assignment operator.

**operator UINT() const**

Implicit conversion to a **UINT** sample mask.

## Remarks

CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_MASK is a typedef specialization of the [**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) template, and is defined as follows:

```C++
typedef CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT<UINT, D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_MASK>
    CD3DX12_PIPELINE_STATE_STREAM_SAMPLE_MASK;

```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject)

[**D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type)

