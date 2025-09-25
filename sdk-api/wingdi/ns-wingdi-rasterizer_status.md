# RASTERIZER_STATUS structure

## Description

The **RASTERIZER_STATUS** structure contains information about whether TrueType is installed. This structure is filled when an application calls the [GetRasterizerCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getrasterizercaps) function.

## Members

### `nSize`

The size, in bytes, of the **RASTERIZER_STATUS** structure.

### `wFlags`

Specifies whether at least one TrueType font is installed and whether TrueType is enabled. This value is TT_AVAILABLE, TT_ENABLED, or both if TrueType is on the system.

### `nLanguageID`

The language in the system's Setup.inf file.

## See also

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetRasterizerCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getrasterizercaps)