# CMYK macro

## Syntax

```cpp
COLORREF CMYK(
     c,
     m,
     y,
     k
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

A CMYK color value.

## Description

The **CMYK** macro creates a CMYK color value by combining the specified cyan, magenta, yellow, and black values.

## Parameters

### `c`

The cyan value for the color to be created.

### `m`

The magenta value for the color to be created.

### `y`

The yellow value for the color to be created.

### `k`

The black value for the color to be created.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [GetCValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcvalue)
* [GetKValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getkvalue)
* [GetMValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmvalue)
* [GetYValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getyvalue)
* [Macros for CMYK values and colors](https://learn.microsoft.com/windows/win32/wcs/macros-for-cmyk-values-and-colors)