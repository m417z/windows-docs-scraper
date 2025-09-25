# D3D12_RAYTRACING_INSTANCE_DESC structure

## Description

Describes an instance of a raytracing acceleration structure used in GPU memory during the acceleration structure build process.

## Members

### `Transform`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) \[3\]\[4\]**

A 3x4 transform matrix in row-major layout representing the instance-to-world transformation. Implementations transform rays, as opposed to transforming all of the geometry or AABBs.

> [!NOTE]
> The layout of `Transform` is a transpose of how affine matrices are typically stored in memory. Instead of four 3-vectors, `Transform` is laid out as three 4-vectors.

### `InstanceID`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) : 24**

An arbitrary 24-bit value that can be accessed using the `InstanceID` intrinsic function in supported shader types.

### `InstanceMask`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) : 8**

An 8-bit mask assigned to the instance, which can be used to include/reject groups of instances on a per-ray basis. If the value is zero, then the instance will never be included, so typically this should be set to some non-zero value. For more information see, the `InstanceInclusionMask` parameter to the [TraceRay](https://learn.microsoft.com/windows/win32/direct3d12/traceray-function) function.

### `InstanceContributionToHitGroupIndex`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) : 24**

An arbitrary 24-bit value representing per-instance contribution to add into shader table indexing to select the hit group to use.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) : 8**

An 8-bit mask representing flags from [D3D12_RAYTRACING_INSTANCE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_raytracing_instance_flags) to apply to the instance.

### `AccelerationStructure`

Type: **[D3D12_GPU_VIRTUAL_ADDRESS](https://learn.microsoft.com/windows/win32/direct3d12/d3d12_gpu_virtual_address)**

Address of the bottom-level acceleration structure that is being instanced. The address must be aligned to 256 bytes, defined as [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/win32/direct3d12/constants). Any existing acceleration structure passed in here would already have been required to be placed with such alignment.

The memory pointed to must be in state [D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states).

## Remarks

This C++ struct definition is useful if you're generating instance data on the CPU first, then uploading to the GPU. But your application is also free to generate instance descriptions directly into GPU memory (from compute shaders, for instance) following the same layout.