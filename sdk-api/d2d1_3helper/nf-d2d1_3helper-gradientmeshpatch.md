# GradientMeshPatch function

## Description

Creates a [D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch) structure that contains the given control points, colors, and boundary flags.

## Parameters

### `point00`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 00.

### `point01`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 01.

### `point02`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 02.

### `point03`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 03.

### `point10`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 10.

### `point11`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 11.

### `point12`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 12.

### `point13`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 13.

### `point20`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 20.

### `point21`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 21.

### `point22`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 22.

### `point23`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 23.

### `point30`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 30.

### `point31`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 31.

### `point32`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 32.

### `point33`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The coordinate-space location of the control point at position 33.

### `color00`

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The color associated with the control point at position 00.

### `color03`

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The color associated with the control point at position 03.

### `color30`

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The color associated with the control point at position 30.

### `color33`

Type: **[D2D1_COLOR_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-color-f)**

The color associated with the control point at position 33.

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

## See also

[D2D1_GRADIENT_MESH_PATCH](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_gradient_mesh_patch)