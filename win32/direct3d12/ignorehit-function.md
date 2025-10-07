# IgnoreHit function

Called from an [any hit shader](https://learn.microsoft.com/windows/win32/direct3d12/any-hit-shader) to reject the hit and end the shader. The hit search continues on without committing the distance and attributes for the current hit. The [**ReportHit**](https://learn.microsoft.com/windows/win32/direct3d12/reporthit-function) call in the [intersection shader](https://learn.microsoft.com/windows/win32/direct3d12/intersection-shader), if there is one, will return false. Any modifications made to the ray payload up to this point in the any hit shader are preserved.

## Return Value

**void**

## Remarks

This function can be called from the following raytracing shader types:

* [**Any Hit Shader**](https://learn.microsoft.com/windows/win32/direct3d12/any-hit-shader)

## See also

[Direct3D 12 Raytracing HLSL Reference](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-raytracing-hlsl-reference)

