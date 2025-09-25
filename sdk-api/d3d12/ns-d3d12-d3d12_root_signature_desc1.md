# D3D12_ROOT_SIGNATURE_DESC1 structure

## Description

Describes the layout of a root signature version 1.1.

## Members

### `NumParameters`

The number of slots in the root signature. This number is also the number of elements in the *pParameters* array.

### `pParameters`

An array of [D3D12_ROOT_PARAMETER1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter1) structures for the slots in the root signature.

### `NumStaticSamplers`

Specifies the number of static samplers.

### `pStaticSamplers`

Pointer to one or more [D3D12_STATIC_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_static_sampler_desc) structures.

### `Flags`

Specifies the [D3D12_ROOT_SIGNATURE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_signature_flags) that determine the data volatility.

## Remarks

Use this structure with the [D3D12_VERSIONED_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc) structure.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)