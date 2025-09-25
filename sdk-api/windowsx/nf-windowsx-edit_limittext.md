# Edit_LimitText macro

## Syntax

```cpp
void Edit_LimitText(
   HWND hwndCtl,
   int  cchMax
);
```

## Description

Limits the length of text that can be entered into an edit control. You can use this macro or send the [EM_LIMITTEXT](https://learn.microsoft.com/windows/desktop/Controls/em-limittext) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `cchMax`

Type: **int**

The maximum number of characters.

## Remarks

For more information, see [EM_LIMITTEXT](https://learn.microsoft.com/windows/desktop/Controls/em-limittext).