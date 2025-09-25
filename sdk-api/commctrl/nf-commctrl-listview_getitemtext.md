# ListView_GetItemText macro

## Syntax

```cpp
void ListView_GetItemText(
   HWND   hwndLV,
   int    i,
   int    iSubItem_,
   LPTSTR pszText_,
   int    cchTextMax_
);
```

## Description

Gets the text of a list-view item or subitem. You can use this macro or send the [LVM_GETITEMTEXT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemtext) message explicitly.

To get the length of the retrieved string, send the **LVM_GETITEMTEXT** message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the list-view item.

### `iSubItem_`

Type: **int**

The index of the subitem. To retrieve the item text, set *iSubItem_* to zero.

### `pszText_`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a buffer that receives the item or subitem text.

### `cchTextMax_`

Type: **int**

The number of characters in the *pszText_* buffer.

## See also

[LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema)