# RemoveFontResourceA function

## Description

The **RemoveFontResource** function removes the fonts in the specified file from the system font table.

If the font was added using the [AddFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourceexa) function, you must use the [RemoveFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontresourceexa) function.

## Parameters

### `lpFileName` [in]

A pointer to a null-terminated string that names a font resource file.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

We recommend that if an app adds or removes fonts from the system font table that it notify other windows of the change by sending a [WM_FONTCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-fontchange) message to all top-level windows in the system. The app sends this message by calling the [SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage) function with the *hwnd* parameter set to HWND_BROADCAST.

If there are outstanding references to a font, the associated resource remains loaded until no device context is using it. Furthermore, if the font is listed in the font registry (**HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts**) and is installed to any location other than the %windir%\fonts\ folder, it may be loaded into other active sessions (including session 0).

When you try to replace an existing font file that contains a font with outstanding references to it, you might get an error that indicates that the original font can't be deleted because it’s in use even after you call **RemoveFontResource**. If your app requires that the font file be replaced, to reduce the resource count of the original font to zero, call **RemoveFontResource** in a loop as shown in this example code. If you continue to get errors, this is an indication that the font file remains loaded in other sessions. Make sure the font isn't listed in the font registry and restart the system to ensure the font is unloaded from all sessions.

**Note** Apps where the original font file is in use will still be able to access the original file and won't use the new font until the font reloads. Call [AddFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourcea) to reload the font. We recommend that you call **AddFontResource** the same number of times as the call to **RemoveFontResource** succeeded as shown in this example code.

``` syntax

int i = 0;
while( RemoveFontResource( FontFile ) )
{
    i++;
}

// TODO: Replace font file

while( i-- )
{
    AddFontResource( FontFile );
}

```

> [!NOTE]
> The wingdi.h header defines RemoveFontResource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourcea)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[RemoveFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontresourceexa)

[SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage)