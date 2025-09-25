# PropSheet_HwndToIndex macro

## Syntax

```cpp
int PropSheet_HwndToIndex(
   HWND hDlg,
   HWND hwnd
);
```

## Return value

Type: **int**

Returns the zero-based index of the property sheet page specified by *hwnd* if successful. Otherwise, it returns -1.

## Description

Takes a window handle of the property sheet page and returns its zero-based index. You can use this macro or send the [PSM_HWNDTOINDEX](https://learn.microsoft.com/windows/desktop/controls/psm-hwndtoindex) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet's window.

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the page's window.

## See also

[GetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getparent)

**Other Resources**

[PropSheet_GetCurrentPageHwnd](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_getcurrentpagehwnd)

**Reference**