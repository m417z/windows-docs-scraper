# GetMetaFileA function

## Description

[GetMetaFile is no longer available for use as of Windows 2000. Instead, use [GetEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilea).]

The **GetMetaFile** function creates a handle that identifies the metafile stored in the specified file.

## Parameters

### `lpName` [in]

A pointer to a null-terminated string that specifies the name of a metafile.

## Return value

If the function succeeds, the return value is a handle to the metafile.

If the function fails, the return value is **NULL**.

## Remarks

This function is not implemented in the Win32 API. It is provided for compatibility with 16-bit versions of Windows. In Win32 applications, use the [GetEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilea) function.

> [!NOTE]
> The wingdi.h header defines GetMetaFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilea)