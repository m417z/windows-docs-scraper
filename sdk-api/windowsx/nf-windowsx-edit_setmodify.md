# Edit_SetModify macro

## Syntax

```cpp
void Edit_SetModify(
   HWND hwndCtl,
   BOOL fModified
);
```

## Description

Sets or clears the modification flag for an edit control. The modification flag indicates whether the text within the edit control has been modified. You can use this macro or send the [EM_SETMODIFY](https://learn.microsoft.com/windows/desktop/Controls/em-setmodify) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `fModified`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the text has been modified; otherwise **FALSE**.

## Remarks

For more information, see [EM_SETMODIFY](https://learn.microsoft.com/windows/desktop/Controls/em-setmodify).