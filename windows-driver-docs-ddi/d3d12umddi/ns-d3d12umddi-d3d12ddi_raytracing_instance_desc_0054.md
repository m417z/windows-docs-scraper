# D3D12DDI_RAYTRACING_INSTANCE_DESC_0054 structure

## Description

Describes a ray tracing instance. This data structure is used in GPU memory during acceleration structure build, and is useful if generating instance data on the CPU first then uploading to the GPU.

## Members

### `Transform`

A 3x4 transform matrix in row major layout representing the instance-to-world transformation.

### `InstanceID`

An arbitrary 24-bit value in shader types.

### `InstanceMask`

An 8-bit mask assigned to the instance, which can be used to include or reject groups of instances on a per-ray basis. If the value is zero, the instance will never be included. Set this value to a nonzero value.

### `InstanceContributionToHitGroupIndex`

Per-instance contribution to add into shader table indexing to select the hit group to use.

### `Flags`

Flags to apply to the instance.

### `AccelerationStructure`

Address of the bottom-level acceleration structure that is being instanced. The address must be aligned to 256 bytes.

The memory pointed to must be in [resource state](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_states) D3D12DDI_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE.

## Remarks

## See also