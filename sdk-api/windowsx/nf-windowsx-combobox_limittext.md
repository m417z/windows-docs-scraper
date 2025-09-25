# ComboBox_LimitText macro

## Syntax

```cpp
int ComboBox_LimitText(
   HWND hwndCtl,
   int  cchLimit
);
```

## Return value

Type: **int**

Always returns nonzero.

## Description

Limits the length of the text the user may type into the edit control of a combo box. You can use this macro or send the [CB_LIMITTEXT](https://learn.microsoft.com/windows/desktop/Controls/cb-limittext) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `cchLimit`

Type: **int**

The maximum number of characters.

## Remarks

For more information, see [CB_LIMITTEXT](https://learn.microsoft.com/windows/desktop/Controls/cb-limittext).