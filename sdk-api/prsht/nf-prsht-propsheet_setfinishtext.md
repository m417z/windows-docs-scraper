# PropSheet_SetFinishText macro

## Syntax

```cpp
VOID PropSheet_SetFinishText(
   HWND   hDlg,
   LPTSTR lpszText
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Sets the text of the Finish button in a wizard, shows and enables the button, and hides the Next and Back buttons. You can use this macro or send the [PSM_SETFINISHTEXT](https://learn.microsoft.com/windows/desktop/Controls/psm-setfinishtext) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Window handle (HWND) of the wizard property sheet.

### `lpszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the new text for the Finish button.

## Remarks

By default, the Finish button does not have a keyboard accelerator. You can create a keyboard accelerator with this macro by including an ampersand (&) in the text string that you assign to *lpszText*. For example, "&Finish" defines F as the accelerator key.