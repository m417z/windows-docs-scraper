# XFORM structure

## Description

The **XFORM** structure specifies a world-space to page-space transformation.

## Members

### `eM11`

The following.

| Operation | Meaning |
| --- | --- |
| Scaling | Horizontal scaling component |
| Rotation | Cosine of rotation angle |
| Reflection | Horizontal component |

### `eM12`

The following.

| Operation | Meaning |
| --- | --- |
| Shear | Horizontal proportionality constant |
| Rotation | Sine of the rotation angle |

### `eM21`

The following.

| Operation | Meaning |
| --- | --- |
| Shear | Vertical proportionality constant |
| Rotation | Negative sine of the rotation angle |

### `eM22`

The following.

| Operation | Meaning |
| --- | --- |
| Scaling | Vertical scaling component |
| Rotation | Cosine of rotation angle |
| Reflection | Vertical reflection component |

### `eDx`

The horizontal translation component, in logical units.

### `eDy`

The vertical translation component, in logical units.

## Remarks

The following list describes how the members are used for each operation.

| Operation | eM11 | eM12 | eM21 | eM22 |
| --- | --- | --- | --- | --- |
| Rotation | Cosine | Sine | Negative sine | Cosine |
| Scaling | Horizontal scaling component | Not used | Not used | Vertical Scaling Component |
| Shear | Not used | Horizontal Proportionality Constant | Vertical Proportionality Constant | Not used |
| Reflection | Horizontal Reflection Component | Not used | Not used | Vertical Reflection Component |

## See also

[Coordinate Space and Transformation Structures](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-structures)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[ExtCreateRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreateregion)

[GetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getworldtransform)

[ModifyWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-modifyworldtransform)

[PlayEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafile)

[SetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setworldtransform)