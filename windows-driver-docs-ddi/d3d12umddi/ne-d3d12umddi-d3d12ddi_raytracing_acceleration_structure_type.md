# D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_TYPE enumeration

## Description

Specifies the ray tracing acceleration structure type.

## Constants

### `D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL`

Top-level acceleration structure.

### `D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL`

Bottom-level acceleration structure.

## Remarks

Geometry for a scene is described to the system using two levels of acceleration structures:

* Bottom-level acceleration structures each consist of a set of geometries that are building blocks for a scene.
* A top-level acceleration structure represents a set of instances of bottom-level acceleration structures.

Within a given bottom-level acceleration structure there can be any number either:

1. triangle meshes
2. procedural primitives initially described only by an axis-aligned bounding box (AABB)

## See also