# MsiPreviewBillboardW function

## Description

The
**MsiPreviewBillboard** function displays a billboard with the host control in the displayed dialog box.

## Parameters

### `hPreview` [in]

Handle to the preview.

### `szControlName` [in]

Specifies the name of the host control.

### `szBillboard` [in]

Specifies the name of the billboard to display.

## Return value

This function returns UINT.

## Remarks

Supplying a null billboard name in the
**MsiPreviewBillboard** function removes any billboard displayed.

> [!NOTE]
> The msiquery.h header defines MsiPreviewBillboard as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[User Interface Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)