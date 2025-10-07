# TraceRay function

Sends a ray into a search for hits in an acceleration structure.

## Syntax
This intrinsic function definition is equivalent to the following function template:

```
Template<payload_t>
void TraceRay(RaytracingAccelerationStructure AccelerationStructure,
              uint RayFlags,
              uint InstanceInclusionMask,
              uint RayContributionToHitGroupIndex,
              uint MultiplierForGeometryContributionToHitGroupIndex,
              uint MissShaderIndex,
              RayDesc Ray,
              inout payload_t Payload);

```

## Parameters

`AccelerationStructure`

The top-level acceleration structure to use. Specifying a NULL acceleration structure forces a miss.

`RayFlags`

Valid combination of [ray_flag](https://learn.microsoft.com/windows/win32/direct3d12/ray_flag) values. Only defined ray flags are propagated by the system, i.e. are visible to the [RayFlags](https://learn.microsoft.com/windows/win32/direct3d12/rayflags) shader intrinsic.

`InstanceInclusionMask`

An unsigned integer, the bottom 8 bits of which are used to include or reject geometry instances based on the InstanceMask in each instance. For example:
```
if(!((InstanceInclusionMask & InstanceMask) & 0xff)) { //ignore intersection }
```

`RayContributionToHitGroupIndex`

An unsigned integer specifying the offset to add into addressing calculations within shader tables for hit group indexing. Only the bottom 4 bits of this value are used.

`MultiplierForGeometryContributionToHitGroupIndex`

An unsigned integer specifying the stride to multiply by *GeometryContributionToHitGroupIndex*, which is just the 0 based index the geometry was supplied by the app into its bottom-level acceleration structure. Only the bottom 16 bits of this multiplier value are used.

`MissShaderIndex`

An unsigned integer specifying the index of the miss shader within a shader table.

`Ray`

A [**RayDesc**](https://learn.microsoft.com/windows/win32/direct3d12/raydesc) representing the ray to be traced.

`Payload`

A user defined ray payload accessed both for both input and output by shaders invoked during raytracing. After [**TraceRay**](https://learn.microsoft.com/windows/win32/direct3d12/traceray-function) completes, the caller can access the payload as well.

## Return Value

**void**

## Remarks

This function can be called from the following raytracing shader types:

* [**Closest Hit Shader**](https://learn.microsoft.com/windows/win32/direct3d12/closest-hit-shader)
* [**Miss Shader**](https://learn.microsoft.com/windows/win32/direct3d12/miss-shader)
* [**Ray Generation Shader**](https://learn.microsoft.com/windows/win32/direct3d12/ray-generation-shader)

## See also

[Direct3D 12 Raytracing HLSL Reference](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-raytracing-hlsl-reference)

