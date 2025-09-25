# GetCValue macro

## Syntax

```cpp
BYTE GetCValue(
     cmyk
);
```

## Return value

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The cyan color value from a CMYK color value.

## Description

The **GetCValue** macro retrieves the cyan color value from a CMYK color value.

## Parameters

### `cmyk`

CMYK color value from which the cyan color value will be retrieved.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [CMYK](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-cmyk)
* [GetKValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getkvalue)
* [GetMValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmvalue)
* [GetYValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getyvalue)
* [Macros for CMYK values and colors](https://learn.microsoft.com/windows/win32/wcs/macros-for-cmyk-values-and-colors)