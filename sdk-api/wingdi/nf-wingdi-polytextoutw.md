# PolyTextOutW function

## Description

The **PolyTextOut** function draws several strings using the font and text colors currently selected in the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `ppt` [in]

A pointer to an array of [POLYTEXT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-polytexta) structures describing the strings to be drawn. The array contains one structure for each string to be drawn.

### `nstrings` [in]

The number of [POLYTEXT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-polytexta) structures in the *pptxt* array.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Each [POLYTEXT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-polytexta) structure contains the coordinates of a reference point that Windows uses to align the corresponding string of text. An application can specify how the reference point is used by calling the [SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign) function. An application can determine the current text-alignment setting for the specified device context by calling the [GetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextalign) function.

To draw a single string of text, the application should call the [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) function.

**PolyTextOut** will not handle international scripting support automatically. To get international scripting support, use **ExtTextOut** instead. **ExtTextOut** will use [Uniscribe](https://learn.microsoft.com/windows/win32/intl/uniscribe) when necessary resulting in font fallback. Additionally, **ExtTextOut** will perform internal batching of calls before transitioning to kernel mode, mitigating some of the performance concerns when weighing usage of **PolyTextOut** versus **ExtTextOut**.

> [!TIP]
>  **ExtTextOut** is strongly recommended over **PolyTextOut** for modern development due to its ability to handle display of different languages.

> [!NOTE]
> The wingdi.h header defines PolyTextOut as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextalign)

[POLYTEXT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-polytexta)

[SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign)