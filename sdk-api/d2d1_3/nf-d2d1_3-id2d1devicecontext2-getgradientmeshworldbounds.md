# ID2D1DeviceContext2::GetGradientMeshWorldBounds

## Description

Returns the world bounds of a given gradient mesh.

## Parameters

### `gradientMesh` [in]

Type: **[ID2D1GradientMesh](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1gradientmesh)***

The gradient mesh whose world bounds will be calculated.

### `pBounds` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

When this method returns, contains a pointer to the bounds of the gradient mesh, in device independent pixels (DIPs).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

S_OK if successful, otherwise a failure HRESULT.

## Remarks

The world bounds reflect the current DPI, unit mode, and world transform of the context. They indicate which pixels would be impacted by calling DrawGradientMesh with the given gradient mesh.
They do not reflect the current clip rectangle set on the device context or the extent of the context’s current target.

## See also

[ID2D1DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext2)