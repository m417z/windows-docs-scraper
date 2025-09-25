# IPrintOemUni::OutputCharStr

## Description

The `IPrintOemUni::OutputCharStr` method enables a rendering plug-in to control the printing of font glyphs.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pUFObj`

Caller-supplied pointer to a [UNIFONTOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_unifontobj) structure.

### `dwType`

Caller-supplied value indicating the type of glyph specifier array pointed to by *pGlyph*. Valid values are as follows:

| Value | Definition |
| --- | --- |
| TYPE_GLYPHHANDLE | The *pGlyph* array elements are glyph handles of type HGLYPH. |
| TYPE_GLYPHID | The *pGlyph* array elements are glyph identifiers of type DWORD. |

### `dwCount`

Caller-supplied value representing the number of glyph specifiers in the array pointed to by *pGlyph*.

### `pGlyph`

Caller-supplied pointer to an array of glyph specifiers, where the array element type is indicated by *dwType*.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemUni::OutputCharStr` method is used for supporting printers that do not recognize the [PCL](https://learn.microsoft.com/windows-hardware/drivers/), CAPSL, or PPDS-formatted character output commands supported by Unidrv. Its purpose is to allow a rendering plug-in to control the printing of a font's glyphs, and to provide glyph substitutions if necessary.

If a rendering plug-in implements the `IPrintOemUni::OutputCharStr` method, Unidrv calls the method each time a string of characters is ready to be spooled.

The method receives an array of glyph specifiers. The value received for *dwType* indicates the identifier type.

If the specified font is a device font, the array contains glyph handles. The handles need to be translated to character codes or commands, and then sent to the print spooler to cause device glyphs to be printed.

If the specified font is a soft (TrueType) font, the array contains glyph identifiers. The identifiers represent previously downloaded glyphs that need to be printed.

If the specified font is a device font, the method must do the following:

1. Allocate a [GETINFO_GLYPHSTRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_getinfo_glyphstring) structure with *dwTypeIn* set to TYPE_GLYPHHANDLE and *dwTypeOut* set to TYPE_TRANSDATA.
2. Call the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) function, passing the GETINFO_GLYPHSTRING structure as input, to obtain glyph translations as [TRANSDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_transdata) structure contents.
3. Call [IPrintOemDriverUni::DrvWriteSpoolBuf](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriveruni-drvwritespoolbuf) to send TRANSDATA structure contents to the print spooler, in order to print the glyphs.

If the specified font is a soft font, the method can just call **IPrintOemDriverUni::DrvWriteSpoolBuf** to send commands to the print spooler that will cause the specified previously-downloaded glyphs to be printed.

The `IPrintOemUni::OutputCharStr` method is optional. If a rendering plug-in implements this method, the plug-in's [IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod) method must return S_OK when it receives "OutputCharStr" as input.

For additional information see [Customized Font Management](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management).