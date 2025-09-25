# Edit_SetRect macro

## Syntax

```cpp
void Edit_SetRect(
   HWND hwndCtl,
   RECT *lprc
);
```

## Description

Sets the formatting rectangle of an edit control. You can use this macro or send the [EM_SETRECT](https://learn.microsoft.com/windows/desktop/Controls/em-setrect) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `lprc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the new dimensions of the rectangle. If this parameter is **NULL**, the formatting rectangle is set to its default values.

## Remarks

For more information, see [EM_SETRECT](https://learn.microsoft.com/windows/desktop/Controls/em-setrect).