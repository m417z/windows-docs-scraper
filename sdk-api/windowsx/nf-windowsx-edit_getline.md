# Edit_GetLine macro

## Syntax

```cpp
int Edit_GetLine(
   HWND   hwndCtl,
   int    line,
   LPTSTR lpch,
   int    cchMax
);
```

## Return value

Type: **int**

The return value is the number of **TCHAR**s copied. The return value is zero if the line number specified by the *line* parameter is greater than the number of lines in the edit control.

## Description

Retrieves a line of text from an edit or rich edit control. You can use this macro or send the [EM_GETLINE](https://learn.microsoft.com/windows/desktop/Controls/em-getline) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `line`

Type: **int**

The zero-based index of the line. This parameter is ignored by a single-line edit control.

### `lpch`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a buffer that receives the string.

### `cchMax`

Type: **int**

The maximum number of characters to be copied to the buffer.

## Remarks

For more information, see [EM_GETLINE](https://learn.microsoft.com/windows/desktop/Controls/em-getline)