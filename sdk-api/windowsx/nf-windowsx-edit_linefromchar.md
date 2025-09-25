# Edit_LineFromChar macro

## Syntax

```cpp
int Edit_LineFromChar(
   HWND hwndCtl,
   int  ich
);
```

## Return value

Type: **int**

The zero-based index of the line.

## Description

Gets the index of the line that contains the specified character index in a multiline edit or rich edit control. You can use this macro or send the [EM_LINEFROMCHAR](https://learn.microsoft.com/windows/desktop/Controls/em-linefromchar) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `ich`

Type: **int**

The zero-based index of the character from the beginning of the text in the control.

## Remarks

For more information, see [EM_LINEFROMCHAR](https://learn.microsoft.com/windows/desktop/Controls/em-linefromchar).