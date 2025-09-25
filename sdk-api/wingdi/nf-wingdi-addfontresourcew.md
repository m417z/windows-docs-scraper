# AddFontResourceW function

## Description

The **AddFontResource** function adds the font resource from the specified file to the system font table. The font can subsequently be used for text output by any application.

To mark a font as private or not enumerable, use the [AddFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourceexa) function.

## Parameters

### `unnamedParam1` [in]

A pointer to a null-terminated character string that contains a valid font file name. This parameter can specify any of the following files.

| File Extension | Meaning |
| --- | --- |
| **.fon** | Font resource file. |
| **.fnt** | Raw bitmap font file. |
| **.ttf** | Raw TrueType file. |
| **.ttc** | East Asian Windows: TrueType font collection. |
| **.fot** | TrueType resource file. |
| **.otf** | PostScript OpenType font. |
| **.mmm** | Multiple master Type1 font resource file. It must be used with .pfm and .pfb files. |
| **.pfb** | Type 1 font bits file. It is used with a .pfm file. |
| **.pfm** | Type 1 font metrics file. It is used with a .pfb file. |

To add a font whose information comes from several resource files, have *lpszFileName* point to a string with the file names separated by a "|" --for example, abcxxxxx.pfm | abcxxxxx.pfb.

## Return value

If the function succeeds, the return value specifies the number of fonts added.

If the function fails, the return value is zero. No extended error information is available.

## Remarks

Any application that adds or removes fonts from the system font table should notify other windows of the change by sending a [WM_FONTCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-fontchange) message to all top-level windows in the operating system. The application should send this message by calling the [SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage) function and setting the *hwnd* parameter to HWND_BROADCAST.

When an application no longer needs a font resource that it loaded by calling the **AddFontResource** function, it must remove that resource by calling the [RemoveFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontresourcea) function.

This function installs the font only for the current session. When the system restarts, the font will not be present. To have the font installed even after restarting the system, the font must be listed in the registry.

A font listed in the registry and installed to a location other than the %windir%\fonts\ folder cannot be modified, deleted, or replaced as long as it is loaded in any session. In order to change one of these fonts, it must first be removed by calling [RemoveFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontresourcea), removed from the font registry (**HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts**), and the system restarted. After restarting the system, the font will no longer be loaded and can be changed.

> [!NOTE]
> The wingdi.h header defines AddFontResource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourceexa)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[RemoveFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontresourcea)

[SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage)