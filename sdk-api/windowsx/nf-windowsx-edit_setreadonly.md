# Edit_SetReadOnly macro

## Syntax

```cpp
BOOL Edit_SetReadOnly(
   HWND hwndCtl,
   BOOL fReadOnly
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if the operation succeeds; otherwise **FALSE**.

## Description

Sets or removes the read-only style (ES_READONLY) of an edit or rich edit control. You can use this macro or send the [EM_SETREADONLY](https://learn.microsoft.com/windows/desktop/Controls/em-setreadonly) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `fReadOnly`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to set the control to read-only; **FALSE** to remove the read-only style.

## Remarks

For more information, see [EM_SETREADONLY](https://learn.microsoft.com/windows/desktop/Controls/em-setreadonly).