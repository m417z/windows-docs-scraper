# NMPGCALCSIZE structure

## Description

Contains and receives information that the pager control uses to calculate the scrollable area of the contained window. It is used with the [PGN_CALCSIZE](https://learn.microsoft.com/windows/desktop/Controls/pgn-calcsize) notification.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification.

### `dwFlag`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that indicates which dimension is being requested. This will be one of the following values:

| Value | Meaning |
| --- | --- |
| **PGF_CALCHEIGHT** | The height of the scrollable area is being requested. The height must be placed in the **iHeight** member before returning from the notification. |
| **PGF_CALCWIDTH** | The width of the scrollable area is being requested. The width must be placed in the **iWidth** member before returning from the notification. |

### `iWidth`

Type: **int**

Receives the desired width of the scrollable area, in pixels.

### `iHeight`

Type: **int**

Receives the desired height of the scrollable area, in pixels.