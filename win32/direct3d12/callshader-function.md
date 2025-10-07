# CallShader function

Invokes another shader from within a shader.

## Syntax
This intrinsic function definition is equivalent to the following function template:

```
template<param_t>
void CallShader(uint ShaderIndex, inout param_t Parameter);
```

## Parameters

`ShaderIndex`

An unsigned integer representing the index into the [callable shader](https://learn.microsoft.com/windows/win32/direct3d12/callable-shader) table specified in the call to [**DispatchRays**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-dispatchrays).

`Parameter`

The user-defined parameters to pass to the callable shader. This parameter structure must match the parameter structure used in the callable shader pointed to in the shader table.

## Return Value

**void**

## Remarks

This function can be called from the following raytracing shader types:

* [**Callable shader**](https://learn.microsoft.com/windows/win32/direct3d12/callable-shader)
* [**Closest hit shader**](https://learn.microsoft.com/windows/win32/direct3d12/closest-hit-shader)
* [**Miss shader**](https://learn.microsoft.com/windows/win32/direct3d12/miss-shader)
* [**Ray generation shader**](https://learn.microsoft.com/windows/win32/direct3d12/ray-generation-shader)

## See also

* [Direct3D 12 raytracing HLSL reference](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-raytracing-hlsl-reference)