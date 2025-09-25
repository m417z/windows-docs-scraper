# SCROLLINFO structure

## Description

The **SCROLLINFO** structure contains scroll bar parameters to be set by the [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo) function (or [SBM_SETSCROLLINFO](https://learn.microsoft.com/windows/desktop/Controls/sbm-setscrollinfo) message), or retrieved by the [GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo) function (or [SBM_GETSCROLLINFO](https://learn.microsoft.com/windows/desktop/Controls/sbm-getscrollinfo) message).

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the size, in bytes, of this structure. The caller must set this to sizeof(**SCROLLINFO**).

### `fMask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the scroll bar parameters to set or retrieve. This member can be a combination of the following values:

| Value | Meaning |
| --- | --- |
| **SIF_ALL** | Combination of SIF_PAGE, SIF_POS, SIF_RANGE, and SIF_TRACKPOS. |
| **SIF_DISABLENOSCROLL** | This value is used only when setting a scroll bar's parameters. If the scroll bar's new parameters make the scroll bar unnecessary, disable the scroll bar instead of removing it. |
| **SIF_PAGE** | The **nPage** member contains the page size for a proportional scroll bar. |
| **SIF_POS** | The **nPos** member contains the scroll box position, which is not updated while the user drags the scroll box. |
| **SIF_RANGE** | The **nMin** and **nMax** members contain the minimum and maximum values for the scrolling range. |
| **SIF_TRACKPOS** | The **nTrackPos** member contains the current position of the scroll box while the user is dragging it. |

### `nMin`

Type: **int**

Specifies the minimum scrolling position.

### `nMax`

Type: **int**

Specifies the maximum scrolling position.

### `nPage`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the page size, in device units. A scroll bar uses this value to determine the appropriate size of the proportional scroll box.

### `nPos`

Type: **int**

Specifies the position of the scroll box.

### `nTrackPos`

Type: **int**

Specifies the immediate position of a scroll box that the user is dragging. An application can retrieve this value while processing the SB_THUMBTRACK request code. An application cannot set the immediate scroll position; the [SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo) function ignores this member.

## See also

[GetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollinfo)

**Reference**

[SBM_GETSCROLLINFO](https://learn.microsoft.com/windows/desktop/Controls/sbm-getscrollinfo)

[SBM_SETSCROLLINFO](https://learn.microsoft.com/windows/desktop/Controls/sbm-setscrollinfo)

[SetScrollInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setscrollinfo)