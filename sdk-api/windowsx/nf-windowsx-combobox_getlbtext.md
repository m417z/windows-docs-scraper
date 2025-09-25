# ComboBox_GetLBText macro

## Syntax

```cpp
int ComboBox_GetLBText(
   HWND    hwndCtl,
   int     index,
   LPCTSTR lpszBuffer
);
```

## Return value

Type: **int**

The count of characters in the string, excluding the terminating null character. If *index* does not specify a valid item, the return value is CB_ERR.

## Description

Gets a string from a list in a combo box. You can use this macro or send the [CB_GETLBTEXT](https://learn.microsoft.com/windows/desktop/Controls/cb-getlbtext) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `index`

Type: **int**

The zero-based index of the item.

### `lpszBuffer`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the buffer that will receive the string. The buffer must have sufficient space for the string and a terminating null character. Before allocating the buffer, you can call [ComboBox_GetLBTextLen](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-combobox_getlbtextlen) to retrieve the length of the string.

## Remarks

For more information, see [CB_GETLBTEXT](https://learn.microsoft.com/windows/desktop/Controls/cb-getlbtext).