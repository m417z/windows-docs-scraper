# XFORML structure

## Description

The FLOATOBJ_XFORM structure describes an arbitrary linear two-dimensional transform, such as for geometric wide lines.

## Members

### `eM11`

### `eM12`

### `eM21`

### `eM22`

Are the four [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj) elements that comprise a 2x2 row-major matrix. The **eM11** member specifies the matrix element at row 1, column 1, the **eM12** member specifies the matrix element at row 1, column2, and so on.

### `eDx`

### `eDy`

Are the x- and y-translation components of the transform.

## Remarks

All elements are specified as [FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj) values. The transform can be downloaded to the driver. Structure members can be operated on by the **FLOATOBJ_***Xxx* routines.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)

[XFORMOBJ_iGetXform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xformobj_igetxform)