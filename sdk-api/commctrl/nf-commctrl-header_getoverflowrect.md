# Header_GetOverflowRect macro

## Syntax

```cpp
BOOL Header_GetOverflowRect(
  [in]      HWND   hwnd,
  [in, out] LPRECT lprc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful; otherwise, **FALSE**.

## Description

Gets the coordinates of the drop-down overflow area for a specified header control. The header control must be of type **HDF_SPLITBUTTON**. Use this macro or send the [HDM_GETOVERFLOWRECT](https://learn.microsoft.com/windows/desktop/Controls/hdm-getoverflowrect) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

### `lprc` [in, out]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure to receive the bounding rectangle information.The message sender is responsible for allocating this structure. The coordinates returned in the **RECT** structure are expressed as screen coordinates.