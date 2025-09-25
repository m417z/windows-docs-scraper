# DTTOPTS structure

## Description

Defines the options for the [DrawThemeTextEx](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemetextex) function.

## Members

### `dwSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the structure.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of flags that specify whether certain values of the **DTTOPTS** structure have been specified, and how to interpret these values. This member can be a combination of the following.

| Value | Meaning |
| --- | --- |
| **DTT_TEXTCOLOR** | The **crText** member value is valid. |
| **DTT_BORDERCOLOR** | The **crBorder** member value is valid. |
| **DTT_SHADOWCOLOR** | The **crShadow** member value is valid. |
| **DTT_SHADOWTYPE** | The **iTextShadowType** member value is valid. |
| **DTT_SHADOWOFFSET** | The **ptShadowOffset** member value is valid. |
| **DTT_BORDERSIZE** | The **iBorderSize** member value is valid. |
| **DTT_FONTPROP** | The **iFontPropId** member value is valid. |
| **DTT_COLORPROP** | The **iColorPropId** member value is valid. |
| **DTT_STATEID** | The **iStateId** member value is valid. |
| **DTT_CALCRECT** | The *pRect* parameter of the [DrawThemeTextEx](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemetextex) function that uses this structure will be used as both an in and an out parameter. After the function returns, the *pRect* parameter will contain the rectangle that corresponds to the region calculated to be drawn. |
| **DTT_APPLYOVERLAY** | The **fApplyOverlay** member value is valid. |
| **DTT_GLOWSIZE** | The **iGlowSize** member value is valid. |
| **DTT_CALLBACK** | The **pfnDrawTextCallback** member value is valid. |
| **DTT_COMPOSITED** | Draws text with antialiased alpha. Use of this flag requires a top-down DIB section. This flag works only if the HDC passed to function [DrawThemeTextEx](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemetextex) has a top-down DIB section currently selected in it. For more information, see [Device-Independent Bitmaps](https://learn.microsoft.com/windows/desktop/gdi/device-independent-bitmaps). |
| **DTT_VALIDBITS** | DTT_TEXTCOLOR | DTT_BORDERCOLOR | DTT_SHADOWCOLOR | DTT_SHADOWTYPE | DTT_SHADOWOFFSET | DTT_BORDERSIZE | DTT_FONTPROP | DTT_COLORPROP | DTT_STATEID | DTT_CALCRECT | DTT_APPLYOVERLAY | DTT_GLOWSIZE | DTT_COMPOSITED. |

### `crText`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the color of the text that will be drawn.

### `crBorder`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the color of the outline that will be drawn around the text.

### `crShadow`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the color of the shadow that will be drawn behind the text.

### `iTextShadowType`

Type: **int**

Specifies the type of the shadow that will be drawn behind the text. This member can have one of the following values.

| Value | Meaning |
| --- | --- |
| **TST_NONE** | No shadow will be drawn. |
| **TST_SINGLE** | The shadow will be drawn to appear detailed underneath text. |
| **TST_CONTINUOUS** | The shadow will be drawn to appear blurred underneath text. |

### `ptShadowOffset`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

Specifies the amount of offset, in logical coordinates, between the shadow and the text.

### `iBorderSize`

Type: **int**

Specifies the radius of the outline that will be drawn around the text.

### `iFontPropId`

Type: **int**

Specifies an alternate font property to use when drawing text. For a list of possible values, see [GetThemeSysFont](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemesysfont).

### `iColorPropId`

Type: **int**

Specifies an alternate color property to use when drawing text. If this value is valid and the corresponding flag is set in **dwFlags**, this value will override the value of **crText**. See the values listed in [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) for the *nIndex* parameter.

### `iStateId`

Type: **int**

Specifies an alternate state to use. This member is not used by [DrawThemeTextEx](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemetextex).

### `fApplyOverlay`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **TRUE**, text will be drawn on top of the shadow and outline effects. If **FALSE**, just the shadow and outline effects will be drawn.

### `iGlowSize`

Type: **int**

Specifies the size of a glow that will be drawn on the background prior to any text being drawn.

### `pfnDrawTextCallback`

Type: **DTT_CALLBACK_PROC**

Pointer to callback function for [DrawThemeTextEx](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemetextex).

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Parameter for callback back function specified by **pfnDrawTextCallback**.