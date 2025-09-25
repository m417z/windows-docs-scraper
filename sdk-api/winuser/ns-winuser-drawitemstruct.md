# DRAWITEMSTRUCT structure

## Description

Provides information that the owner window uses to determine how to paint an owner-drawn control or menu item. The owner window of the owner-drawn control or menu item receives a pointer to this structure as the *lParam* parameter of the [WM_DRAWITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-drawitem) message.

## Members

### `CtlType`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The control type. This member can be one of the following values. See Remarks.

| Value | Meaning |
| --- | --- |
| **ODT_BUTTON** | Owner-drawn button |
| **ODT_COMBOBOX** | Owner-drawn combo box |
| **ODT_LISTBOX** | Owner-drawn list box |
| **ODT_LISTVIEW** | List-view control |
| **ODT_MENU** | Owner-drawn menu item |
| **ODT_STATIC** | Owner-drawn static control |
| **ODT_TAB** | Tab control |

### `CtlID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The identifier of the combo box, list box, button, or static control. This member is not used for a menu item.

### `itemID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The menu item identifier for a menu item or the index of the item in a list box or combo box. For an empty list box or combo box, this member can be `-1`. This allows the application to draw only the focus rectangle at the coordinates specified by the **rcItem** member even though there are no items in the control. This indicates to the user whether the list box or combo box has the focus. How the bits are set in the **itemAction** member determines whether the rectangle is to be drawn as though the list box or combo box has the focus.

### `itemAction`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The required drawing action. This member can be one or more of the values.

| Value | Meaning |
| --- | --- |
| **ODA_DRAWENTIRE** | The entire control needs to be drawn. |
| **ODA_FOCUS** | The control has lost or gained the keyboard focus. The **itemState** member should be checked to determine whether the control has the focus. |
| **ODA_SELECT** | The selection status has changed. The **itemState** member should be checked to determine the new selection state. |

### `itemState`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The visual state of the item after the current drawing action takes place. This member can be a combination of the values shown in the following table.

| Value | Meaning |
| --- | --- |
| **ODS_CHECKED** | The menu item is to be checked. This bit is used only in a menu. |
| **ODS_COMBOBOXEDIT** | The drawing takes place in the selection field (edit control) of an owner-drawn combo box. |
| **ODS_DEFAULT** | The item is the default item. |
| **ODS_DISABLED** | The item is to be drawn as disabled. |
| **ODS_FOCUS** | The item has the keyboard focus. |
| **ODS_GRAYED** | The item is to be grayed. This bit is used only in a menu. |
| **ODS_HOTLIGHT** | The item is being hot-tracked, that is, the item will be highlighted when the mouse is on the item. |
| **ODS_INACTIVE** | The item is inactive and the window associated with the menu is inactive. |
| **ODS_NOACCEL** | The control is drawn without the keyboard accelerator cues. |
| **ODS_NOFOCUSRECT** | The control is drawn without focus indicator cues. |
| **ODS_SELECTED** | The menu item's status is selected. |

### `hwndItem`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control for combo boxes, list boxes, buttons, and static controls. For menus, this member is a handle to the menu that contains the item.

### `hDC`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a device context; this device context must be used when performing drawing operations on the control.

### `rcItem`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A rectangle that defines the boundaries of the control to be drawn. This rectangle is in the device context specified by the **hDC** member. The system automatically clips anything that the owner window draws in the device context for combo boxes, list boxes, and buttons, but does not clip menu items. When drawing menu items, the owner window must not draw outside the boundaries of the rectangle defined by the **rcItem** member.

### `itemData`

Type: **[ULONG_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The application-defined value associated with the menu item. For a control, this parameter specifies the value last assigned to the list box or combo box by the [LB_SETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/lb-setitemdata) or [CB_SETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/cb-setitemdata) message. If the list box or combo box has the [LBS_HASSTRINGS](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) or [CBS_HASSTRINGS](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) style, this value is initially zero. Otherwise, this value is initially the value that was passed to the list box or combo box in the *lParam* parameter of one of the following messages:

* [CB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-addstring)
* [CB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-insertstring)
* [LB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-addstring)
* [LB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-insertstring)

If **CtlType** is **ODT_BUTTON** or **ODT_STATIC**, **itemData** is zero.

## Remarks

Some control types, such as status bars, do not set the value of **CtlType**.

## See also

[CB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-addstring)

[CB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-insertstring)

[CB_SETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/cb-setitemdata)

[LB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-addstring)

[LB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-insertstring)

[LB_SETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/lb-setitemdata)

**Reference**

[WM_DRAWITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-drawitem)