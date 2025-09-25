# EMRSETBKCOLOR structure

## Description

The **EMRSETBKCOLOR** and **EMRSETTEXTCOLOR** structures contain members for the **SetBkColor** and **SetTextColor** enhanced metafile records.

## Members

### `emr`

Base structure for all record types.

### `crColor`

Color value. To make a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)