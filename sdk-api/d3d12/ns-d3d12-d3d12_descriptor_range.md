# D3D12_DESCRIPTOR_RANGE structure

## Description

Describes a descriptor range.

## Members

### `RangeType`

A [D3D12_DESCRIPTOR_RANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_type)-typed value that specifies the type of descriptor range.

### `NumDescriptors`

The number of descriptors in the range. Use -1 or UINT_MAX to specify an unbounded size. If a given descriptor range is unbounded, then it must either be the last range in the table definition, or else the following range in the table definition must have a value for *OffsetInDescriptorsFromTableStart* that is not [D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND]().

### `BaseShaderRegister`

The base shader register in the range. For example, for shader-resource views (SRVs), 3 maps to ": register(t3);" in HLSL.

### `RegisterSpace`

The register space. Can typically be 0, but allows multiple descriptor arrays of unknown size to not appear to overlap.
For example, for SRVs, by extending the example in the **BaseShaderRegister** member description, 5 maps to ": register(t3,space5);" in HLSL.

### `OffsetInDescriptorsFromTableStart`

The offset in descriptors, from the start of the descriptor table which was set as the root argument value for this parameter slot. This value can be **D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND**, which indicates this range should immediately follow the preceding range.

## Remarks

This structure is a member of the [D3D12_ROOT_DESCRIPTOR_TABLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table) structure.

## See also

[CD3DX12_DESCRIPTOR_RANGE](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-descriptor-range)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)