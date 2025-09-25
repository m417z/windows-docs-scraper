# NMLINK structure

## Description

The **NMLINK** Contains notification information. Send this structure with the [NM_CLICK](https://learn.microsoft.com/windows/desktop/Controls/nm-click-syslink) or [NM_RETURN](https://learn.microsoft.com/windows/desktop/Controls/nm-return) messages.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification.

### `item`

Type: **[LITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-litem)**

[LITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-litem) structure that contains information about the link item.

## See also

[LITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-litem)

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)

[NM_CLICK (syslink)](https://learn.microsoft.com/windows/desktop/Controls/nm-click-syslink)

**Reference**