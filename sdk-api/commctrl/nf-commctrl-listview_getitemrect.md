# ListView_GetItemRect macro

## Syntax

```cpp
BOOL ListView_GetItemRect(
  [in]  HWND hwnd,
  [in]  int  i,
  [out] RECT *prc,
  [in]  int  code
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets the bounding rectangle for all or part of an item in the current view. You can use this macro or send the [LVM_GETITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemrect) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i` [in]

Type: **int**

The index of the list-view item.

### `prc` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the bounding rectangle.

### `code` [in]

Type: **int**

The portion of the list-view item from which to retrieve the bounding rectangle. This parameter must be one of the following values:

| Value | Meaning |
| --- | --- |
| **LVIR_BOUNDS** | Returns the bounding rectangle of the entire item, including the icon and label. |
| **LVIR_ICON** | Returns the bounding rectangle of the icon or small icon. |
| **LVIR_LABEL** | Returns the bounding rectangle of the item text. |
| **LVIR_SELECTBOUNDS** | Returns the union of the LVIR_ICON and LVIR_LABEL rectangles, but excludes columns in report view. |