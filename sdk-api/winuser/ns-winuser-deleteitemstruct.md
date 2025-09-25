# DELETEITEMSTRUCT structure

## Description

Describes a deleted list box or combo box item. The *lParam* parameter of a [WM_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-deleteitem) message contains a pointer to this structure. When an item is removed from a list box or combo box or when a list box or combo box is destroyed, the system sends the **WM_DELETEITEM** message to the owner for each deleted item.

The system sends a [WM_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-deleteitem) message only for items deleted from an owner-drawn list box (with the [LBS_OWNERDRAWFIXED](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) or [LBS_OWNERDRAWVARIABLE](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) style) or owner-drawn combo box (with the [CBS_OWNERDRAWFIXED](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) or [CBS_OWNERDRAWVARIABLE](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) style).

## Members

### `CtlType`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the item was deleted from a list box or a combo box. One of the following values.

| Value | Meaning |
| --- | --- |
| **ODT_LISTBOX** | A list box. |
| **ODT_COMBOBOX** | A combo box. |

### `CtlID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The identifier of the list box or combo box.

### `itemID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the item in the list box or combo box being removed.

### `hwndItem`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `itemData`

Type: **[ULONG_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined data for the item. This value is passed to the control in the *lParam* parameter of the message that adds the item to the list box or combo box.

## See also

[WM_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-deleteitem)