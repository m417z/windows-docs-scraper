## Description

The **GETINFO_GLYPHBITMAP** structure is used as input to the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

## Members

### `dwSize`

Specifies the size, in bytes, of the **GETINFO_GLYPHBITMAP** structure. Supplied by [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `hGlyph`

Handle to the glyph. See the following Remarks section. Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `pGlyphData`

Pointer to a [GLYPHDATA](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-glyphdata) structure. The structure is filled in by Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function. The pointer is supplied by the *UNIFONTOBJ_GetInfo* caller.

## Remarks

To obtain a glyph bitmap, a rendering plug-in can supply the address of a **GETINFO_GLYPHBITMAP** structure when calling Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

The value that a rendering plug-in specifies for the **hGlyph** member must have been previously received as the *hGlyph* parameter to the [IPrintOemUni::DownloadCharGlyph](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-downloadcharglyph) method.

## See also

[GLYPHDATA](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-glyphdata)

[IPrintOemUni::DownloadCharGlyph](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-downloadcharglyph)

[UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo)