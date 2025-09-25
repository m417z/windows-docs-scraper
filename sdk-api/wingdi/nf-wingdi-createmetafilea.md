# CreateMetaFileA function

## Description

The **CreateMetaFile** function creates a device context for a Windows-format metafile.

**Note** This function is provided only for compatibility with Windows-format metafiles. Enhanced-format metafiles provide superior functionality and are recommended for new applications. The corresponding function for an enhanced-format metafile is [CreateEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createenhmetafilea).

## Parameters

### `pszFile` [in]

A pointer to the file name for the Windows-format metafile to be created. If this parameter is **NULL**, the Windows-format metafile is memory based and its contents are lost when it is deleted by using the [DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile) function.

## Return value

If the function succeeds, the return value is a handle to the device context for the Windows-format metafile.

If the function fails, the return value is **NULL**.

## Remarks

Where text arguments must use Unicode characters, use the **CreateMetaFile** function as a wide-character function. Where text arguments must use characters from the Windows character set, use this function as an ANSI function.

**CreateMetaFile** is a Windows-format metafile function. This function supports only 16-bit Windows-based applications, which are listed in [Windows-Format Metafiles](https://learn.microsoft.com/windows/desktop/gdi/windows-format-metafiles). It does not record or play back GDI functions such as [PolyBezier](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezier), which were not part of 16-bit Windows.

The device context created by this function can be used to record GDI output functions in a Windows-format metafile. It cannot be used with GDI query functions such as [GetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextcolor). When the device context is used with a GDI output function, the return value of that function becomes **TRUE** if the function is recorded and **FALSE** otherwise. When an object is selected by using the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function, only a copy of the object is recorded. The object still belongs to the application.

To create a scalable Windows-format metafile, record the graphics output in the MM_ANISOTROPIC mapping mode. The file cannot contain functions that modify the viewport origin and extents, nor can it contain device-dependent functions such as the [SelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectcliprgn) function. Once created, the Windows metafile can be scaled and rendered to any output device-format by defining the viewport origin and extents of the picture before playing it.

> [!NOTE]
> The wingdi.h header defines CreateMetaFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-closemetafile)

[CreateEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createenhmetafilea)

[DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile)

[GetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextcolor)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectcliprgn)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)