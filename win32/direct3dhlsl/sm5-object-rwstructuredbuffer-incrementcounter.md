# IncrementCounter function

Increments the object's hidden counter.

## Parameters

This function has no parameters.

## Return value

Type: **uint**

The pre-incremented counter value.

## Remarks

The bound unordered access view must have [**D3D11\_BUFFER\_UAV\_FLAG\_COUNTER**](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_buffer_uav_flag) set during creation for this method to work.

A structured resource can be further indexed based on the component names of the structures.

This function is supported for the following types of shaders:

| Vertex | Hull | Domain | Geometry | Pixel | Compute |
|--------|------|--------|----------|-------|---------|
| | | | | x | x |

## See also

[RWStructuredBuffer](https://learn.microsoft.com/windows/win32/direct3dhlsl/sm5-object-rwstructuredbuffer)

[Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5)

