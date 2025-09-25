# PropSheet_PressButton macro

## Syntax

```cpp
BOOL PropSheet_PressButton(
   HWND hDlg,
   int  iButton
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Simulates the selection of a property sheet button. You can use this macro or send the [PSM_PRESSBUTTON](https://learn.microsoft.com/windows/desktop/Controls/psm-pressbutton) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `iButton`

Type: **int**

Index of the button to select. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **PSBTN_APPLYNOW** | Selects the Apply button. |
| **PSBTN_BACK** | Selects the Back button. |
| **PSBTN_CANCEL** | Selects the Cancel button. |
| **PSBTN_FINISH** | Selects the Finish button. |
| **PSBTN_HELP** | Selects the Help button. |
| **PSBTN_NEXT** | Selects the Next button. |
| **PSBTN_OK** | Selects the OK button. |