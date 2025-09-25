# PropSheet_SetHeaderSubTitle macro

## Syntax

```cpp
VOID PropSheet_SetHeaderSubTitle(
   HWND   hDlg,
   int    index,
   LPCSTR lpszText
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Sets the subtitle text for the header of a wizard's interior page. You can use this macro or send the [PSM_SETHEADERSUBTITLE](https://learn.microsoft.com/windows/desktop/Controls/psm-setheadersubtitle) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the wizard's window.

### `index`

Type: **int**

Zero-based index of the page.

### `lpszText`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New header subtitle.

## Remarks

If you specify the current page, it will immediately be repainted to display the new subtitle.

**Note** This macro is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetheadera_v2)).

## See also

[PropSheet_HwndToIndex](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_hwndtoindex)

[PropSheet_IdToIndex](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_idtoindex)

[PropSheet_PageToIndex](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-propsheet_pagetoindex)

**Reference**