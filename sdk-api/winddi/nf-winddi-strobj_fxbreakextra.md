# STROBJ_fxBreakExtra function

## Description

The **STROBJ_fxBreakExtra** function retrieves the amount of extra space to be added to each space character in a string when displaying and/or printing justified text.

## Parameters

### `pstro`

Pointer to the [STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj) structure of the string to be displayed.

## Return value

**STROBJ_fxBreakExtra** returns the amount of extra space to add to each space character in the string. A return value of zero indicates that no extra space is added to space characters in a string.

## Remarks

The extra space value is specified in pixel coordinates.

## See also

[STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj)

[STROBJ_fxCharacterExtra](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_fxcharacterextra)