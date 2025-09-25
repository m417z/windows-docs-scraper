# Edit_SetZoom macro

## Syntax

```cpp
void Edit_SetZoom(
         HWND hwndCtl,
  [out]  LONG numerator,
  [out]  LONG denominator
);
```

## Description

Sets the current zoom ratio of an edit control (the zoom ratio is always between 1/64 and 64). You can use this macro or send the [EM_SETZOOM](https://learn.microsoft.com/windows/desktop/Controls/em-setzoom) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.

### `numerator` [out]

The numerator of the ratio as a fraction.

### `denominator` [out]

The denominator of the ratio as a fraction.