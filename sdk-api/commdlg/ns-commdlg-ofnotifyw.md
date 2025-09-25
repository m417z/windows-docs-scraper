# OFNOTIFYW structure

## Description

Contains information about a [WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify) message sent to an [OFNHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpofnhookproc) hook procedure for an **Open** or **Save As** dialog box. The *lParam* parameter of the **WM_NOTIFY** message is a pointer to an **OFNOTIFY** structure.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

The **code** member of this structure can be one of the following notification messages that identify the message being sent: [CDN_FILEOK](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-fileok), [CDN_FOLDERCHANGE](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-folderchange), [CDN_HELP](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-help), [CDN_INITDONE](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-initdone), [CDN_SELCHANGE](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-selchange), [CDN_SHAREVIOLATION](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-shareviolation), [CDN_TYPECHANGE](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-typechange).

### `lpOFN`

Type: **LPOPENFILENAME**

A pointer to the [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure that was specified when the **Open** or **Save As** dialog box was created. For some of the notification messages, this structure contains additional information about the event that caused the notification.

### `pszFile`

Type: **LPTSTR**

The file name for which a network sharing violation has occurred. This member is valid only with the [CDN_SHAREVIOLATION](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-shareviolation) notification message.

## Remarks

Not all of the **Open** and **Save As** notification messages use the **OFNOTIFY** structure. The [CDN_INCLUDEITEM](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-includeitem) notification message uses the [OFNOTIFYEX](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-ofnotifyexa) structure.

> [!NOTE]
> The commdlg.h header defines OFNOTIFY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CDN_FILEOK](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-fileok)

[CDN_FOLDERCHANGE](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-folderchange)

[CDN_HELP](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-help)

[CDN_INITDONE](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-initdone)

[CDN_SELCHANGE](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-selchange)

[CDN_SHAREVIOLATION](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-shareviolation)

[CDN_TYPECHANGE](https://learn.microsoft.com/windows/desktop/dlgbox/cdn-typechange)

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[OFNOTIFYEX](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-ofnotifyexa)

[OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea)

**Reference**