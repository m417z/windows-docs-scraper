# Edit_GetHandle macro

## Syntax

```cpp
HLOCAL Edit_GetHandle(
   HWND hwndCtl
);
```

## Return value

Type: **[HLOCAL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

A memory handle identifying the buffer that holds the content of the edit control. If an error occurs, such as sending the message to a single-line edit control, the return value is zero.

## Description

Gets a handle to the memory currently allocated for the text of a multiline edit control. You can use this macro or send the [EM_GETHANDLE](https://learn.microsoft.com/windows/desktop/Controls/em-gethandle) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [EM_GETHANDLE](https://learn.microsoft.com/windows/desktop/Controls/em-gethandle).