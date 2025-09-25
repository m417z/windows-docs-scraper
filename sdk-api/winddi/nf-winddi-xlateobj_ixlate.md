# XLATEOBJ_iXlate function

## Description

The **XLATEOBJ_iXlate** function translates a color index of the source palette to the closest index in the destination palette.

## Parameters

### `pxlo`

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that defines the source palette.

### `iColor`

Specifies the color index to be translated.

## Return value

The return value is an index into the destination palette if the function is successful. If the function fails, -1 is returned.

## See also

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)