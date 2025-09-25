# Edit_Scroll macro

## Syntax

```cpp
void Edit_Scroll(
   HWND hwndCtl,
   int  dv,
   int  dh
);
```

## Description

Scrolls the text vertically in a multiline edit or rich edit control. You can use this macro or send the [EM_SCROLL](https://learn.microsoft.com/windows/desktop/Controls/em-scroll) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `dv`

Type: **int**

The amount to scroll vertically.

### `dh`

Type: **int**

The amount to scroll horizontally.

## Remarks

For more information, see [EM_SCROLL](https://learn.microsoft.com/windows/desktop/Controls/em-scroll).