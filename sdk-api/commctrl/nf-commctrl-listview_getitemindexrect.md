# ListView_GetItemIndexRect macro

## Syntax

```cpp
BOOL ListView_GetItemIndexRect(
  [in]      HWND        hwnd,
  [in]      LVITEMINDEX *plvii,
  [in]      LONG        iSubItem,
  [in]      LONG        code,
  [in, out] LPRECT      prc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets the bounding rectangle for all or part of a subitem in the current view of a specified list-view control. Use this macro or send the [LVM_GETITEMINDEXRECT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemindexrect) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `plvii` [in]

Type: **[LVITEMINDEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitemindex)***

A pointer to a [LVITEMINDEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitemindex) structure for the parent item of the subitem. The caller is responsible for allocating this structure and setting its members. *plvii* must not be **NULL**.

### `iSubItem` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the subitem.

### `code` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The portion of the list-view subitem for which to retrieve the bounding rectangle. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **LVIR_BOUNDS** | Returns the bounding rectangle of the entire subitem, including the icon and label. |
| **LVIR_ICON** | Returns the bounding rectangle of the icon or small icon of the subitem. |
| **LVIR_LABEL** | Returns the bounding rectangle of the subitem text. |

### `prc` [in, out]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure to receive the coordinates. The caller is responsible for allocating this structure. *prc* must not be **NULL**.

## Remarks

If *iSubItem* is zero, this macro returns the coordinates of the rectangle to the item pointed to by *plvii*. The value LVIR_SELECTBOUNDS for the parameter *code* is not supported.