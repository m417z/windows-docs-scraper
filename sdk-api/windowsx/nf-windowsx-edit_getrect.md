# Edit_GetRect macro

## Syntax

```cpp
void Edit_GetRect(
   HWND hwndCtl,
   RECT *lprc
);
```

## Description

Gets the formatting rectangle of an edit control. You can use this macro or send the [EM_GETRECT](https://learn.microsoft.com/windows/desktop/Controls/em-getrect) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `lprc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the formatting rectangle.

## Remarks

For more information, see [EM_GETRECT](https://learn.microsoft.com/windows/desktop/Controls/em-getrect).