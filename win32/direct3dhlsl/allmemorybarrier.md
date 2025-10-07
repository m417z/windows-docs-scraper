# AllMemoryBarrier function

Blocks execution of all threads in a group until all memory accesses have been completed.

## Parameters

This function has no parameters.

## Return value

This function does not return a value.

## Remarks

A memory barrier guarantees that outstanding memory operations have completed. Threads are synchronized at GroupSync barriers. This may stall a thread or threads if memory operations are in progress.

### Minimum Shader Model

This function is supported in the following shader models.

| Shader Model | Supported |
|-----------------------------------------------------------------------------|-----------|
| [Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5) and higher shader models | yes |

This function is supported in the following types of shaders:

| Vertex | Hull | Domain | Geometry | Pixel | Compute |
|--------|------|--------|----------|-------|---------|
| | | | | | x |

## See also

[Intrinsic Functions](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-intrinsic-functions)

[Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5)

