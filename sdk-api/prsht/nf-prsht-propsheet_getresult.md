# PropSheet_GetResult macro

## Syntax

```cpp
int PropSheet_GetResult(
   HWND hDlg
);
```

## Return value

Type: **int**

Returns a positive value if successful, or -1 otherwise. The following return values have a special meaning.

| Return code | Description |
|---|---|
| ID_PSREBOOTSYSTEM | A page sent a PSM_REBOOTSYSTEM message to the property sheet. The computer must be restarted for the user's changes to take effect. |
| ID_PSRESTARTWINDOWS | A page sent a PSM_RESTARTWINDOWS message to the property sheet. Windows must be restarted for the user's changes to take effect. |

## Description

Used by modeless property sheets to retrieve the information returned to modal property sheets by [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta). You can use this macro or sent the [PSM_GETRESULT](https://learn.microsoft.com/windows/desktop/Controls/psm-getresult) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet's dialog box.

## Remarks

To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The return value is identical to what [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) would have returned had this been a modal property sheet.

[Version 5.80.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) The [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) return value carries different information for modal and modeless property sheets. In some cases, modeless property sheets may need the information they would have received from **PropertySheet** if they had been modal. In particular, they may need to know whether ID_PSREBOOTSYSTEM or ID_PSRESTARTWINDOWS would have been returned.

For a modeless property sheet, your message loop should use [PSM_ISDIALOGMESSAGE](https://learn.microsoft.com/windows/desktop/Controls/psm-isdialogmessage) to pass messages to the property sheet dialog box, and [PSM_GETCURRENTPAGEHWND](https://learn.microsoft.com/windows/desktop/Controls/psm-getcurrentpagehwnd) to determine when to destroy the dialog box. When the user clicks the **OK** or **Cancel** button, **PSM_GETCURRENTPAGEHWND** returns **NULL**. You can then retrieve the value that a modal property sheet would have received from [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) by sending a [PSM_GETRESULT](https://learn.microsoft.com/windows/desktop/Controls/psm-getresult) message.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).