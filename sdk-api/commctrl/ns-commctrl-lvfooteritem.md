# LVFOOTERITEM structure

## Description

Contains information on a footer item.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set of flags that specify which members of this structure contain data to be set or which members are being requested. This parameter must be one of the following values:

| Value | Meaning |
| --- | --- |
| **LVFIF_TEXT** | The **pszText** member is valid input from the caller or is requested and thus should be set by the receiver. |
| **LVFIF_STATE** | The **state** member is valid input from the caller or is requested and thus should be set by the receiver. |

### `iItem`

Type: **int**

The index of the item.

### `pszText`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated, Unicode buffer. The calling process is responsible for allocating the buffer.

### `cchTextMax`

Type: **int**

The number of **WCHAR****s** in the buffer pointed to by **pszText**, including the terminating **NULL**.

### `state`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates the item's state. The **stateMask** member indicates the valid bits of this member. Currently, **state** must be set to the following:

| Value | Meaning |
| --- | --- |
| **LVFIS_FOCUSED** | Bit indicating focus state. Set if the item is in focus, otherwise cleared. |

### `stateMask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying which bits of the **state** member will be retrieved or modified. Currently, this value must be the following:

| Value | Meaning |
| --- | --- |
| **LVFIS_FOCUSED** | The LVFIS_FOCUSED bit of member **state** is valid. For example, setting this member to LVFIS_FOCUSED will cause the focus state to be retrieved to member **state**. |

## Remarks

This structure is used with the [ListView_GetFooterItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_getfooteritem) macro and the [LVM_GETFOOTERITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getfooteritem) message.