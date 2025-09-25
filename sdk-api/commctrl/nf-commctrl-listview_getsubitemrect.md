# ListView_GetSubItemRect macro

## Syntax

```cpp
BOOL ListView_GetSubItemRect(
   HWND   hwnd,
   int    iItem,
   int    iSubItem,
   int    code,
   LPRECT prc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Gets information about the rectangle that surrounds a subitem in a list-view control. You can use this macro (recommended) or send the [LVM_GETSUBITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getsubitemrect) message explicitly. This macro is intended to be used only on list-view controls that use the [LVS_REPORT](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a list-view control.

### `iItem`

Type: **int**

The index of the subitem's parent item.

### `iSubItem`

Type: **int**

The one-based index of the subitem.

### `code`

Type: **int**

A portion of the list-view subitem for which to retrieve the bounding rectangle information. This value can be one of the following:

| Value | Meaning |
| --- | --- |
| **LVIR_BOUNDS** | Returns the bounding rectangle of the entire item, including the icon and label. |
| **LVIR_ICON** | Returns the bounding rectangle of the icon or small icon. |
| **LVIR_LABEL** | Returns the bounding rectangle of the entire item, including the icon and label. This is identical to LVIR_BOUNDS. |

### `prc`

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the subitem bounding rectangle information.