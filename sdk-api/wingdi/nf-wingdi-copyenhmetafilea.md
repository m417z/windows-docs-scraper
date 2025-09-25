# CopyEnhMetaFileA function

## Description

The **CopyEnhMetaFile** function copies the contents of an enhanced-format metafile to a specified file.

## Parameters

### `hEnh` [in]

A handle to the enhanced metafile to be copied.

### `lpFileName` [in]

A pointer to the name of the destination file. If this parameter is **NULL**, the source metafile is copied to memory.

## Return value

If the function succeeds, the return value is a handle to the copy of the enhanced metafile.

If the function fails, the return value is **NULL**.

## Remarks

Where text arguments must use Unicode characters, use the **CopyEnhMetaFile** function as a wide-character function. Where text arguments must use characters from the Windows character set, use this function as an ANSI function.

Applications can use metafiles stored in memory for temporary operations.

When the application no longer needs the enhanced-metafile handle, it should delete the handle by calling the [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile) function.

> [!NOTE]
> The wingdi.h header defines CopyEnhMetaFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)