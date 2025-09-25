# OleUIUpdateLinksW function

## Description

Updates all links in the link container and displays a dialog box that shows the progress of the updating process. The process is stopped if the user presses the **Stop** button or when all links are processed.

## Parameters

### `lpOleUILinkCntr` [in]

Pointer to the [IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera) interface on the link container.

### `hwndParent` [in]

Parent window of the dialog box.

### `lpszTitle` [in]

Pointer to the title of the dialog box.

### `cLinks` [in]

Total number of links.

## Return value

Returns **TRUE** if the links were successfully updated; otherwise, **FALSE**.

## See also

[IOleUILinkContainer::GetLinkUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-getlinkupdateoptions)

[IOleUILinkContainer::UpdateLink](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-updatelink)

## Remarks

> [!NOTE]
> The oledlg.h header defines OleUIUpdateLinks as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).