# PropertySheetA function

## Description

Creates a property sheet and adds the pages defined in the specified property sheet header structure.

## Parameters

### `unnamedParam1`

Type: **LPCPROPSHEETHEADER**

Pointer to a [PROPSHEETHEADER](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2) structure that defines the frame and pages of a property sheet.

## Return value

Type: **[INT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

For modal property sheets, the return value is as follows:

|  |  |
| --- | --- |
| >=1 | Changes were saved by the user. |
| 0 | No changes were saved by the user. |
| -1 | An error occurred. |

For modeless property sheets, the return value is the property sheet's window handle.

The following return values have a special meaning.

| Return code | Description |
| --- | --- |
| **ID_PSREBOOTSYSTEM** | A page sent the [PSM_REBOOTSYSTEM](https://learn.microsoft.com/windows/desktop/Controls/psm-rebootsystem) message to the property sheet. The computer must be restarted for the user's changes to take effect. |
| **ID_PSRESTARTWINDOWS** | A page sent the [PSM_RESTARTWINDOWS](https://learn.microsoft.com/windows/desktop/Controls/psm-restartwindows) message to the property sheet. Windows must be restarted for the user's changes to take effect. |

## Remarks

To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If you attempt to add more than 99 pages to a property sheet, this function will fail, but with no indication of the cause of the error: **PropertySheet** returns a value of -1, but [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns 0.

**Note** The following remarks refer only to wizards that do not use the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)) or non-wizard property sheets.

By default, the **PropertySheet** function creates a modal dialog box. If the **dwFlags** member of the [PROPSHEETHEADER](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2) structure specifies the PSH_MODELESS flag, **PropertySheet** creates a modeless dialog box and returns immediately after it is created. In this case, the **PropertySheet** return value is the window handle to the modeless dialog box.

For a modeless property sheet, your message loop should use [PSM_ISDIALOGMESSAGE](https://learn.microsoft.com/windows/desktop/Controls/psm-isdialogmessage) to pass messages to the property sheet dialog box. Your message loop should use [PSM_GETCURRENTPAGEHWND](https://learn.microsoft.com/windows/desktop/Controls/psm-getcurrentpagehwnd) to determine when to destroy the dialog box. When the user clicks the **OK** or **Cancel** button, **PSM_GETCURRENTPAGEHWND** returns **NULL**. You can then use the [DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow) function to destroy the dialog box.

[Version 5.80.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) The **PropertySheet** return value carries different information for modal and modeless property sheets. In some cases, modeless property sheets might need the information they would have received from **PropertySheet** if they had been modal. In particular, they may need to know whether ID_PSREBOOTSYSTEM or ID_PSRESTARTWINDOWS would have been returned. A modeless property sheet can retrieve the value that a modal property sheet would have received from **PropertySheet** by waiting until [PSM_GETCURRENTPAGEHWND](https://learn.microsoft.com/windows/desktop/Controls/psm-getcurrentpagehwnd) returns **NULL** and then sending a [PSM_GETRESULT](https://learn.microsoft.com/windows/desktop/Controls/psm-getresult) message.

> [!NOTE]
> The prsht.h header defines PropertySheet as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).