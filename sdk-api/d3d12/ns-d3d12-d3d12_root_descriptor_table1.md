## Description

Describes the root signature 1.1 layout of a descriptor table as a collection of descriptor ranges that are all relative to a single base descriptor handle.

## Members

### `NumDescriptorRanges`

The number of descriptor ranges in the table layout.

### `pDescriptorRanges`

An array of [D3D12_DESCRIPTOR_RANGE1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range1) structures that describe the descriptor ranges.

## Remarks

Samplers are not allowed in the same descriptor table as constant-buffer views (CBVs), unordered-access views (UAVs), and shader-resource views (SRVs).

**D3D12_ROOT_DESCRIPTOR_TABLE1** is the data type of the
**DescriptorTable** member of
[D3D12_ROOT_PARAMETER1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter1).
Use a
**D3D12_ROOT_DESCRIPTOR_TABLE1** when you set **D3D12_ROOT_PARAMETER1**'s **SlotType** member to [D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_parameter_type).

Refer to the helper structure [CD3DX12_ROOT_DESCRIPTOR_TABLE1](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-root-descriptor-table1).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_ROOT_DESCRIPTOR_TABLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)