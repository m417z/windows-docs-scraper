# ModifyWorldTransform function

## Description

The **ModifyWorldTransform** function changes the world transformation for a device context using the specified mode.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpxf` [in]

A pointer to an [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure used to modify the world transformation for the given device context.

### `mode` [in]

Specifies how the transformation data modifies the current world transformation. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **MWT_IDENTITY** | Resets the current world transformation by using the identity matrix. If this mode is specified, the [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure pointed to by *lpXform* is ignored. |
| **MWT_LEFTMULTIPLY** | Multiplies the current transformation by the data in the [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure. (The data in the **XFORM** structure becomes the left multiplicand, and the data for the current transformation becomes the right multiplicand.) |
| **MWT_RIGHTMULTIPLY** | Multiplies the current transformation by the data in the [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure. (The data in the **XFORM** structure becomes the right multiplicand, and the data for the current transformation becomes the left multiplicand.) |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **ModifyWorldTransform** function will fail unless graphics mode for the specified device context has been set to GM_ADVANCED by previously calling the [SetGraphicsMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setgraphicsmode) function. Likewise, it will not be possible to reset the graphics mode for the device context to the default GM_COMPATIBLE mode, unless world transform has first been reset to the default identity transform by calling [SetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setworldtransform) or **ModifyWorldTransform**.

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getworldtransform)

[SetGraphicsMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setgraphicsmode)

[SetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setworldtransform)

[XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform)