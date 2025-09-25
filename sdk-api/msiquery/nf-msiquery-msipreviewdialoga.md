# MsiPreviewDialogA function

## Description

The
**MsiPreviewDialog** function displays a dialog box as modeless and inactive.

## Parameters

### `hPreview` [in]

Handle to the preview.

### `szDialogName` [in]

Specifies the name of the dialog box to preview.

## Return value

This function returns UINT.

## Remarks

Supplying a null name in the
**MsiPreviewDialog** function removes any current dialog box.

> [!NOTE]
> The msiquery.h header defines MsiPreviewDialog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[User Interface Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)