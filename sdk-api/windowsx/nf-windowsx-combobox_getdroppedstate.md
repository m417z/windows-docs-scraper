# ComboBox_GetDroppedState macro

## Syntax

```cpp
BOOL ComboBox_GetDroppedState(
   HWND hwndCtl
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if the drop list is visible; otherwise **FALSE**.

## Description

Ascertains whether the drop list in a combo box control is visible. You can use this macro or send the [CB_GETDROPPEDSTATE](https://learn.microsoft.com/windows/desktop/Controls/cb-getdroppedstate) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the combo box control.