# RemoveFontMemResourceEx function

## Description

The **RemoveFontMemResourceEx** function removes the fonts added from a memory image file.

## Parameters

### `h` [in]

A handle to the font-resource. This handle is returned by the [AddFontMemResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontmemresourceex) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. No extended error information is available.

## Remarks

This function removes a font that was added by the [AddFontMemResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontmemresourceex) function. To remove the font, specify the same path and flags as were used in **AddFontMemResourceEx**. This function will only remove the font that is specified by *fh*.

## See also

[AddFontMemResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontmemresourceex)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage)