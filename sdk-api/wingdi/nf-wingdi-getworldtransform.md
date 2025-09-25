# GetWorldTransform function

## Description

The **GetWorldTransform** function retrieves the current world-space to page-space transformation.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpxf` [out]

A pointer to an [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure that receives the current world-space to page-space transformation.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The precision of the transformation may be altered if an application calls the [ModifyWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-modifyworldtransform) function prior to calling **GetWorldTransform**. (This is because the internal format for storing transformation values uses a higher precision than a **FLOAT** value.)

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[ModifyWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-modifyworldtransform)

[SetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setworldtransform)