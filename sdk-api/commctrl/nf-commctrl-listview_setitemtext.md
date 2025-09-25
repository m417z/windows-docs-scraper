# ListView_SetItemText macro

## Syntax

```cpp
VOID ListView_SetItemText(
   HWND    hwndLV,
   int     i,
   int     iSubItem_,
   LPCTSTR pszText_
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Changes the text of a list-view item or subitem. You can use this macro or send the [LVM_SETITEMTEXT](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitemtext) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The zero-based index of the list-view item.

### `iSubItem_`

Type: **int**

The one-based index of the subitem. To set the item label, set *iSubItem_* to zero.

### `pszText_`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated string that contains the new text. This parameter can be LPSTR_TEXTCALLBACK to indicate a callback item for which the parent window stores the text. In this case, the list-view control sends the parent an [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) notification code when it needs the text.

This parameter can be **NULL**.