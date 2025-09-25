# PropSheet_PageToIndex macro

## Syntax

```cpp
int PropSheet_PageToIndex(
   HWND           hDlg,
   HPROPSHEETPAGE hpage
);
```

## Return value

Type: **int**

Returns the zero-based index of the property sheet page specified by *hpage* if successful. Otherwise, it returns -1.

## Description

Takes the HPROPSHEETPAGE handle of a property sheet page and returns its zero-based index. You can use this macro or send the [PSM_PAGETOINDEX](https://learn.microsoft.com/windows/desktop/controls/psm-pagetoindex) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the property sheet.

### `hpage`

Type: **HPROPSHEETPAGE**

HPROPSHEETPAGE handle to the property sheet page.

## See also

[CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea)

[PropSheet_IndexToPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_indextopage)

**Reference**