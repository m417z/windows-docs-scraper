## Description

The **UNIFONTOBJ** structure is used as an input parameter to font functions in rendering plug-ins.

## Members

### `ulFontID`

Specifies a resource identifier for an RC_UFM resource contained in a Unidrv minidriver's resource DLL. Supplied by Unidrv.

### `dwFlags`

A set of Unidrv-supplied bit flags. Flag definitions are as follows:

| Flag | Definition |
|--|--|
| UFOFLAG_TTDOWNLOAD_BITMAP | If set, the font is a bitmap font. |
| UFOFLAG_TTDOWNLOAD_TTOUTLINE | If set, the font is a TrueType outline font. |
| UFOFLAG_TTFONT | If set, the font is a downloadable TrueType font. If not set, the font is a device font. |
| UFOFLAG_TTOUTLINE_BOLD_SIM | If set, the TrueType font has bold simulation done by GDI. |
| UFOFLAG_TTOUTLINE_ITALIC_SIM | If set, the TrueType font has italic simulation done by GDI. |
| UFOFLAG_TTOUTLINE_VERTICAL | If set, the TrueType font is a vertical font. Note that this flag is available only for those Asian fonts that can be written vertically. If not set, text is written horizontally. |
| UFOFLAG_TTSUBSTITUTED | If set, the device font is a font substituted for the TrueType font. In the font substitution, GDI requests that Unidrv print using a TrueType font. For performance reasons, Unidrv substitutes a device font for the TrueType font. (The substitution is specified by a \[generic printer description (GPD)\](https://learn.microsoft.com/windows-hardware/drivers/) file or in a table in the registry.) For this substitution, for some printers, it is necessary to adjust the baseline position of the device font, because the baseline position of the device font can be higher than that of the TrueType font. The adjustment causes the output of the substituted device font to be shifted down to correct this discrepancy. Depending on the flags set in the UNIFONTOBJ structure, the printer minidriver is able to adjust the baseline position of device fonts. |

### `pIFIMetrics`

Pointer to an [IFIMETRICS](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-ifimetrics) structure. Supplied by Unidrv.

### `pfnGetInfo`

Pointer to Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function. Supplied by Unidrv.

## See also

[IFIMETRICS](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-ifimetrics)

[UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo)