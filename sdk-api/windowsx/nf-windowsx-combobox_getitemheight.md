# ComboBox_GetItemHeight macro

## Syntax

```cpp
int ComboBox_GetItemHeight(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The height, in pixels, of the list items in a combo box.

## Description

Retrieves the height of list items in a combo box. You can use this macro or send the [CB_GETITEMHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/cb-getitemheight) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

This macro passes zero as the *wParam* member of [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage). For more information, see [CB_GETITEMHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/cb-getitemheight).