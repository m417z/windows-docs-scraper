## Description

The **UNIFONTOBJ_GetInfo** callback function is provided by the Unidrv driver so that rendering plug-ins can obtain font or glyph information.

## Parameters

### `unnamedParam1`

Pointer to the [UNIFONTOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_unifontobj) structure received by the function that is making the callback to **UNIFONTOBJ_GetInfo**. Supplied by the caller.

### `unnamedParam2`

Specifies the size, in bytes, of the buffer pointed to by *pData*. Supplied by the caller.

### `unnamedParam3`

Pointer to a structure, as indicated in the following table. Supplied by the caller.

| dwInfoID Value | *pData* Structure |
|--|--|
| UFO_GETINFO_FONTOBJ | [GETINFO_FONTOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_fontobj) |
| UFO_GETINFO_GLYPHBITMAP | [GETINFO_GLYPHBITMAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_glyphbitmap) |
| UFO_GETINFO_GLYPHSTRING | [GETINFO_GLYPHSTRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_glyphstring) |
| UFO_GETINFO_GLYPHWIDTH | [GETINFO_GLYPHWIDTH](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_glyphwidth) |
| UFO_GETINFO_MEMORY | [GETINFO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_memory) |
| UFO_GETINFO_STDVARIABLE | [GETINFO_STDVAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_stdvar) |

For more information, see the table in the **Remarks** section.

### `unnamedParam4`

Specifies the type of structure pointed to by *pData*. Supplied by the caller. For more information, see the table in the **Remarks** section.

### `unnamedParam5`

Pointer to a location that receives the minimum buffer size, in bytes, required to contain the structure identified by *dwInfoID*. Supplied by the caller.

## Return value

Returns a **BOOL** value. If the operation succeeds, the function returns **TRUE**. Otherwise it returns **FALSE**.

## Remarks

The **UNIFONTOBJ_GetInfo** callback function allows a [rendering plug-in](https://learn.microsoft.com/windows-hardware/drivers/print/rendering-plug-ins) to call back into Unidrv to obtain font or glyph information from GDI, needed for handling [customized font management](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) operations.

A rendering plug-in receives the **UNIFONTOBJ_GetInfo** function's address in the [UNIFONTOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_unifontobj) structure that is passed to the font customization methods.

The type of information returned by the function is dependent on the input arguments. The caller supplies values for *dwInfoID*, *pData*, and *dwDataSize* to indicate the type of information wanted. The following table summarizes the types of information returned. For more information, see the structure descriptions.

| *pData* Structure | Returned Information |
|--|--|
| [GETINFO_FONTOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_fontobj) | A FONTOBJ structure describing the current font. |
| [GETINFO_GLYPHBITMAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_glyphbitmap) | A single glyph bitmap. |
| [GETINFO_GLYPHSTRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_glyphstring) | An array of glyph specifiers in a specified format. |
| [GETINFO_GLYPHWIDTH](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_glyphwidth) | Total width of a set of glyphs. |
| [GETINFO_MEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_memory) | Amount of available printer memory remaining. |
| [GETINFO_STDVAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_stdvar) | The current value for one or more of Unidrv's [standard variables](https://learn.microsoft.com/windows-hardware/drivers/print/standard-variables). |

If the buffer described by *pData* and *dwDataSize* is too small to receive the structure indicated by *dwInfoID*, the function loads the required buffer size into the location pointed by *pcbNeeded* and returns **FALSE**.