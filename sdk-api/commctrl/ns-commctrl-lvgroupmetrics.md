# LVGROUPMETRICS structure

## Description

Contains information about the display of groups in a list-view control.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the **LVGROUPMETRICS** structure.

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags that specify which members contain or are to receive valid data. Can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| LVGMF_BORDERCOLOR | Not implemented. |
| LVGMF_BORDERSIZE | The **Left**, **Top**, **Right**, and **Bottom** members are valid. |
| LVGMF_NONE | No members are valid. |
| LVGMF_TEXTCOLOR | Not implemented. |

### `Left`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the width of the left border in icon, small icon, or tile view.

### `Top`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the width of the top border in all group views.

### `Right`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the width of the right border in icon, small icon, or tile view.

### `Bottom`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the width of the bottom border in all group views.

### `crLeft`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the color of the left border. Not implemented.

### `crTop`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the color of the top border. Not implemented.

### `crRight`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the color of the right border. Not implemented.

### `crBottom`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the color of the bottom border. Not implemented.

### `crHeader`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the color of the header text. Not implemented.

### `crFooter`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the color of the footer text. Not implemented.

## Remarks

The width of a border determines the margins of the area within which items are placed. The top border is highlighted when the user moves the cursor over it, and when the user clicks on this border in a list that allows multiple selection, all items in the group are selected.

## See also

[LVM_GETGROUPMETRICS](https://learn.microsoft.com/windows/desktop/Controls/lvm-getgroupmetrics)

[LVM_SETGROUPMETRICS](https://learn.microsoft.com/windows/desktop/Controls/lvm-setgroupmetrics)

[ListView_GetGroupMetrics](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_getgroupmetrics)

[ListView_SetGroupMetrics](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setgroupmetrics)

**Reference**