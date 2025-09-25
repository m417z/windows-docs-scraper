# Header_GetItemDropDownRect macro

## Syntax

```cpp
BOOL Header_GetItemDropDownRect(
  [in]      HWND   hwnd,
  [in]      int    iItem,
  [in, out] LPRECT lprc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if successful; otherwise, **FALSE**.

## Description

Gets the coordinates of the drop-down button for a specified item in a header control. The header control must be of type **HDF_SPLITBUTTON**. Use this macro or send the [HDM_GETITEMDROPDOWNRECT](https://learn.microsoft.com/windows/desktop/Controls/hdm-getitemdropdownrect) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

### `iItem` [in]

Type: **int**

The zero-based index of the header control item for which to retrieve the bounding rectangle.

### `lprc` [in, out]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure to receive the bounding rectangle information. The message sender is responsible for allocating this structure. The coordinates returned in the **RECT** structure are expressed as screen coordinates.