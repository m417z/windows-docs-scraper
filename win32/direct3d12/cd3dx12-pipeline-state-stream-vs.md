# CD3DX12\_PIPELINE\_STATE\_STREAM\_VS structure

A helper structure used to describe a vertex shader as a single object suitable for a stream description.

## Members

**CD3DX12\_PIPELINE\_STATE\_STREAM\_VS**

Creates a new, uninitialized, instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_VS.

**CD3DX12\_PIPELINE\_STATE\_STREAM\_VS(D3D12\_SHADER\_BYTECODE const &i)**

Creates a new instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_VS, initialized with a subobject type of **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE\_VS** and subobject data copied from *i*, a [**D3D12\_SHADER\_BYTECODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_bytecode) structure.

**operator=(D3D12\_SHADER\_BYTECODE const& i)**

Copy-assignment operator.

**operator D3D12\_SHADER\_BYTECODE() const**

Implicit conversion to a [**D3D12\_SHADER\_BYTECODE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_bytecode) structure.

## Remarks

CD3DX12\_PIPELINE\_STATE\_STREAM\_VS is a typedef specialization of the [**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) template, and is defined as follows:

```C++
typedef CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT<D3D12_SHADER_BYTECODE, D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS>
    CD3DX12_PIPELINE_STATE_STREAM_VS;

```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject)

[**D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type)

