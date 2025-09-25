# GetSaveFileNamePreviewA function

## Description

The **GetSaveFileNamePreview** function selects a file by using the Save As dialog box. The dialog box also allows the user to preview the currently specified file. This function augments the capability found in the [GetSaveFileName](https://learn.microsoft.com/windows/win32/api/commdlg/nf-commdlg-getsavefilenamea) function.

## Parameters

### `lpofn`

Pointer to an **OPENFILENAME** structure used to initialize the dialog box. On return, the structure contains information about the user's file selection.

## Return value

Returns a handle to the selected file.

## Remarks

> [!NOTE]
> The vfw.h header defines GetSaveFileNamePreview as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).