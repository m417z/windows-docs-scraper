# COLORSCHEME structure

## Description

Contains information for the drawing of buttons in a toolbar or rebar.

## Members

### `dwSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of this structure, in bytes.

### `clrBtnHighlight`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that represents the highlight color of the buttons. Use
**CLR_DEFAULT** for the default highlight color.

### `clrBtnShadow`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that represents the shadow color of the buttons. Use
**CLR_DEFAULT** for the default shadow color.