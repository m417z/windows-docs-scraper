# SCROLLBARINFO structure

## Description

The **SCROLLBARINFO** structure contains scroll bar information.

## Members

### `cbSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the size, in bytes, of the structure. Before calling the [GetScrollBarInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollbarinfo) function, set **cbSize** to **sizeof**(**SCROLLBARINFO**).

### `rcScrollBar`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

Coordinates of the scroll bar as specified in a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure.

### `dxyLineButton`

Type: **int**

Height or width of the thumb.

### `xyThumbTop`

Type: **int**

Position of the top or left of the thumb.

### `xyThumbBottom`

Type: **int**

Position of the bottom or right of the thumb.

### `reserved`

Type: **int**

Reserved.

### `rgstate`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[CCHILDREN_SCROLLBAR+1]**

An array of **DWORD** elements. Each element indicates the state of a scroll bar component. The following values show the scroll bar component that corresponds to each array index.

| Index | Scroll bar component |
| --- | --- |
| 0 | The scroll bar itself. |
| 1 | The top or right arrow button. |
| 2 | The page up or page right region. |
| 3 | The scroll box (thumb). |
| 4 | The page down or page left region. |
| 5 | The bottom or left arrow button. |

The **DWORD** element for each scroll bar component can include a combination of the following bit flags.

| Value | Meaning |
| --- | --- |
| **STATE_SYSTEM_INVISIBLE** | For the scroll bar itself, indicates the specified vertical or horizontal scroll bar does not exist. For the page up or page down regions, indicates the thumb is positioned such that the region does not exist. |
| **STATE_SYSTEM_OFFSCREEN** | For the scroll bar itself, indicates the window is sized such that the specified vertical or horizontal scroll bar is not currently displayed. |
| **STATE_SYSTEM_PRESSED** | The arrow button or page region is pressed. |
| **STATE_SYSTEM_UNAVAILABLE** | The component is disabled. |

## See also

**Conceptual**

[GetScrollBarInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getscrollbarinfo)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[Scroll Bars](https://learn.microsoft.com/windows/desktop/Controls/scroll-bars)