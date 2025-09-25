# BRUSHOBJ_ulGetBrushColor function

## Description

The **BRUSHOBJ_ulGetBrushColor** function returns the RGB color of the specified solid brush.

## Parameters

### `pbo`

Pointer to the [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure whose color is being queried.

## Return value

**BRUSHOBJ_ulGetBrushColor** returns the RGB color of a solid brush. If the specified brush is not solid, this function returns -1.

## Remarks

The color stored in the **iSolidColor** member of the BRUSHOBJ structure is an index value that has been translated to the target surface's palette. **BRUSHOBJ_ulGetBrushColor** allows the driver to query the original RGB color value of **iSolidColor**.

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)