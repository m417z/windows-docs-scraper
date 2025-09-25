# ComboBox_ResetContent macro

## Syntax

```cpp
int ComboBox_ResetContent(
   HWND hwndCtl
);
```

## Return value

Type: **int**

Always returns CB_OKAY.

## Description

Removes all items from the list box and edit control of a combo box. You can use this macro or send the [CB_RESETCONTENT](https://learn.microsoft.com/windows/desktop/Controls/cb-resetcontent) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.