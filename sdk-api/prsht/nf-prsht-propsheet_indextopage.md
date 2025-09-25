# PropSheet_IndexToPage macro

## Syntax

```cpp
HPROPSHEETPAGE PropSheet_IndexToPage(
   HWND hDlg,
   int  i
);
```

## Return value

Type: **HPROPSHEETPAGE**

Returns the HPROPSHEETPAGE handle of the property sheet page specified by *i* if successful. Otherwise, it returns zero.

## Description

Takes the index of a property sheet page and returns its HPROPSHEETPAGE handle. You can use this macro or send the [PSM_INDEXTOPAGE](https://learn.microsoft.com/windows/desktop/Controls/psm-indextopage) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet window.

### `i`

Type: **int**

Zero-based index of the page.

## See also

[PropSheet_PageToIndex](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_pagetoindex)