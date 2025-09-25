## Description

Describes the root signature 1.0 layout of a descriptor table as a collection of descriptor ranges that are all relative to a single base descriptor handle.

## Members

### `NumDescriptorRanges`

The number of descriptor ranges in the table layout.

### `pDescriptorRanges`

An array of [D3D12_DESCRIPTOR_RANGE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range) structures that describe the descriptor ranges.

## Remarks

Samplers are not allowed in the same descriptor table as constant-buffer views (CBVs), unordered-access views (UAVs), and shader-resource views (SRVs).

**D3D12_ROOT_DESCRIPTOR_TABLE** is the data type of the
**DescriptorTable** member of
[D3D12_ROOT_PARAMETER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter).
Use a
**D3D12_ROOT_DESCRIPTOR_TABLE** when you set **D3D12_ROOT_PARAMETER**'s **ParameterType** member to [D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_parameter_type).

## See also

[CD3DX12_ROOT_DESCRIPTOR_TABLE](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-root-descriptor-table)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_ROOT_DESCRIPTOR_TABLE1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table1)