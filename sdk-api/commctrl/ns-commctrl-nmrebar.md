# NMREBAR structure

## Description

Contains information used in handling various rebar notifications.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set of flags that define which members of this structure contain valid information. This can be one or more of the following values:

| Value | Meaning |
| --- | --- |
| **RBNM_ID** | The **wID** member contains valid information. |
| **RBNM_LPARAM** | The **lParam** member contains valid information. |
| **RBNM_STYLE** | The **fStyle** member contains valid information. |

### `uBand`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index of the band affected by the notification. This will be -1 if no band is affected.

### `fStyle`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The style of the band. This is one or more of the RBBS_ styles detailed in the
**fStyle** member of the [REBARBANDINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-rebarbandinfoa) structure. This member is only valid if
**dwMask** contains RBNM_STYLE.

### `wID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined identifier of the band. This member is only valid if
**dwMask** contains RBNM_ID.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined value associated with the band. This member is only valid if
**dwMask** contains RBNM_LPARAM.