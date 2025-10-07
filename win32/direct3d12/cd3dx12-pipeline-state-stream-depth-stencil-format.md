# CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL\_FORMAT structure

A helper structure used to describe the depth stencil format as a single object suitable for a stream description.

## Members

**CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL\_FORMAT**

Creates a new, uninitialized, instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL\_FORMAT.

**CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL\_FORMAT(DXGI\_FORMAT const &i)**

Creates a new instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL\_FORMAT, initialized with a subobject type of **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE\_DEPTH\_STENCIL\_FORMAT** and subobject data copied from *i*, a [**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration.

**operator=(DXGI\_FORMAT const& i)**

Copy-assignment operator.

**operator DXGI\_FORMAT() const**

Implicit conversion to a [**DXGI\_FORMAT**](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration.

## Remarks

CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL\_FORMAT is a typedef specialization of the [**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) template, and is defined as follows:

```C++
typedef CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT<DXGI_FORMAT, D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT>
    CD3DX12_PIPELINE_STATE_STREAM_DEPTH_STENCIL_FORMAT;

```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject)

[**D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type)

