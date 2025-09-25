# GetEnhMetaFileA function

## Description

The **GetEnhMetaFile** function creates a handle that identifies the enhanced-format metafile stored in the specified file.

## Parameters

### `lpName` [in]

A pointer to a null-terminated string that specifies the name of an enhanced metafile.

## Return value

If the function succeeds, the return value is a handle to the enhanced metafile.

If the function fails, the return value is **NULL**.

## Remarks

When the application no longer needs an enhanced-metafile handle, it should delete the handle by calling the [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile) function.

A Windows-format metafile must be converted to the enhanced format before it can be processed by the **GetEnhMetaFile** function. To convert the file, use the [SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits) function.

Where text arguments must use Unicode characters, use this function as a wide-character function. Where text arguments must use characters from the Windows character set, use this function as an ANSI function.

#### Examples

For an example, see [Opening an Enhanced Metafile and Displaying Its Contents](https://learn.microsoft.com/windows/desktop/gdi/opening-an-enhanced-metafile-and-displaying-its-contents).

> [!NOTE]
> The wingdi.h header defines GetEnhMetaFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile)

[GetEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilea)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits)