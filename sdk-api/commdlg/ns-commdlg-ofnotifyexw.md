# OFNOTIFYEXW structure

## Description

Contains information about a [CDN_INCLUDEITEM](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-includeitem) notification message.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

The **code** member of this structure identifies the notification message being sent.

### `lpOFN`

Type: **LPOPENFILENAME**

A pointer to an [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure containing the values specified when the **Open** or **Save As** dialog box was created.

### `psf`

Type: **LPVOID**

A pointer to the interface for the folder or shell name-space extension whose items are being enumerated.

### `pidl`

Type: **LPVOID**

A pointer to an item identifier list that identifies an item in the container identified by the **psf** member. The item identifier is relative to the **psf** container.

## See also

[CDN_INCLUDEITEM](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-includeitem)

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[OFNHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpofnhookproc)

[OFNOTIFY](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-ofnotifya)

[OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea)

**Reference**

## Remarks

> [!NOTE]
> The commdlg.h header defines OFNOTIFYEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).