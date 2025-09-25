# NMUPDOWN structure

## Description

Contains information specific to up-down control notification messages. It is identical to and replaces the
**NM_UPDOWN** structure.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `iPos`

Type: **int**

Signed integer value that represents the up-down control's current position.

### `iDelta`

Type: **int**

Signed integer value that represents the proposed change in the up-down control's position.

## See also

**Reference**

[UDN_DELTAPOS](https://learn.microsoft.com/windows/desktop/Controls/udn-deltapos)

[WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify)