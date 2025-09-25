# TTGETTITLE structure

## Description

Provides information about the title of a tooltip control.

## Members

### `dwSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**DWORD** that specifies size of structure. Set to sizeof(TTGETTITLE).

### `uTitleBitmap`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**UINT** that specifies the tooltip icon.

### `cch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**UINT** that specifies the number of characters in the title.

### `pszTitle`

Type: **[WCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a wide character string that contains the title.