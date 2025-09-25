# CreateScalableFontResourceA function

## Description

[The **CreateScalableFontResource** function is available for use in the operating systems specified in the Requirements section. It may be

altered or unavailable in subsequent versions.]

The **CreateScalableFontResource** function creates a font resource file for a scalable font.

## Parameters

### `fdwHidden` [in]

Specifies whether the font is a read-only font. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | The font has read/write permission. |
| **1** | The font has read-only permission and should be hidden from other applications in the system. When this flag is set, the font is not enumerated by the [EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa) or [EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa) function. |

### `lpszFont` [in]

A pointer to a null-terminated string specifying the name of the font resource file to create. If this parameter specifies an existing font resource file, the function fails.

### `lpszFile` [in]

A pointer to a null-terminated string specifying the name of the scalable font file that this function uses to create the font resource file.

### `lpszPath` [in]

A pointer to a null-terminated string specifying the path to the scalable font file.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

If *lpszFontRes* specifies an existing font file, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_FILE_EXISTS

## Remarks

The **CreateScalableFontResource** function is used by applications that install TrueType fonts. An application uses the **CreateScalableFontResource** function to create a font resource file (typically with a .fot file name extension) and then uses the [AddFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourcea) function to install the font. The TrueType font file (typically with a .ttf file name extension) must be in the System subdirectory of the Windows directory to be used by the [AddFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourcea) function.

The **CreateScalableFontResource** function currently supports only TrueType-technology scalable fonts.

When the *lpszFontFile* parameter specifies only a file name and extension, the *lpszCurrentPath* parameter must specify a path. When the *lpszFontFile* parameter specifies a full path, the *lpszCurrentPath* parameter must be **NULL** or a pointer to **NULL**.

When only a file name and extension are specified in the *lpszFontFile* parameter and a path is specified in the *lpszCurrentPath* parameter, the string in *lpszFontFile* is copied into the .fot file as the .ttf file that belongs to this resource. When the [AddFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourcea) function is called, the operating system assumes that the .ttf file has been copied into the System directory (or into the main Windows directory in the case of a network installation). The .ttf file need not be in this directory when the **CreateScalableFontResource** function is called, because the *lpszCurrentPath* parameter contains the directory information. A resource created in this manner does not contain absolute path information and can be used in any installation.

When a path is specified in the *lpszFontFile* parameter and **NULL** is specified in the *lpszCurrentPath* parameter, the string in *lpszFontFile* is copied into the .fot file. In this case, when the [AddFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourcea) function is called, the .ttf file must be at the location specified in the *lpszFontFile* parameter when the **CreateScalableFontResource** function was called; the *lpszCurrentPath* parameter is not needed. A resource created in this manner contains absolute references to paths and drives and does not work if the .ttf file is moved to a different location.

> [!NOTE]
> The wingdi.h header defines CreateScalableFontResource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddFontResource](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-addfontresourcea)

[EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa)

[EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)