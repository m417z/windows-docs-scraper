# COMPAREITEMSTRUCT structure

## Description

Supplies the identifiers and application-supplied data for two items in a sorted, owner-drawn list box or combo box.

Whenever an application adds a new item to an owner-drawn list box or combo box created with the [CBS_SORT](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles) or [LBS_SORT](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles) style, the system sends the owner a [WM_COMPAREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-compareitem) message. The *lParam* parameter of the message contains a long pointer to a **COMPAREITEMSTRUCT** structure. Upon receiving the message, the owner compares the two items and returns a value indicating which item sorts before the other.

## Members

### `CtlType`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An ODT_LISTBOX (owner-drawn list box) or ODT_COMBOBOX (an owner-drawn combo box).

### `CtlID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The identifier of the list box or combo box.

### `hwndItem`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `itemID1`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first item in the list box or combo box being compared. This member will be –1 if the item has not been inserted or when searching for a potential item in the list box or combo box.

### `itemData1`

Type: **[ULONG_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-supplied data for the first item being compared. (This value was passed as the *lParam* parameter of the message that added the item to the list box or combo box.)

### `itemID2`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the second item in the list box or combo box being compared.

### `itemData2`

Type: **[ULONG_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-supplied data for the second item being compared. This value was passed as the
*lParam* parameter of the message that added the item to the list box or combo box. This member will be
–1 if the item has not been inserted or when searching for a potential item in the list box or combo box.

### `dwLocaleId`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The locale identifier. To create a locale identifier, use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro.

## See also

[Combo Boxes](https://learn.microsoft.com/windows/desktop/Controls/combo-boxes)

**Conceptual**

[MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid)

**Other Resources**

**Reference**

[WM_COMPAREITEM](https://learn.microsoft.com/windows/desktop/Controls/wm-compareitem)