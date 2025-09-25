# Header_GetBitmapMargin macro

## Syntax

```cpp
int Header_GetBitmapMargin(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns the width of the bitmap margin in pixels. If the bitmap margin was not previously specified, the default value of 3***GetSystemMetrics** (*CX_EDGE*) is returned.

## Description

Gets the width of the margin (in pixels) of a bitmap in an existing header control. You can use this macro or send the [HDM_GETBITMAPMARGIN](https://learn.microsoft.com/windows/desktop/Controls/hdm-getbitmapmargin) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

## See also

[Header_SetBitmapMargin](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-header_setbitmapmargin)