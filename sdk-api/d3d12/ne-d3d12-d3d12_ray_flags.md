# D3D12_RAY_FLAGS enumeration

## Description

Flags passed to the [TraceRay](https://learn.microsoft.com/windows/desktop/direct3d12/traceray-function) function to override transparency, culling, and early-out behavior.

## Constants

### `D3D12_RAY_FLAG_NONE:0`

No options selected.

### `D3D12_RAY_FLAG_FORCE_OPAQUE:0x1`

All ray-primitive intersections encountered in a raytrace are treated as opaque. So no any hit shaders will be executed regardless of whether or not the hit geometry specifies D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE, and regardless of the instance flags on the instance that was hit.

This flag is mutually exclusive with RAY_FLAG_FORCE_NON_OPAQUE, RAY_FLAG_CULL_OPAQUE and RAY_FLAG_CULL_NON_OPAQUE.

### `D3D12_RAY_FLAG_FORCE_NON_OPAQUE:0x2`

All ray-primitive intersections encountered in a raytrace are treated as non-opaque. So any hit shaders, if present, will be executed regardless of whether or not the hit geometry specifies D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE, and regardless of the instance flags on the instance that was hit. This flag is mutually exclusive with RAY_FLAG_FORCE_\OPAQUE, RAY_FLAG_CULL_OPAQUE and RAY_FLAG_CULL_NON_OPAQUE.

### `D3D12_RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH:0x4`

The first ray-primitive intersection encountered in a raytrace automatically causes [AcceptHitAndEndSearch](https://learn.microsoft.com/windows/desktop/direct3d12/accepthitandendsearch-function) to be called immediately after the any hit shader, including if there is no any hit shader.

The only exception is when the preceding any hit shader calls [IgnoreHit](https://learn.microsoft.com/windows/desktop/direct3d12/ignorehit-function), in which case the ray continues unaffected such that the next hit becomes another candidate to be the first hit. For this exception to apply, the any hit shader has to actually be executed. So if the any hit shader is skipped because the hit is treated as opaque (e.g. due to RAY_FLAG_FORCE_OPAQUE or D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE or D3D12_RAYTRACING_INSTANCE_FLAG_OPAQUE being set), then **AcceptHitAndEndSearch** is called.

If a closest hit shader is present at the first hit, it gets invoked unless RAY_FLAG_SKIP_CLOSEST_HIT_SHADER is also present. The one hit that was found is considered “closest”, even though other potential hits that might be closer on the ray may not have been visited.

A typical use for this flag is for shadows, where only a single hit needs to be found.

### `D3D12_RAY_FLAG_SKIP_CLOSEST_HIT_SHADER:0x8`

Even if at least one hit has been committed, and the hit group for the closest hit contains a closest hit shader, skip execution of that shader.

### `D3D12_RAY_FLAG_CULL_BACK_FACING_TRIANGLES:0x10`

Enables culling of back facing triangles. See [D3D12_RAYTRACING_INSTANCE_FLAGS](https://msdn.microsoft.com/en-us/library/Mt815589(v=VS.85).aspx) for selecting which triangles are back facing, per-instance.

On instances that specify D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE, this flag has no effect.

On geometry types other than D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES, this flag has no effect.

This flag is mutually exclusive with RAY_FLAG_CULL_FRONT_FACING_TRIANGLES.

### `D3D12_RAY_FLAG_CULL_FRONT_FACING_TRIANGLES:0x20`

Enables culling of front facing triangles. See [D3D12_RAYTRACING_INSTANCE_FLAGS](https://msdn.microsoft.com/en-us/library/Mt815589(v=VS.85).aspx) for selecting which triangles are back facing, per-instance.

On instances that specify D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE, this flag has no effect.

On geometry types other than D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES, this flag has no effect.

This flag is mutually exclusive with RAY_FLAG_CULL_FRONT_FACING_TRIANGLES.

### `D3D12_RAY_FLAG_CULL_OPAQUE:0x40`

Culls all primitives that are considered opaque based on their geometry and instance flags.

This flag is mutually exclusive with RAY_FLAG_FORCE_OPAQUE, RAY_FLAG_FORCE_NON_OPAQUE, and RAY_FLAG_CULL_NON_OPAQUE.

### `D3D12_RAY_FLAG_CULL_NON_OPAQUE:0x80`

Culls all primitives that are considered non-opaque based on their geometry and instance flags.

This flag is mutually exclusive with RAY_FLAG_FORCE_OPAQUE, RAY_FLAG_FORCE_NON_OPAQUE, and RAY_FLAG_CULL_OPAQUE.