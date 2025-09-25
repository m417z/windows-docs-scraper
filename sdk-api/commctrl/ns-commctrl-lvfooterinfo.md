# LVFOOTERINFO structure

## Description

Contains information on a footer in a list-view control.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set of flags that specify which members of this structure contain data to be set or which members are being requested. Currently, this value must be LVFF_ITEMCOUNT, for the **cItems** member.

### `pszText`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Not supported. Must be set to zero.

### `cchTextMax`

Type: **int**

Not supported. Must be set to zero.

### `cItems`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of items in the footer. When this structure is used to get information, this member will be set by the message receiver.

## Remarks

This structure is used with the [ListView_GetFooterInfo](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_getfooterinfo) macro and the [LVM_GETFOOTERINFO](https://learn.microsoft.com/windows/desktop/Controls/lvm-getfooterinfo) message.

The creation of footers in list-view controls is currently not supported.