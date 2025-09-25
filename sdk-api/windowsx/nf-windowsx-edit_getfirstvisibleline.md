# Edit_GetFirstVisibleLine macro

## Syntax

```cpp
int Edit_GetFirstVisibleLine(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The zero-based index of the uppermost visible line in a multiline edit control.

**Edit controls:** For single-line edit controls, the return value is the zero-based index of the first visible character.

**Rich edit controls:** For single-line rich edit controls, the return value is zero.

## Description

Gets the index of the uppermost visible line in a multiline edit or rich edit control. You can use this macro or send the [EM_GETFIRSTVISIBLELINE](https://learn.microsoft.com/windows/desktop/Controls/em-getfirstvisibleline) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [EM_GETFIRSTVISIBLELINE](https://learn.microsoft.com/windows/desktop/Controls/em-getfirstvisibleline).