# D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS enumeration

## Description

Specifies flags for the build of a raytracing acceleration structure. Use a value from this enumeration with the [D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_build_raytracing_acceleration_structure_inputs) structure that provides input to the acceleration structure build operation.

## Constants

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_NONE:0`

No options specified for the acceleration structure build.

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE:0x1`

Build the acceleration structure such that it supports future updates (via the flag **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE**) instead of the app having to entirely rebuild the structure. This option may result in increased memory consumption, build times, and lower raytracing performance. Future updates, however, should be faster than building the equivalent acceleration structure from scratch.

This flag can only be set on an initial acceleration structure build, or on an update where the source acceleration structure specified **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE**. In other words, after an acceleration structure was been built without **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE**, no other acceleration structures can be created from it via updates.

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION:0x2`

Enables the option to compact the acceleration structure by calling [CopyRaytracingAccelerationStructure](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-copyraytracingaccelerationstructure) using compact mode, specified with [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_COMPACT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_acceleration_structure_copy_mode).

This option may result in increased memory consumption and build times. After future compaction, however, the resulting acceleration structure should consume a smaller memory footprint than building the acceleration structure from scratch.

This flag is compatible with all other flags. If specified as part of an acceleration structure update, the source acceleration structure must have also been built with this flag. In other words, after an acceleration structure was been built without **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION**, no other acceleration structures can be created from it via updates that specify **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION**.

Specifying ALLOW_COMPACTION may increase pre-compaction acceleration structure size versus not specifying ALLOW_COMPACTION.

If multiple incremental builds are performed before finally compacting, there may be redundant compaction related work performed.

The size required for the compacted acceleration structure can be queried before compaction via [EmitRaytracingAccelerationStructurePostbuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-emitraytracingaccelerationstructurepostbuildinfo). See [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_acceleration_structure_postbuild_info_compacted_size_desc) for more information on properties of compacted acceleration structure size.

**Note** When **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE** is specified, there is certain information that needs to be retained in the acceleration structure, and compaction will only help so much. However, if the pipeline knows that the acceleration structure will no longer be updated, it can make the structure more compact. Some apps may benefit from compacting twice - once after the initial build, and again after the acceleration structure has settled to a static state, if that occurs.

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_TRACE:0x4`

Construct a high quality acceleration structure that maximizes raytracing performance at the expense of additional build time. Typically, the implementation will take 2-3 times the build time than the default setting in order to get better tracing performance.

This flag is recommended for static geometry in particular. It is compatible with all other flags except for **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_BUILD**.

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_BUILD:0x8`

Construct a lower quality acceleration structure, trading raytracing performance for build speed. Typically, the implementation will take 1/2 to 1/3 the build time than default setting, with a sacrifice in tracing performance.

This flag is compatible with all other flags except for **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_BUILD**.

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_MINIMIZE_MEMORY:0x10`

Minimize the amount of scratch memory used during the acceleration structure build as well as the size of the result. This option may result in increased build times and/or raytracing times. This is orthogonal to the **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION** flag and the explicit acceleration structure compaction that it enables. Combining the flags can mean both the initial acceleration structure as well as the result of compacting it use less memory.

The impact of using this flag for a build is reflected in the result of calling [GetRaytracingAccelerationStructurePrebuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device5-getraytracingaccelerationstructureprebuildinfo) before doing the build to retrieve memory requirements for the build.

This flag is compatible with all other flags.

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE:0x20`

Perform an acceleration structure update, as opposed to building from scratch. This is faster than a full build, but can negatively impact raytracing performance, especially if the positions of the underlying objects have changed significantly from the original build of the acceleration structure before updates.

If the addresses of the source and destination acceleration structures are identical, the update is performed in-place. Any other overlapping of address ranges of the source and destination is invalid. For non-overlapping source and destinations, the source acceleration structure is unmodified. The memory requirement for the output acceleration structure is the same as in the input acceleration structure

The source acceleration structure must have been built with **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE**.

This flag is compatible with all other flags. The other flags selections, aside from **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE** and **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE**, must match the flags in the source acceleration structure.

Acceleration structure updates can be performed in unlimited succession, as long as the source acceleration structure was created with **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE** and the flags for the update build continue to specify **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE**.