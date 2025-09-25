# NMPGSCROLL structure

## Description

Contains and receives information that the pager control uses when scrolling the contained window. It is used with the [PGN_SCROLL](https://learn.microsoft.com/windows/desktop/Controls/pgn-scroll) notification.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification.

### `fwKeys`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Modifier keys that are down when the scroll occurs. This can be one or more of the following values:

| Value | Meaning |
| --- | --- |
| **0** | None of the modifier keys are down. |
| **PGK_SHIFT** | The SHIFT key is down. |
| **PGK_CONTROL** | The CONTROL key is down. |
| **PGK_MENU** | The ALT key is down. |

### `rcParent`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

Contains the client rectangle of the pager control.

### `iDir`

Type: **int**

Value that indicates in which direction the scroll is occurring. This will be one of the following values:

| Value | Meaning |
| --- | --- |
| **PGF_SCROLLDOWN** | The contained window is being scrolled down. |
| **PGF_SCROLLLEFT** | The contained window is being scrolled to the left. |
| **PGF_SCROLLRIGHT** | The contained window is being scrolled to the right. |
| **PGF_SCROLLUP** | The contained window is being scrolled up. |

### `iXpos`

Type: **int**

Contains the horizontal scroll position of the contained window, in pixels, before the scroll action.

### `iYpos`

Type: **int**

Contains the vertical scroll position of the contained window, in pixels, before the scroll action.

### `iScroll`

Type: **int**

On entry, contains the default scroll delta in pixels. This member can be modified to contain a different scroll delta amount if desired. This value is always positive, regardless of the scroll direction.