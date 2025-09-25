# PALOBJ_cGetColors function

## Description

The **PALOBJ_cGetColors** function copies RGB colors from an indexed palette.

## Parameters

### `ppalo`

Pointer to the [PALOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-palobj) structure that contains the RGB colors to be copied.

### `iStart`

Specifies the starting color index.

### `cColors`

Specifies the number of colors to be written.

### `pulColors`

Pointer to the buffer in which the colors are to be written.

## Return value

The return value is the number of colors written if the function is successful. Otherwise, it is zero.

## Remarks

A graphics driver can call this function in its implementation of [DrvSetPalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpalette).

## See also

[DrvSetPalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpalette)

[PALOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-palobj)