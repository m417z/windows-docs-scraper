# COMPCOLOR structure

## Description

Contains color settings for a composition string.

## Members

### `crText`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Color of text. To generate a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref), use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `crBackground`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Color of background. To generate a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref), use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `dwEffects`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character effect values as described for the
**dwEffects** member in the [CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata) structure.

## See also

[CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

**Other Resources**

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

**Reference**