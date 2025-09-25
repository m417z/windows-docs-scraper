# D2D1_GRADIENT_MESH_PATCH structure

## Description

Represents a tensor patch with 16 control points, 4 corner colors, and boundary flags. An ID2D1GradientMesh is made up of 1 or more gradient mesh patches.
Use the [GradientMeshPatch function](https://learn.microsoft.com/windows/desktop/api/d2d1_3helper/nf-d2d1_3helper-gradientmeshpatch) or the [GradientMeshPatchFromCoonsPatch function](https://learn.microsoft.com/windows/desktop/api/d2d1_3helper/nf-d2d1_3helper-gradientmeshpatchfromcoonspatch) to create one.

## Members

### `point00`

The coordinate-space location of the control point in column 0 and row 0 of the tensor grid.

### `point01`

The coordinate-space location of the control point in column 0 and row 1 of the tensor grid.

### `point02`

The coordinate-space location of the control point in column 0 and row 2 of the tensor grid.

### `point03`

The coordinate-space location of the control point in column 0 and row 3 of the tensor grid.

### `point10`

The coordinate-space location of the control point in column 1 and row 0 of the tensor grid.

### `point11`

The coordinate-space location of the control point in column 1 and row 1 of the tensor grid.

### `point12`

The coordinate-space location of the control point in column 1 and row 2 of the tensor grid.

### `point13`

The coordinate-space location of the control point in column 1 and row 3 of the tensor grid.

### `point20`

The coordinate-space location of the control point in column 2 and row 0 of the tensor grid.

### `point21`

The coordinate-space location of the control point in column 2 and row 1 of the tensor grid.

### `point22`

The coordinate-space location of the control point in column 2 and row 2 of the tensor grid.

### `point23`

The coordinate-space location of the control point in column 2 and row 3 of the tensor grid.

### `point30`

The coordinate-space location of the control point in column 3 and row 0 of the tensor grid.

### `point31`

The coordinate-space location of the control point in column 3 and row 1 of the tensor grid.

### `point32`

The coordinate-space location of the control point in column 3 and row 2 of the tensor grid.

### `point33`

The coordinate-space location of the control point in column 3 and row 3 of the tensor grid.

### `color00`

The color associated with the control point in column 0 and row 0 of the tensor grid.

### `color03`

The color associated with the control point in column 0 and row 3 of the tensor grid.

### `color30`

The color associated with the control point in column 3 and row 0 of the tensor grid.

### `color33`

The color associated with the control point in column 3 and row 3 of the tensor grid.

### `topEdgeMode`

Specifies how to render the top edge of the mesh.

### `leftEdgeMode`

Specifies how to render the left edge of the mesh.

### `bottomEdgeMode`

Specifies how to render the bottom edge of the mesh.

### `rightEdgeMode`

Specifies how to render the right edge of the mesh.

## Remarks

The following image shows the numbering of control points on a tensor grid.

![Number of control points on a tensor grid](https://learn.microsoft.com/windows/win32/api/d2d1_3/images/tensorpatch.png)