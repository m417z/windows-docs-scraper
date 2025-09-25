# D3D12DDI_HIT_GROUP_DESC_0054 structure

## Description

Describes a hit group.

## Members

### `HitGroupExport`

Name of the hit group.

### `Type`

A [D3D12DDI_HIT_GROUP_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_hit_group_type) enumeration that represents the type of hit group.

### `AnyHitShaderImport`

The any hit shader import.

### `ClosestHitShaderImport`

Closest hit shader import.

### `IntersectionShaderImport`

Intersection shader import.

### `SummaryFlags`

A [D3D12DDI_EXPORT_SUMMARY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_export_summary_flags) flag that indicates the properties the runtime has determined about the shader export.

## Remarks

A hit group is one or more shaders that consists of:

* 0 or 1 intersection shader
* 0 or 1 any hit shader
* 0 or 1 closest hit shader

Individual geometries in a given instance each refer to a hit group to provide their shader code. The point of the grouping is to allow implementations to be able to compile and execute the group as efficiently as rays interacting with geometry

Ray generation shaders and miss shaders aren’t part of hit groups because they aren’t involved directly with geometry.

If a hit group contains an intersection shader, it can only be used with procedural primitive geometry. If a hit group does not contain an intersection shader, it can only be used with triangle geometry.

A hit group with no shaders at all is also possible, by simply using NULL as it’s shader identifier.

An empty hit group can be useful, for example, if the app doesn’t want to do anything for hits and only cares about the miss shader running when nothing has been hit.

## See also