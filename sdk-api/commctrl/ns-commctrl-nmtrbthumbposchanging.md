# NMTRBTHUMBPOSCHANGING structure

## Description

Contains information about a trackbar change notification. This message is sent with the [TRBN_THUMBPOSCHANGING](https://learn.microsoft.com/windows/desktop/Controls/trbn-thumbposchanging) notification.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

A [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that describes the notification.

### `dwPos`

Type: **DWORD**

Position on trackbar.

### `nReason`

Type: **int**

Type of movement as one of the following values: TB_LINEUP, TB_LINEDOWN, TB_PAGEUP, TB_PAGEDOWN, TB_THUMBPOSITION, TB_THUMBTRACK,
TB_TOP, TB_BOTTOM, or TB_ENDTRACK.