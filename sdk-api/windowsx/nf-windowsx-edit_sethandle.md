# Edit_SetHandle macro

## Syntax

```cpp
void Edit_SetHandle(
   HWND   hwndCtl,
   HLOCAL h
);
```

## Description

Sets the handle of the memory that will be used by a multiline edit control. You can use this macro or send the [EM_SETHANDLE](https://learn.microsoft.com/windows/desktop/Controls/em-sethandle) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `h`

Type: **[HLOCAL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the memory buffer the edit control uses to store the currently displayed text instead of allocating its own memory. If necessary, the control reallocates this memory.

## Remarks

For more information, see [EM_SETHANDLE](https://learn.microsoft.com/windows/desktop/Controls/em-sethandle).