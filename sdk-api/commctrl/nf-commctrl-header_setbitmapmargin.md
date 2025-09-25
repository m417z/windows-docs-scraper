# Header_SetBitmapMargin macro

## Syntax

```cpp
int Header_SetBitmapMargin(
   HWND hwnd,
   int  iWidth
);
```

## Return value

Type: **int**

Returns width of the bitmap margin in pixels. If the bitmap margin was not previously specified, the default value of 3***GetSystemMetrics** (*CX_EDGE*) is returned.

## Description

Sets the width of the margin for a bitmap in an existing header control. You can use this macro or send the [HDM_SETBITMAPMARGIN](https://learn.microsoft.com/windows/desktop/Controls/hdm-setbitmapmargin) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

### `iWidth`

Type: **int**

The width, specified in pixels, of the margin that surrounds a bitmap within an existing header control.

## See also

[Header_GetBitmapMargin](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-header_getbitmapmargin)