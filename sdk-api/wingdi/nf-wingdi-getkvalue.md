# GetKValue macro

## Syntax

```cpp
BYTE GetKValue(
     cmyk
);
```

## Return value

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The black color value from a CMYK color value.

## Description

The **GetKValue** macro retrieves the black color value from a CMYK color value.

## Parameters

### `cmyk`

CMYK color value from which the black color value will be retrieved.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [CMYK](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-cmyk)
* [GetCValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcvalue)
* [GetMValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmvalue)
* [GetYValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getyvalue)
* [Macros for CMYK values and colors](https://learn.microsoft.com/windows/win32/wcs/macros-for-cmyk-values-and-colors)