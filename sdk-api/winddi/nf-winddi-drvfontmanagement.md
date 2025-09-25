# DrvFontManagement function

## Description

The **DrvFontManagement** function is an optional entry point provided for PostScript devices.

## Parameters

### `pso` [in]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure.

### `pfo` [in, optional]

Pointer to a [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure.

### `iMode` [in]

Specifies the escape number to be performed. This must either be equal to QUERYESCSUPPORT (defined in *wingdi.h*), or in the range 0x100 through 0x3FE.

### `cjIn` [in]

Specifies the size, in bytes, of the buffer pointed to by the *pvIn* parameter.

### `pvIn` [in]

Pointer to an input buffer. If the *iMode* parameter is QUERYESCSUPPORT, *pvIn* points to a ULONG value in the range 0x100 through 0x3FE.

### `cjOut` [in]

Specifies the size, in bytes, of the output buffer pointed to by the *pvOut* parameter.

### `pvOut` [out]

Pointer to the output data buffer.

## Return value

If this function is hooked by the device driver then GDI will pass calls made by an application to **ExtEscape** for escape numbers 0x100 through 0x3fe, or for the QUERYESCSUPPORT escape when the first DWORD pointed to by *pvIn* is in the range 0x100 through 0x3fe.

## See also

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)