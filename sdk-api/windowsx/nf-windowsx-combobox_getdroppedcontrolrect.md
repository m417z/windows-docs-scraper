# ComboBox_GetDroppedControlRect macro

## Syntax

```cpp
void ComboBox_GetDroppedControlRect(
   HWND hwndCtl,
   RECT *lprc
);
```

## Description

Retrieves the screen coordinates of a combo box in its dropped-down state. You can use this macro or send the [CB_GETDROPPEDCONTROLRECT](https://learn.microsoft.com/windows/desktop/Controls/cb-getdroppedcontrolrect) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `lprc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the coordinates of the combo box in its dropped-down state.