# XLATEOBJ_cGetPalette function

## Description

The **XLATEOBJ_cGetPalette** function retrieves RGB colors or the bitfields format from the specified palette.

## Parameters

### `pxlo`

Pointer to the [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure from which GDI retrieves the requested information.

### `iPal` [in]

Identifies the palette information to be written. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| XO_DESTBITFIELDS | GDI retrieves the bitfields format of the destination palette. |
| XO_DESTPALETTE | GDI retrieves RGB colors from the destination palette. |
| XO_SRCBITFIELDS | GDI retrieves the bitfields format of the source palette. |
| XO_SRCPALETTE | GDI retrieves RGB colors from the source palette. |

### `cPal`

Specifies the number of entries in the buffer pointed to by *pPal*. This can be smaller than the total size of the palette.

### `pPal`

Pointer to a buffer in which GDI writes the requested palette information. If *iPal* is XO_SRCPALETTE or XO_DESTPALETTE and the respective palette type is PAL_INDEXED, each entry is a 24-bit RGB value.

If *iPal* is XO_SRCBITFIELDS or XO_DESTBITFIELDS and the respective palette type is PAL_BITFIELDS, PAL_RGB, or PAL_BGR, *pPal* points to three ULONG masks that represent the red, green, and blue color masks.

## Return value

**XLATEOBJ_cGetPalette** returns the number of entries written if *pPal* is not null. A value of zero is returned if the XLATEOBJ is null or its palette is invalid. **XLATEOBJ_cGetPalette** will also return zero if the data pointed to by *pxlo* is not consistent with the value in *iPal*. For example, if the data pointed to is a bitfield, but *iPal* is set to either XO_SRCPALETTE or XO_DESTPALETTE, **XLATEOBJ_cGetPalette** will return zero. Similarly, if the data pointed to by *pxlo* is a palette, but *iPal* is set to either XO_SRCBITFIELDS or XO_DESTBITFIELDS, **XLATEOBJ_cGetPalette** also returns zero.

## Remarks

The driver must have information about the palette to perform some methods of color blending.

## See also

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)