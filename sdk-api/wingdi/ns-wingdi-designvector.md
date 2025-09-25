# DESIGNVECTOR structure

## Description

The **DESIGNVECTOR** structure is used by an application to specify values for the axes of a multiple master font.

## Members

### `dvReserved`

Reserved. Must be STAMP_DESIGNVECTOR.

### `dvNumAxes`

Number of values in the **dvValues** array.

### `dvValues`

An array specifying the values of the axes of a multiple master OpenType font. This array corresponds to the **axlAxisInfo** array in the [AXESLIST](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-axeslista) structure.

## Remarks

The **dvNumAxes** member determines the actual size of **dvValues**, and thus, of **DESIGNVECTOR**. The constant MM_MAX_NUMAXES, which is 16, specifies the maximum allowed size of the **dvValues** array.

The PostScript Open Type Font does not support multiple master functionality.

## See also

[AXESLIST](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-axeslista)

[AddFontMemResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontmemresourceex)

[AddFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourceexa)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[RemoveFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontresourceexa)