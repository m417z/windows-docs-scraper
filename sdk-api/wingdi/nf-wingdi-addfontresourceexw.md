# AddFontResourceExW function

## Description

The **AddFontResourceEx** function adds the font resource from the specified file to the system. Fonts added with the **AddFontResourceEx** function can be marked as private and not enumerable.

## Parameters

### `name` [in]

A pointer to a null-terminated character string that contains a valid font file name. This parameter can specify any of the following files.

| File Extension | Meaning |
| --- | --- |
| **.fon** | Font resource file. |
| **.fnt** | Raw bitmap font file. |
| **.ttf** | Raw TrueType file. |
| **.ttc** | East Asian Windows: TrueType font collection. |
| **.fot** | TrueType resource file. |
| **.otf** | PostScript OpenType font. |
| **.mmm** | multiple master Type1 font resource file. It must be used with .pfm and .pfb files. |
| **.pfb** | Type 1 font bits file. It is used with a .pfm file. |
| **.pfm** | Type 1 font metrics file. It is used with a .pfb file. |

To add a font whose information comes from several resource files, point *lpszFileName* to a string with the file names separated by a | --for example, abcxxxxx.pfm | abcxxxxx.pfb.

### `fl` [in]

The characteristics of the font to be added to the system. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FR_PRIVATE** | Specifies that only the process that called the **AddFontResourceEx** function can use this font. When the font name matches a public font, the private font will be chosen. When the process terminates, the system will remove all fonts installed by the process with the **AddFontResourceEx** function. |
| **FR_NOT_ENUM** | Specifies that no process, including the process that called the **AddFontResourceEx** function, can enumerate this font. |

### `res` [in]

Reserved. Must be zero.

## Return value

If the function succeeds, the return value specifies the number of fonts added.

If the function fails, the return value is zero. No extended error information is available.

## Remarks

This function allows a process to use fonts without allowing other processes access to the fonts.

When an application no longer needs a font resource it loaded by calling the **AddFontResourceEx** function, it must remove the resource by calling the [RemoveFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontresourceexa) function.

This function installs the font only for the current session. When the system restarts, the font will not be present. To have the font installed even after restarting the system, the font must be listed in the registry.

A font listed in the registry and installed to a location other than the %windir%\fonts\ folder cannot be modified, deleted, or replaced as long as it is loaded in any session. In order to change one of these fonts, it must first be removed by calling [RemoveFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontresourcea), removed from the font registry (**HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts**), and the system restarted. After restarting the system, the font will no longer be loaded and can be changed.

> [!NOTE]
> The wingdi.h header defines AddFontResourceEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[RemoveFontResourceEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-removefontresourceexa)

[SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage)