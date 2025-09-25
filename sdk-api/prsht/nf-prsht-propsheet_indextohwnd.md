# PropSheet_IndexToHwnd macro

## Syntax

```cpp
HWND PropSheet_IndexToHwnd(
   HWND hDlg,
   int  i
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the property sheet page's window specified by *i* if successful. Otherwise, it returns zero.

## Description

Takes the index of a property sheet page and returns its window handle. You can use this macro or send the [PSM_INDEXTOHWND](https://learn.microsoft.com/windows/desktop/Controls/psm-indextohwnd) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet page's window.

### `i`

Type: **int**

Zero-based index of the page.

## See also

[PropSheet_HwndToIndex](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_hwndtoindex)