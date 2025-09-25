# PropSheet_RebootSystem macro

## Syntax

```cpp
VOID PropSheet_RebootSystem(
   HWND hDlg
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Indicates the system needs to be restarted for the changes to take effect. You can use this macro or send the [PSM_REBOOTSYSTEM](https://learn.microsoft.com/windows/desktop/Controls/psm-rebootsystem) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

## Remarks

An application should send the PSM_REBOOTSYSTEM message only in response to the [PSN_APPLY](https://learn.microsoft.com/windows/desktop/Controls/psn-apply) or [PSN_KILLACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-killactive) notification code.

This macro causes the [PropertySheet](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propertysheeta) function to return the ID_PSREBOOTSYSTEM value, but only if the user clicks the **OK** button to close the property sheet. It is the application's responsibility to reboot the system, which can be done by using the [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex) function.

This macro supersedes all **PropSheet_RebootSystem** macros that precede or follow it.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).

## See also

[PSM_RESTARTWINDOWS](https://learn.microsoft.com/windows/desktop/Controls/psm-restartwindows)