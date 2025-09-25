# NMLVCACHEHINT structure

## Description

Contains information used to update the cached item information for use with a [virtual list view](https://learn.microsoft.com/windows/desktop/Controls/list-view-controls-overview).

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification message.

### `iFrom`

Type: **int**

Starting index of the requested range of items. This value is inclusive.

### `iTo`

Type: **int**

Ending index of the requested range of items. This value is inclusive.