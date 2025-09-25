# Edit_SetRectNoPaint macro

## Syntax

```cpp
void Edit_SetRectNoPaint(
   HWND hwndCtl,
   RECT *lprc
);
```

## Description

Sets the formatting rectangle of a multiline edit control. This macro is equivalent to [Edit_SetRect](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-edit_setrect), except that it does not redraw the edit control window. You can use this macro or send the [EM_SETRECTNP](https://learn.microsoft.com/windows/desktop/Controls/em-setrectnp) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `lprc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the dimensions of the rectangle. If this parameter is **NULL**, the formatting rectangle is set to its default values.

## Remarks

**Rich Edit 3.0 and later.** This macro does not have full functionality, because it does not set the WPARAM of the message.

For more information, see [EM_SETRECTNP](https://learn.microsoft.com/windows/desktop/Controls/em-setrectnp).