# XFORMOBJ_bApplyXform function

## Description

The **XFORMOBJ_bApplyXform** function applies the given transform or its inverse to the given array of points.

## Parameters

### `pxo`

Pointer to a [XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85)) structure that defines the transform to be applied to the *pvIn* array.

### `iMode` [in]

Identifies the transform and the input and output data types. This parameter can be one of the following:

| Value | Meaning |
| --- | --- |
| XF_INV_FXTOL | Applies the inverse of the transform to POINTFIX structures to get [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structures. |
| XF_INV_LTOL | Applies the inverse of the transform to POINTL structures to get POINTL structures. |
| XF_LTOFX | Applies the transform to POINTL structures to get POINTFIX structures (see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types)). |
| XF_LTOL | Applies the transform to POINTL structures to get POINTL structures. |

### `cPoints`

Specifies the count of points in *pvIn* to be transformed.

### `pvIn`

Pointer to an array of input points. The format of the points is specified by the *iMode* parameter.

### `pvOut`

Pointer to the buffer that is to receive the transformed points. The *iMode* parameter specifies the format of the points.

## Return value

The return value is **TRUE** if all points were transformed without overflow. **FALSE** is returned if *pxo*, *pvIn*, or *pvOut* are **null**, or if overflow occurs during the transformation.

## See also

[XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85))