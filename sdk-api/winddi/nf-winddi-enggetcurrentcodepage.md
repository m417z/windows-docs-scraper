# EngGetCurrentCodePage function

## Description

The **EngGetCurrentCodePage** function returns the system's default OEM and ANSI code pages.

## Parameters

### `OemCodePage` [out]

Pointer to a USHORT that receives the system's default OEM code page.

### `AnsiCodePage` [out]

Pointer to a USHORT that receives the system's default ANSI code page.

## Return value

None

## Remarks

**EngGetCurrentCodePage** returns the default code pages that are used by the system to translate from ANSI to Unicode. These values are set at boot time according to locale settings.

## See also

[STROBJ_dwGetCodePage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-strobj_dwgetcodepage)