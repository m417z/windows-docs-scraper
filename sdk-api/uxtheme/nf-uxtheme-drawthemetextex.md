# DrawThemeTextEx function

## Description

Draws text using the color and font defined by the visual style. Extends [DrawThemeText](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemetext) by allowing additional text format options.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC to use for drawing.

### `iPartId` [in]

Type: **int**

The control part that has the desired text appearance. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states). If this value is 0, the text is drawn in the default font, or a font selected into the device context.

### `iStateId` [in]

Type: **int**

The control state that has the desired text appearance. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `pszText` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that contains the text to draw.

### `cchText` [in]

Type: **int**

Value of type **int** that contains the number of characters to draw. If the parameter is set to -1, all the characters in the string are drawn.

### `dwTextFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**DWORD** that contains one or more values that specify the string's formatting. See [Format Values](https://learn.microsoft.com/windows/desktop/Controls/theme-format-values) for possible parameter values.

### `pRect` [in, out]

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the rectangle, in logical coordinates, in which the text is to be drawn.

### `pOptions` [in]

Type: **const [DTTOPTS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-dttopts)***

A [DTTOPTS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-dttopts) structure that defines additional formatting options that will be applied to the text being drawn.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The function always uses the themed font for the specified part and state if one is defined. Otherwise it uses the font currently selected into the device context. To find out if a themed font is defined, you can call [GetThemeFont](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemefont) or [GetThemePropertyOrigin](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemepropertyorigin) with TMT_FONT as the property identifier.