# CD3DX12\_PIPELINE\_STATE\_STREAM\_ROOT\_SIGNATURE structure

A helper structure used to describe the root signature as a single object suitable for a stream description.

## Members

**CD3DX12\_PIPELINE\_STATE\_STREAM\_ROOT\_SIGNATURE**

Creates a new, uninitialized, instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_ROOT\_SIGNATURE.

**CD3DX12\_PIPELINE\_STATE\_STREAM\_ROOT\_SIGNATURE(ID3D12RootSignature\* const &i)**

Creates a new instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_ROOT\_SIGNATURE, initialized with a subobject type of **D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE\_ROOT\_SIGNATURE** and subobject data copied from *i*, a [**ID3D12RootSignature**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12rootsignature) structure.

**operator=(ID3D12RootSignature\* const& i)**

Copy-assignment operator.

**operator ID3D12RootSignature\*() const**

Implicit conversion to a [**ID3D12RootSignature**](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12rootsignature) structure pointer.

## Remarks

CD3DX12\_PIPELINE\_STATE\_STREAM\_ROOT\_SIGNATURE is a typedef specialization of the [**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) template, and is defined as follows:

```C++
typedef CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT<ID3D12RootSignature*, D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE>
    CD3DX12_PIPELINE_STATE_STREAM_ROOT_SIGNATURE;

```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject)

[**D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type)

