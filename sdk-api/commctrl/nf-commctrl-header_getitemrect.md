# Header_GetItemRect macro

## Syntax

```cpp
BOOL Header_GetItemRect(
   HWND   hwnd,
   int    iItem,
   LPRECT lprc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Gets the bounding rectangle for a given item in a header control. You can use this macro or send the [HDM_GETITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/hdm-getitemrect) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

### `iItem`

Type: **int**

The zero-based index of the header control item for which to retrieve the bounding rectangle.

### `lprc`

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the bounding rectangle information.