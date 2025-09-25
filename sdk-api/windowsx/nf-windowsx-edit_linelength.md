# Edit_LineLength macro

## Syntax

```cpp
int Edit_LineLength(
   HWND hwndCtl,
   int  line
);
```

## Return value

Type: **int**

The length of the line.

## Description

Retrieves the length, in characters, of a line in an edit or rich edit control. You can use this macro or send the [EM_LINELENGTH](https://learn.microsoft.com/windows/desktop/Controls/em-linelength) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `line`

Type: **int**

The zero-based index of the line.

## Remarks

For more information, see [EM_LINELENGTH](https://learn.microsoft.com/windows/desktop/Controls/em-linelength).