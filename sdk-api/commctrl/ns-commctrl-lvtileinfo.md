# LVTILEINFO structure

## Description

Provides information about an item in a list-view control when it is displayed in tile view.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the **LVTILEINFO** structure.

### `iItem`

Type: **int**

The item for which the information is retrieved or set.

### `cColumns`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of data columns displayed for this item. When retrieving information, initialize this value to the size of the **puColumns** array. On return, the member is set to the number of columns actually set for the item.

### `puColumns`

Type: **[PUINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to an array of column indices, specifying which columns are displayed for this item, and the order of those columns. When retrieving information, allocate an array large enough to hold the greatest number of columns expected.

### `piColFmt`

Type: **int***

A pointer to an array of column formats (for example, LVCFMT_LEFT), one for each of the columns specified in **puColumns**. When retrieving information, allocate an array large enough to hold the greatest number of column formats expected.

## Remarks

In tile view, the item name is displayed to the right of the icon. You can specify additional subitems (corresponding to columns in the details view), to be displayed on lines below the item name. The **puColumns** array contains the indices of subitems to be displayed. Indices should be greater than 0, because subitem 0, the item name, is already displayed.

Column information can also be set in the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure when creating the list item.