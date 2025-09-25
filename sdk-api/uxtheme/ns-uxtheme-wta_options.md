# WTA_OPTIONS structure

## Description

Defines options that are used to set window visual style attributes.

## Members

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of flags that modify window visual style attributes. Can be a combination of the [WTNCA](https://learn.microsoft.com/windows/desktop/Controls/wtnca) constants.

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A bitmask that describes how the values specified in **dwFlags** should be applied. If the bit corresponding to a value in **dwFlags** is 0, that flag will be removed. If the bit is 1, the flag will be added.

## See also

[SetWindowThemeAttribute](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-setwindowthemeattribute)