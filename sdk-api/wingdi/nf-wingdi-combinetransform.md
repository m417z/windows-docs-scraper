# CombineTransform function

## Description

The **CombineTransform** function concatenates two world-space to page-space transformations.

## Parameters

### `lpxfOut` [out]

A pointer to an [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure that receives the combined transformation.

### `lpxf1` [in]

A pointer to an [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure that specifies the first transformation.

### `lpxf2` [in]

A pointer to an [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure that specifies the second transformation.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Applying the combined transformation has the same effect as applying the first transformation and then applying the second transformation.

The three transformations need not be distinct. For example, *lpxform1* can point to the same [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure as *lpxformResult*.

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getworldtransform)

[ModifyWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-modifyworldtransform)

[SetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setworldtransform)

[XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform)