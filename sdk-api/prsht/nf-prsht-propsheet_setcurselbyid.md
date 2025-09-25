# PropSheet_SetCurSelByID macro

## Syntax

```cpp
BOOL PropSheet_SetCurSelByID(
   HWND hDlg,
   int  id
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Activates the specified page in a property sheet based on the resource identifier of the page. You can use this macro or send the [PSM_SETCURSELID](https://learn.microsoft.com/windows/desktop/Controls/psm-setcurselid) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `id`

Type: **int**

Resource identifier of the page to activate.

## Remarks

The window that is losing the activation receives the [PSN_KILLACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-killactive) notification code, and the window that is gaining the activation receives the [PSN_SETACTIVE](https://learn.microsoft.com/windows/desktop/Controls/psn-setactive) notification code.