# GetKerningPairsW function

## Description

The **GetKerningPairs** function retrieves the character-kerning pairs for the currently selected font for the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `nPairs` [in]

The number of pairs in the *lpkrnpair* array. If the font has more than *nNumPairs* kerning pairs, the function returns an error.

### `lpKernPair` [out]

A pointer to an array of [KERNINGPAIR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-kerningpair) structures that receives the kerning pairs. The array must contain at least as many structures as specified by the *nNumPairs* parameter. If this parameter is **NULL**, the function returns the total number of kerning pairs for the font.

## Return value

If the function succeeds, the return value is the number of kerning pairs returned.

If the function fails, the return value is zero.

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[KERNINGPAIR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-kerningpair)

## Remarks

> [!NOTE]
> The wingdi.h header defines GetKerningPairs as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).