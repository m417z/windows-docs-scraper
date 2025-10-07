# RAY\_FLAG enumeration

Flags passed to the [**TraceRay**](https://learn.microsoft.com/windows/win32/direct3d12/traceray-function) function to override transparency, culling, and early-out behavior.

## Constants

**RAY\_FLAG\_NONE**

No options selected.

**RAY\_FLAG\_FORCE\_OPAQUE**

All ray-primitive intersections encountered in a raytrace are treated as opaque. So no any hit shaders will be executed regardless of whether or not the hit geometry specifies D3D12\_RAYTRACING\_GEOMETRY\_FLAG\_OPAQUE, and regardless of the instance flags on the instance that was hit.

This flag is mutually exclusive with RAY\_FLAG\_FORCE\_NON\_OPAQUE, RAY\_FLAG\_CULL\_OPAQUE and RAY\_FLAG\_CULL\_NON\_OPAQUE.

**RAY\_FLAG\_FORCE\_NON\_OPAQUE**

All ray-primitive intersections encountered in a raytrace are treated as non-opaque. So any hit shaders, if present, will be executed regardless of whether or not the hit geometry specifies D3D12\_RAYTRACING\_GEOMETRY\_FLAG\_OPAQUE, and regardless of the instance flags on the instance that was hit.
This flag is mutually exclusive with RAY\_FLAG\_FORCE_\OPAQUE, RAY\_FLAG\_CULL\_OPAQUE and RAY\_FLAG\_CULL\_NON\_OPAQUE.

**RAY\_FLAG\_ACCEPT\_FIRST\_HIT\_AND\_END\_SEARCH**

The first ray-primitive intersection encountered in a raytrace automatically causes **AcceptHitAndEndSearch** to be called immediately after the any hit shader, including if there is no any hit shader.

The only exception is when the preceding any hit shader calls **IgnoreHit**, in which case the ray continues unaffected such that the next hit becomes another candidate to be the first hit. For this exception to apply, the any hit shader has to actually be executed. So if the any hit shader is skipped because the hit is treated as opaque (e.g. due to RAY\_FLAG\_FORCE\_OPAQUE or D3D12\_RAYTRACING\_GEOMETRY\_FLAG\_OPAQUE or D3D12\_RAYTRACING\_INSTANCE\_FLAG\_OPAQUE being set), then **AcceptHitAndEndSearch** is called.

If a closest hit shader is present at the first hit, it gets invoked unless RAY\_FLAG\_SKIP\_CLOSEST\_HIT\_SHADER is also present. The one hit that was found is considered “closest”, even though other potential hits that might be closer on the ray may not have been visited.

A typical use for this flag is for shadows, where only a single hit needs to be found.

**RAY\_FLAG\_SKIP\_CLOSEST\_HIT\_SHADER**

Even if at least one hit has been committed, and the hit group for the closest hit contains a closest hit shader, skip execution of that shader.

**RAY\_FLAG\_CULL\_BACK\_FACING\_TRIANGLES**

Enables culling of back facing triangles. See **D3D12\_RAYTRACING\_INSTANCE\_FLAGS** for selecting which triangles are back facing, per-instance.

On instances that specify D3D12\_RAYTRACING\_INSTANCE\_FLAG\_TRIANGLE\_CULL\_DISABLE, this flag has no effect.

On geometry types other than D3D12\_RAYTRACING\_GEOMETRY\_TYPE\_TRIANGLES, this flag has no effect.

This flag is mutually exclusive with RAY\_FLAG\_CULL\_FRONT\_FACING\_TRIANGLES and RAY\_FLAG\_SKIP\_TRIANGLES.

**RAY\_FLAG\_CULL\_FRONT\_FACING\_TRIANGLES**

Enables culling of front facing triangles. See **D3D12\_RAYTRACING\_INSTANCE\_FLAGS** for selecting which triangles are back facing, per-instance.

On instances that specify D3D12\_RAYTRACING\_INSTANCE\_FLAG\_TRIANGLE\_CULL\_DISABLE, this flag has no effect.

On geometry types other than D3D12\_RAYTRACING\_GEOMETRY\_TYPE\_TRIANGLES, this flag has no effect.

This flag is mutually exclusive with RAY\_FLAG\_CULL\_BACK\_FACING\_TRIANGLES and RAY\_FLAG\_SKIP\_TRIANGLES.

**RAY\_FLAG\_CULL\_OPAQUE**

Culls all primitives that are considered opaque based on their geometry and instance flags.

This flag is mutually exclusive with RAY\_FLAG\_FORCE\_OPAQUE, RAY\_FLAG\_FORCE\_NON\_OPAQUE, and RAY\_FLAG\_CULL\_NON\_OPAQUE.

**RAY\_FLAG\_CULL\_NON\_OPAQUE**

Culls all primitives that are considered non-opaque based on their geometry and instance flags.

This flag is mutually exclusive with RAY\_FLAG\_FORCE\_OPAQUE, RAY\_FLAG\_FORCE\_NON\_OPAQUE, and RAY\_FLAG\_CULL\_OPAQUE.

**RAY\_FLAG\_SKIP\_TRIANGLES**

Culls all triangles.

This flag is mutually exclusive to RAY\_FLAG\_CULL\_FRONT\_FACING\_TRIANGLES, RAY\_FLAG\_CULL\_BACK\_FACING\_TRIANGLES and RAY\_FLAG\_SKIP\_PROCEDURAL\_PRIMITIVES.

If instances specify D3D12\_RAYTRACING\_INSTANCE\_FLAG\_TRIANGLE\_CULL\_DISABLE it has no effect, as that flag is meant for disabling front or back culling only. In other words RAY\_FLAG\_SKIP\_TRIANGLES cannot be overruled.

This flag is only supported as of Tier 1.1 implementations.

**RAY\_FLAG\_SKIP\_PROCEDURAL\_PRIMITIVES**

Culls all procedural primitives.

This flag is mutually exclusive to RAY\_FLAG\_SKIP\_TRIANGLES.

This flag is only supported as of Tier 1.1 implementations.

## Requirements

## See also

[Direct3D 12 Raytracing HLSL Reference](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-raytracing-hlsl-reference)