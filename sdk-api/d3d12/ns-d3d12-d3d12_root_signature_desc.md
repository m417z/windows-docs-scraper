# D3D12_ROOT_SIGNATURE_DESC structure

## Description

Describes the layout of a root signature version 1.0.

## Members

### `NumParameters`

The number of slots in the root signature. This number is also the number of elements in the *pParameters* array.

### `pParameters`

An array of [D3D12_ROOT_PARAMETER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter) structures for the slots in the root signature.

### `NumStaticSamplers`

Specifies the number of static samplers.

### `pStaticSamplers`

Pointer to one or more [D3D12_STATIC_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_static_sampler_desc) structures.

### `Flags`

A combination of [D3D12_ROOT_SIGNATURE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_signature_flags)-typed values that are combined by using a bitwise OR operation.
The resulting value specifies options for the root signature layout.

## Remarks

This structure is used by the [D3D12SerializeRootSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-d3d12serializerootsignature) function
and is returned by the [ID3D12RootSignatureDeserializer::GetRootSignatureDesc](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12rootsignaturedeserializer-getrootsignaturedesc) method.

There is one graphics root signature, and one compute root signature.

## See also

[CD3DX12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-root-signature-desc)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Creating a Root Signature](https://learn.microsoft.com/windows/desktop/direct3d12/creating-a-root-signature)

[D3D12_ROOT_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_parameter_type)

[D3D12_ROOT_SIGNATURE_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc1)

[D3D12_VERSIONED_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc)

[Using constants directly in the root signature](https://learn.microsoft.com/windows/desktop/direct3d12/using-constants-directly-in-the-root-signature)

[Using descriptors directly in the root signature](https://learn.microsoft.com/windows/desktop/direct3d12/using-descriptors-directly-in-the-root-signature)