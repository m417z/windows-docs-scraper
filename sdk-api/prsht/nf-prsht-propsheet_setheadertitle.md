# PropSheet_SetHeaderTitle macro

## Syntax

```cpp
int PropSheet_SetHeaderTitle(
   HWND    hDlg,
   int     index,
   LPCTSTR lpszText
);
```

## Return value

Type: **int**

No return value.

## Description

Sets the title text for the header of a wizard's interior page. You can use this macro or send the [PSM_SETHEADERTITLE](https://learn.microsoft.com/windows/desktop/Controls/psm-setheadertitle) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the wizard's window.

### `index`

Type: **int**

Zero-based index of the page.

### `lpszText`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New header title.

## Remarks

If you specify the current page, it will immediately be repainted to display the new title.