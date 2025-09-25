# STROBJ_fxCharacterExtra function

## Description

The **STROBJ_fxCharacterExtra** function retrieves the amount of extra space with which to augment each character's width in a string when displaying and/or printing it.

## Parameters

### `pstro`

Pointer to the [STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj) structure of the string to be displayed.

## Return value

**STROBJ_fxCharacterExtra** returns the amount of extra space to add to every character in the string. A return value of zero indicates that the string should be laid out using the characters' unaugmented widths.

## Remarks

The extra space value is specified in pixel coordinates.

**STROBJ_fxCharacterExtra** never fails.

## See also

[STROBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-strobj)

[STROBJ_fxBreakExtra](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_fxbreakextra)