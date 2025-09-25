## Description

The **GETINFO_GLYPHSTRING** structure is used as input to the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

## Members

### `dwSize`

Specifies the size, in bytes, of the **GETINFO_GLYPHSTRING** structure. This value is supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `dwCount`

Specifies the number of elements in the arrays pointed to by **pGlyphIn** and **pGlyphOut**. This value is supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `dwTypeIn`

Specifies the type of glyph specifier array pointed to by **pGlyphIn**. Valid values are as follows:

| Value | Definition |
|--|--|
| TYPE_GLYPHHANDLE | T**pGlyphIn** array elements are of type HGLYPH, or handle to a device font glyph. For this value of **dwTypeIn**, valid values for **dwTypeOut** are either TYPE_UNICODE or TYPE_TRANSDATA. |
| TYPE_GLYPHID | The **pGlyphIn** array elements are of type DWORD, and contain glyph identifiers for downloaded TrueType font glyphs. For this value of **dwTypeIn**, valid values for **dwTypeOut** are either TYPE_UNICODE or TYPE_GLYPHHANDLE. |

Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `pGlyphIn`

Pointer to an array of glyph specifiers. The array element type is indicated by **dwTypeIn**. This value is supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `dwTypeOut`

Specifies the type of glyph specifier array pointed to by **pGlyphOut**. Valid values are as follows:

| Value | Definition |
|--|--|
| TYPE_GLYPHHANDLE | The **pGlyphOut** array elements are of type HGLYPH, or handle to a device font glyph. This value is valid only when **dwTypeIn** has been set to TYPE_GLYPHID. |
| TYPE_TRANSDATA | The **pGlyphOut** array elements are of type [TRANSDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_transdata). This value is valid only when **dwTypeIn** has been set to TYPE_GLYPHHANDLE. |
| TYPE_UNICODE | The *pGlyph* array elements are of type WCHAR. This value is valid when **dwTypeIn** has been set to either TYPE_GLYPHHANDLE or TYPE_GLYPHID. |

Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `pGlyphOut`

Caller-supplied pointer to an empty array of glyph specifiers. The array is filled in by Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function. The array element type is indicated by **dwTypeOut**. This pointer is supplied by the UNIFONTOBJ_GetInfo caller.

### `dwGlyphOutSize`

Specifies the size, in bytes, of the buffer pointed to by **pGlyphOut**. This member is used only when **dwTypeIn** has been set to TYPE_GLYPHHANDLE and **dwTypeOut** has been set to TYPE_TRANSDATA. See the following Remarks section for more information.

## Remarks

To convert an array of glyph specifiers from one type to another, a rendering plug-in can supply the address of a GETINFO_GLYPHSTRING structure when calling Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

If the conversion is from TYPE_GLYPHHANDLE to TYPE_TRANSDATA, [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) must be called twice.

- Before the first call to [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo), the rendering plug-in fills in the **dwSize**, **dwCount**, **dwTypeIn**, and **pGlyphIn** members and sets **dwGlyphOutSize** member to zero.

 After [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) returns, the **dwGlyphOutSize** member contains the size, in bytes, of the buffer needed to store the converted string.

- The plug-in allocates a block of memory of the size received in the **dwGlyphOutSize** member, sets the **pGlyphOut** member to point to this memory block, and calls [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) once more. UNIDRV then converts the string from TYPE_GLYPHHANDLE to TYPE_TRANSDATA.

The values that a rendering plug-in specifies for the **dwTypeIn**and **pGlyphIn** members typically are those that were previously received as the **dwType**and *pGlyph* parameters to the [IPrintOemUni::OutputCharStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-outputcharstr) method.

## See also

[IPrintOemUni::OutputCharStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-outputcharstr)

[UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo)