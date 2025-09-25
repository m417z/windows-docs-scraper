# RemoveFontResourceExW function

## Description

The **RemoveFontResourceEx** function removes the fonts in the specified file from the system font table.

## Parameters

### `name` [in]

A pointer to a null-terminated string that names a font resource file.

### `fl` [in]

The characteristics of the font to be removed from the system. In order for the font to be removed, the flags used must be the same as when the font was added with the [AddFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourceexa) function. See the **AddFontResourceEx** function for more information.

### `pdv` [in]

Reserved. Must be zero.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. No extended error information is available.

## Remarks

This function will only remove the font if the flags specified are the same as when then font was added with the [AddFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourceexa) function.

When you try to replace an existing font file that contains a font with outstanding references to it, you might get an error that indicates that the original font can't be deleted because it’s in use even after you call **RemoveFontResourceEx**. If your app requires that the font file be replaced, to reduce the resource count of the original font to zero, call **RemoveFontResourceEx** in a loop as shown in this example code. If you continue to get errors, this is an indication that the font file remains loaded in other sessions. Make sure the font isn't listed in the font registry and restart the system to ensure the font is unloaded from all sessions.

**Note** Apps where the original font file is in use will still be able to access the original file and won't use the new font until the font reloads. Call [AddFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourceexa) to reload the font. We recommend that you call **AddFontResourceEx** the same number of times as the call to **RemoveFontResourceEx** succeeded as shown in this example code.

``` syntax

int i = 0;
while( RemoveFontResourceEx( FontFile, FR_PRIVATE, 0 ) )
{
    i++;
}

// TODO: Replace font file

while( i-- )
{
    AddFontResourceEx( FontFile, FR_PRIVATE, 0 );
}

```

> [!NOTE]
> The wingdi.h header defines RemoveFontResourceEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourceexa)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage)