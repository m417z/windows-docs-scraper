# GradientMeshPatchFromCoonsPatch function

## Description

Creates a [D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch) from a given Coons patch description.

## Parameters

### `point0`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 0.

### `point1`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 1.

### `point2`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 2.

### `point3`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 3.

### `point4`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 4.

### `point5`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 5.

### `point6`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 6.

### `point7`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 7.

### `point8`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 8.

### `point9`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 9.

### `point10`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 10.

### `point11`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 11.

### `color0`

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The color associated with the control point at position 0.

### `color1`

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The color associated with the control point at position 1.

### `color2`

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The color associated with the control point at position 2.

### `color3`

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The color associated with the control point at position 3.

### `topEdgeMode`

Type: **[D2D1_PATCH_EDGE_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_patch_edge_mode)**

Specifies how to render the top edge of the mesh.

### `leftEdgeMode`

Type: **[D2D1_PATCH_EDGE_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_patch_edge_mode)**

Specifies how to render the left edge of the mesh.

### `bottomEdgeMode`

Type: **[D2D1_PATCH_EDGE_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_patch_edge_mode)**

Specifies how to render the bottom edge of the mesh.

### `rightEdgeMode`

Type: **[D2D1_PATCH_EDGE_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_patch_edge_mode)**

Specifies how to render the right edge of the mesh.

## Return value

Type: **[D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch)**

Returns the created [D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch) structure.

## Remarks

The following image shows the numbering of control points in a Coons patch.

![Numbering of control points in a Coons patch](https://learn.microsoft.com/windows/win32/api/d2d1_3helper/images/coonspatch.png)

## See also

[D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch)