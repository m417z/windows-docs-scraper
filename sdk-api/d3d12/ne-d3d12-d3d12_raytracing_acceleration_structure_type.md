# D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE enumeration

## Description

Specifies the type of a raytracing acceleration structure.

## Constants

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:0`

Top-level acceleration structure.

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:0x1`

Bottom-level acceleration structure.

## Remarks

Bottom-level acceleration structures each consist of a set of geometries that are building blocks for a scene. A top-level acceleration structure represents a set of instances of bottom-level acceleration structures.