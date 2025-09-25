# D3D12_HIT_GROUP_TYPE enumeration

## Description

Specifies the type of a raytracing hit group state subobject. Use a value from this enumeration with the [D3D12_HIT_GROUP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_hit_group_desc) structure.

## Constants

### `D3D12_HIT_GROUP_TYPE_TRIANGLES:0`

The hit group uses a list of triangles to calculate ray hits. Hit groups that use triangles can’t contain an intersection shader.

### `D3D12_HIT_GROUP_TYPE_PROCEDURAL_PRIMITIVE:0x1`

The hit group uses a procedural primitive within a bounding box to calculate ray hits. Hit groups that use procedural primitives must contain an intersection shader.