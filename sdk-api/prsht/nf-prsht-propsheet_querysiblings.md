# PropSheet_QuerySiblings macro

## Syntax

```cpp
int PropSheet_QuerySiblings(
   HWND   hDlg,
   WPARAM wParam,
   LPARAM lParam
);
```

## Return value

Type: **int**

Returns the nonzero value from a page in the property sheet, or zero if no page returns a nonzero value.

## Description

Causes a property sheet to send the [PSM_QUERYSIBLINGS](https://learn.microsoft.com/windows/desktop/Controls/psm-querysiblings) message to each of its pages. You can use this macro or send the **PSM_QUERYSIBLINGS** message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `wParam`

Type: **[WPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

First application-defined parameter.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Second application-defined parameter.

## Remarks

If a page returns a nonzero value, the property sheet does not send the message to subsequent pages.