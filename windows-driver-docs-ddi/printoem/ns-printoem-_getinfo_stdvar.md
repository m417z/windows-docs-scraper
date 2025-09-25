## Description

The **GETINFO_STDVAR** structure is used as input to the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

## Members

### `dwSize`

Specifies the size, in bytes, of the **GETINFO_STDVAR** structure. Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `dwNumOfVariable`

Defines the **DWORD** member **dwNumOfVariable**.

### `dwStdVarID`

Defines the **DWORD** member **dwStdVarID**.

### `lStdVariable`

Defines the **LONG** member **lStdVariable**.

### `StdVar`

An array specifying standard variable indexes and values. Each array element contains two members: a **dwStdVarID** member and an **lStdVariable** member.

#### dwStdVarID

Specifies the [standard variables](https://learn.microsoft.com/windows-hardware/drivers/print/standard-variables) for which a value should be returned. Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller. Valid values are contained in the following table.

| Identifier | Standard Variable |
|------------------------------|-----------------------|
| FNT_INFO_CURRENTFONTID | CurrentFontID |
| FNT_INFO_FONTBOLD | FontBold |
| FNT_INFO_FONTHEIGHT | FontHeight |
| FNT_INFO_FONTITALIC | FontItalic |
| FNT_INFO_FONTMAXWIDTH | FontMaxWidth |
| FNT_INFO_FONTSTRIKETHRU | FontStrikeThru |
| FNT_INFO_FONTUNDERLINE | FontUnderline |
| FNT_INFO_FONTWIDTH | FontWidth |
| FNT_INFO_GRAYPERCENTAGE | GrayPercentage |
| FNT_INFO_NEXTFONTID | NextFontID |
| FNT_INFO_NEXTGLYPH | NextGlyph |
| FNT_INFO_PRINTDIRINCCDEGREES | PrintDirInCCDegrees |
| FNT_INFO_TEXTXRES | TextXRes |
| FNT_INFO_TEXTYRES | TextYRes |

Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

#### lStdVariable

Specifies the current value of the specified standard variable. Supplied by Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

## Remarks

To obtain the current value for one or more of Unidrv's standard variables, a rendering plug-in can supply the address of a GETINFO_STDVAR structure when calling Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

For more information about [standard variables](https://learn.microsoft.com/windows-hardware/drivers/print/standard-variables), see [Microsoft Universal Printer Driver](https://learn.microsoft.com/windows-hardware/drivers/print/microsoft-universal-printer-driver).

## See also

[UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo)