# CopyMetaFileW function

## Description

The **CopyMetaFile** function copies the content of a Windows-format metafile to the specified file.

**Note** This function is provided only for compatibility with Windows-format metafiles. Enhanced-format metafiles provide superior functionality and are recommended for new applications. The corresponding function for an enhanced-format metafile is [CopyEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-copyenhmetafilea).

## Parameters

### `unnamedParam1` [in]

A handle to the source Windows-format metafile.

### `unnamedParam2` [in]

A pointer to the name of the destination file. If this parameter is **NULL**, the source metafile is copied to memory.

## Return value

If the function succeeds, the return value is a handle to the copy of the Windows-format metafile.

If the function fails, the return value is **NULL**.

## Remarks

Where text arguments must use Unicode characters, use this function as a wide-character function. Where text arguments must use characters from the Windows character set, use this function as an ANSI function.

When the application no longer needs the Windows-format metafile handle, it should delete the handle by calling the [DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile) function.

> [!NOTE]
> The wingdi.h header defines CopyMetaFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DeleteMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletemetafile)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)