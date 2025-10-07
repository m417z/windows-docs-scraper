# CheckAccessFullyMapped function

Determines whether all values from a **Sample**, **Gather**, or **Load** operation accessed mapped tiles in a [tiled resource](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-2-features).

## Parameters

*status* \[in\]

Type: **uint\_only**

The status value that is returned from a **Sample**, **Gather**, or **Load** operation. Because you can't access this status value directly, you need to pass it to **CheckAccessFullyMapped**.

## Return value

Type: **bool**

Returns a **Boolean** value that indicates whether all values from a **Sample**, **Gather**, or **Load** operation accessed mapped tiles in a [tiled resource](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-2-features). Returns **TRUE** if all values from the operation accessed mapped tiles; otherwise, returns **FALSE** if any values were taken from an unmapped tile.

## Remarks

### Minimum Shader Model

This function is supported in the following shader models.

| Shader Model | Supported |
|-----------------------------------------------------------------------------|-----------|
| [Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5) and higher shader models | yes |

This function is supported in the following types of shaders:

| Vertex | Hull | Domain | Geometry | Pixel | Compute |
|--------|------|--------|----------|-------|---------|
| x | x | x | x | x | x |

## See also

[Intrinsic Functions](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-intrinsic-functions)

