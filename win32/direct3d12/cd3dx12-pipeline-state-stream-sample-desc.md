# CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_DESC structure

A helper structure used to describe a sample description as a single object suitable for a stream description.

## Members

**CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_DESC**

Creates a new, uninitialized, instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_DESC.

**CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_DESC(DXGI\_SAMPLE\_DESC const &i)**

Creates a new instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_DESC, initialized with a subobject type of **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE\_SAMPLE\_DESC** and subobject data copied from *i*, a [**DXGI\_SAMPLE\_DESC**](https://www.bing.com/search?q=**DXGI/_SAMPLE/_DESC**) structure.

**operator=(DXGI\_SAMPLE\_DESC const& i)**

Copy-assignment operator.

**operator DXGI\_SAMPLE\_DESC() const**

Implicit conversion to a [**DXGI\_SAMPLE\_DESC**](https://www.bing.com/search?q=**DXGI/_SAMPLE/_DESC**) structure.

## Remarks

CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_DESC is a typedef specialization of the [**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) template, and is defined as follows:

```C++
typedef CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT<DXGI_SAMPLE_DESC, D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_DESC>
    CD3DX12_PIPELINE_STATE_STREAM_SAMPLE_DESC;

```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject)

[**D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type)

