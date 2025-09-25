# PropSheet_SetNextText macro

## Syntax

```cpp
VOID PropSheet_SetNextText(
   HWND   hDlg,
   LPTSTR lpszText
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No meaningful return value.

## Description

Sets the text of the **Next** button in a wizard. You can use this macro or send the [PSM_SETNEXTTEXT](https://learn.microsoft.com/windows/desktop/Controls/psm-setnexttext) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the wizard.

### `lpszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a buffer that contains the text.