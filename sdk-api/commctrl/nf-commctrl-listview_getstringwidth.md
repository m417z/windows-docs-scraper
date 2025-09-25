# ListView_GetStringWidth macro

## Syntax

```cpp
int ListView_GetStringWidth(
   HWND   hwndLV,
   LPCSTR psz
);
```

## Return value

Type: **int**

Returns the string width if successful, or zero otherwise.

## Description

Determines the width of a specified string using the specified list-view control's current font. You can use this macro or send the [LVM_GETSTRINGWIDTH](https://learn.microsoft.com/windows/desktop/Controls/lvm-getstringwidth) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `psz`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated string.

## Remarks

The **ListView_GetStringWidth** macro returns the exact width, in pixels, of the specified string. If you use the returned string width as the column width in a call to the [ListView_SetColumnWidth](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setcolumnwidth) macro, the string will be truncated. To retrieve the column width that can contain the string without truncating it, you must add padding to the returned string width.