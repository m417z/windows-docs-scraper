# D2D1GetGradientMeshInteriorPointsFromCoonsPatch function

## Description

Returns the interior points for a gradient mesh patch based on the points defining a Coons patch.

**Note**

This function is called by the [GradientMeshPatchFromCoonsPatch](https://learn.microsoft.com/windows/desktop/api/d2d1_3helper/nf-d2d1_3helper-gradientmeshpatchfromcoonspatch) function and is not intended to be used directly.

## Parameters

### `pPoint0` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 0.

### `pPoint1` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 1.

### `pPoint2` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 2.

### `pPoint3` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 3.

### `pPoint4` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 4.

### `pPoint5` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 5.

### `pPoint6` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 6.

### `pPoint7` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 7.

### `pPoint8` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 8.

### `pPoint9` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 9.

### `pPoint10` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 10.

### `pPoint11` [in]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

The coordinate-space location of the control point at position 11.

### `pTensorPoint11` [out]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

Returns the interior point for the gradient mesh corresponding to point11 in the [D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch) structure.

### `pTensorPoint12` [out]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

Returns the interior point for the gradient mesh corresponding to point12 in the [D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch) structure.

### `pTensorPoint21` [out]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

Returns the interior point for the gradient mesh corresponding to point21 in the [D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch) structure.

### `pTensorPoint22` [out]

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)***

Returns the interior point for the gradient mesh corresponding to point22 in the [D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch) structure.

## Remarks

This function is called by the [GradientMeshPatchFromCoonsPatch](https://learn.microsoft.com/windows/desktop/api/d2d1_3helper/nf-d2d1_3helper-gradientmeshpatchfromcoonspatch) function and is not intended to be used directly.