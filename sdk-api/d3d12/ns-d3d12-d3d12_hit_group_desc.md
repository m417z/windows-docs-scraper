# D3D12_HIT_GROUP_DESC structure

## Description

Describes a raytracing hit group state subobject that can be included in a state object.

## Members

### `HitGroupExport`

The name of the hit group.

### `Type`

A value from the [D3D12_HIT_GROUP_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_hit_group_type) enumeration specifying the type of the hit group.

### `AnyHitShaderImport`

Optional name of the any-hit shader associated with the hit group. This field can be used with all hit group types.

### `ClosestHitShaderImport`

Optional name of the closest-hit shader associated with the hit group. This field can be used with all hit group types.

### `IntersectionShaderImport`

Optional name of the intersection shader associated with the hit group. This field can only be used with hit groups of type procedural primitive.