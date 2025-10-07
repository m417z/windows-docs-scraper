# AcceptHitAndEndSearch function

Used in an [any hit shader](https://learn.microsoft.com/windows/win32/direct3d12/any-hit-shader) to commit the current hit and then stop searching for more hits for the ray. If there is an intersection shader running, it's execution stops. Execution passes to the [closest hit shader](https://learn.microsoft.com/windows/win32/direct3d12/closest-hit-shader), if enabled, with the closest hit recorded so far.

## Return Value

**void**

## Remarks

This function can be called from the following raytracing shader types:

* [**Callable Shader**](https://learn.microsoft.com/windows/win32/direct3d12/callable-shader)
* [**Closest Hit Shader**](https://learn.microsoft.com/windows/win32/direct3d12/closest-hit-shader)
* [**Miss Shader**](https://learn.microsoft.com/windows/win32/direct3d12/miss-shader)
* [**Ray Generation Shader**](https://learn.microsoft.com/windows/win32/direct3d12/ray-generation-shader)

## See also

* [Direct3D 12 raytracing HLSL reference](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-raytracing-hlsl-reference)