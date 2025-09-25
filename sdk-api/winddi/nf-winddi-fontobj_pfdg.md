# FONTOBJ_pfdg function

## Description

The **FONTOBJ_pfdg** function retrieves the pointer to the [FD_GLYPHSET](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphset) structure associated with the specified font.

## Parameters

### `pfo`

Pointer to the [FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj) structure for which the associated FD_GLYPHSET structure is to be returned.

## Return value

**FONTOBJ_pfdg** returns a pointer to the FD_GLYPHSET structure associated with the specified font.

## Remarks

Printer drivers can call **FONTOBJ_pfdg** to determine which Unicode code points are supported in a GDI font. The printer driver can then determine whether it can optimize performance by instead using a similar printer-resident font to display a text string.

## See also

[FD_GLYPHSET](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphset)

[FONTOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontobj)