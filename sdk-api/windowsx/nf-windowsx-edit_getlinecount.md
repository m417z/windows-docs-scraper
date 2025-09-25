# Edit_GetLineCount macro

## Syntax

```cpp
int Edit_GetLineCount(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The return value is an integer specifying the total number of text lines in the multiline edit control or rich edit control. If the control has no text, the return value is 1. The return value will never be less than 1.

## Description

Gets the number of lines in the text of an edit control. You can use this macro or send the [EM_GETLINECOUNT](https://learn.microsoft.com/windows/desktop/Controls/em-getlinecount) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [EM_GETLINECOUNT](https://learn.microsoft.com/windows/desktop/Controls/em-getlinecount)