# MEASUREITEMSTRUCT structure

## Description

Informs the system of the dimensions of an owner-drawn control or menu item. This allows the system to process user interaction with the control correctly.

## Members

### `CtlType`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The control type. This member can be one of the values shown in the following table.

| Value | Meaning |
| --- | --- |
| **ODT_COMBOBOX** | Owner-drawn combo box |
| **ODT_LISTBOX** | Owner-drawn list box |
| **ODT_LISTVIEW** | Owner-draw list-view control |
| **ODT_MENU** | Owner-drawn menu |

### `CtlID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The identifier of the combo box or list box. This member is not used for a menu.

### `itemID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The identifier for a menu item or the position of a list box or combo box item. This value is specified for a list box only if it has the [LBS_OWNERDRAWVARIABLE](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) style; this value is specified for a combo box only if it has the [CBS_OWNERDRAWVARIABLE](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) style.

### `itemWidth`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width, in pixels, of a menu item. Before returning from the message, the owner of the owner-drawn menu item must fill this member.

### `itemHeight`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The height, in pixels, of an individual item in a list box or a menu. Before returning from the message, the owner of the owner-drawn combo box, list box, or menu item must fill out this member.

### `itemData`

Type: **[ULONG_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The application-defined value associated with the menu item. For a control, this member specifies the value last assigned to the list box or combo box by the [LB_SETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/lb-setitemdata) or [CB_SETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/cb-setitemdata) message. If the list box or combo box has the LB_HASSTRINGS or CB_HASSTRINGS style, this value is initially zero. Otherwise, this value is initially the value passed to the list box or combo box in the
*lParam* parameter of one of the following messages:

* [CB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-addstring)
* [CB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-insertstring)
* [LB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-addstring)
* [LB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-insertstring)

## Remarks

The owner window of an owner-drawn control receives a pointer to the **MEASUREITEMSTRUCT** structure as the *lParam* parameter of a [WM_MEASUREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-measureitem) message. The owner-drawn control sends this message to its owner window when the control is created. The owner then fills in the appropriate members in the structure for the control and returns. This structure is common to all owner-drawn controls except the owner-drawn button control whose size is predetermined by its window.

If an application does not fill the appropriate members of **MEASUREITEMSTRUCT**, the control or menu item may not be drawn properly.

## See also

[CB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-addstring)

[CB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/cb-insertstring)

[CB_SETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/cb-setitemdata)

[LB_ADDSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-addstring)

[LB_INSERTSTRING](https://learn.microsoft.com/windows/desktop/Controls/lb-insertstring)

[LB_SETITEMDATA](https://learn.microsoft.com/windows/desktop/Controls/lb-setitemdata)

**Reference**

[WM_MEASUREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-measureitem)