# NMTVSTATEIMAGECHANGING structure

## Description

Contains information about an [NM_TVSTATEIMAGECHANGING](https://learn.microsoft.com/windows/desktop/Controls/nm-tvstateimagechanging) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification code.

### `hti`

Type: **HTREEITEM**

Handle to the tree-view item whose state image is changing.

### `iOldStateImageIndex`

Type: **int**

The index of the old state image.

### `iNewStateImageIndex`

Type: **int**

The index of the new state image.