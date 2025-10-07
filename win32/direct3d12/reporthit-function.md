# ReportHit function

Called by an [intersection shader](https://learn.microsoft.com/windows/win32/direct3d12/intersection-shader) to report a ray intersection.

## Syntax
This intrinsic function definition is equivalent to the following function template:

```
template<attr_t>
bool ReportHit(float THit, uint HitKind, attr_t Attributes);
```

## Parameters

`THit`

A float value specifying the parametric distance of the intersection..

`HitKind`

An unsigned integer that identifies the type of hit that occurred. This is a user-specified value in the range of 0-127. The value can be read by [any hit](https://learn.microsoft.com/windows/win32/direct3d12/any-hit-shader) or [closest hit](https://learn.microsoft.com/windows/win32/direct3d12/closest-hit-shader) shaders with the **HitKind** intrinsic.

`Attributes`

The user-defined [**Intersection Attribute Structure**](https://learn.microsoft.com/windows/win32/direct3d12/intersection-attributes) structure specifying the intersection attributes.

## Return Value

**bool** True if the hit was accepted. A hit is rejected if *THit* is outside the current ray interval, or the any hit shader calls [**IgnoreHit**](https://learn.microsoft.com/windows/win32/direct3d12/ignorehit-function). The current ray interval is defined by **RayTMin** and **RayTCurrent**.

## Remarks

This function can be called from the following raytracing shader types:

* [**Intersection Shader**](https://learn.microsoft.com/windows/win32/direct3d12/intersection-shader)

## See also

[Direct3D 12 Raytracing HLSL Reference](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-raytracing-hlsl-reference)

