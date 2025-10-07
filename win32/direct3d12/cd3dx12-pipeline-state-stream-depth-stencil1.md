# CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL1 structure

A helper structure used to describe a depth stencil description as a single object suitable for a stream description.

## Members

**CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL1**

Creates a new, uninitialized, instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL1.

**CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL1(CD3DX12\_DEPTH\_STENCIL\_DESC1 const &i)**

Creates a new instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL1, initialized with a subobject type of **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE\_DEPTH\_STENCIL1** and subobject data copied from *i*, a [**CD3DX12\_DEPTH\_STENCIL\_DESC1**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-depth-stencil-desc1) structure.

**operator=(CD3DX12\_DEPTH\_STENCIL\_DESC1 const& i)**

Copy-assignment operator.

**operator CD3DX12\_DEPTH\_STENCIL\_DESC1() const**

Implicit conversion to a [**CD3DX12\_DEPTH\_STENCIL\_DESC1**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-depth-stencil-desc1) structure.

## Remarks

CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL1 is a typedef specialization of the [**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) template, and is defined as follows:

```C++
typedef CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT<CD3DX12_DEPTH_STENCIL_DESC1, D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1, CD3DX12_DEFAULT>
    CD3DX12_PIPELINE_STATE_STREAM_DEPTH_STENCIL1;

```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject)

[**D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type)

