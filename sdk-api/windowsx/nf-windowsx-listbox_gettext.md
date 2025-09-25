# ListBox_GetText macro

## Syntax

```cpp
int ListBox_GetText(
   HWND    hwndCtl,
   int     index,
   LPCTSTR lpszBuffer
);
```

## Return value

Type: **int**

The count of characters in the string, excluding the terminating null character. If *index* does not specify a valid item, the return value is LB_ERR.

## Description

Gets a string from a list box. You can use this macro or send the [LB_GETTEXT](https://learn.microsoft.com/windows/desktop/Controls/lb-gettext) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item.

### `lpszBuffer`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the buffer that will receive the string. The buffer must have sufficient space for the string and a terminating null character. Before allocating the buffer, you can call [ListBox_GetTextLen](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-listbox_gettextlen) to retrieve the length of the string.

## Remarks

For more information, see [LB_GETTEXT](https://learn.microsoft.com/windows/desktop/Controls/lb-gettext).