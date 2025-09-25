# D3D12_DESCRIPTOR_RANGE1 structure

## Description

Describes a descriptor range, with flags to determine their volatility.

## Members

### `RangeType`

A [D3D12_DESCRIPTOR_RANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_type)-typed value that specifies the type of descriptor range.

### `NumDescriptors`

The number of descriptors in the range. Use -1 or UINT_MAX to specify unbounded size. Only the last entry in a table can have unbounded size.

### `BaseShaderRegister`

The base shader register in the range. For example, for shader-resource views (SRVs), 3 maps to ": register(t3);" in HLSL.

### `RegisterSpace`

The register space. Can typically be 0, but allows multiple descriptor arrays of unknown size to not appear to overlap.
For example, for SRVs, by extending the example in the **BaseShaderRegister** member description, 5 maps to ": register(t3,space5);" in HLSL.

### `Flags`

Specifies the [D3D12_DESCRIPTOR_RANGE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_flags) that determine descriptor and data volatility.

### `OffsetInDescriptorsFromTableStart`

The offset in descriptors from the start of the root signature. This value can be **D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND**, which indicates this range should immediately follow the preceding range.

## Remarks

This structure is a member of the [D3D12_ROOT_DESCRIPTOR_TABLE1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table1) structure.

Refer to the helper structure [CD3DX12_DESCRIPTOR_RANGE1](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-descriptor-range1).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)