# GetOpenFileNamePreviewA function

## Description

The **GetOpenFileNamePreview** function selects a file by using the Open dialog box. The dialog box also allows the user to preview the currently specified AVI file. This function augments the capability found in the [GetOpenFileName](https://learn.microsoft.com/windows/win32/api/commdlg/nf-commdlg-getopenfilenamea) function.

## Parameters

### `lpofn`

Pointer to an **OPENFILENAME** structure used to initialize the dialog box. On return, the structure contains information about the user's file selection.

## Return value

Returns a handle to the selected file.

## Remarks

> [!NOTE]
> The vfw.h header defines GetOpenFileNamePreview as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).