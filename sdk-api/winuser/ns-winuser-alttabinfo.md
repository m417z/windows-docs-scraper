# ALTTABINFO structure

## Description

Contains status information for the application-switching (ALT+TAB) window.

## Members

### `cbSize`

Type: **DWORD**

The size, in bytes, of the structure. The caller must set this to `sizeof(ALTTABINFO)`.

### `cItems`

Type: **int**

The number of items in the window.

### `cColumns`

Type: **int**

The number of columns in the window.

### `cRows`

Type: **int**

The number of rows in the window.

### `iColFocus`

Type: **int**

The column of the item that has the focus.

### `iRowFocus`

Type: **int**

The row of the item that has the focus.

### `cxItem`

Type: **int**

The width of each icon in the application-switching window.

### `cyItem`

Type: **int**

The height of each icon in the application-switching window.

### `ptStart`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The top-left corner of the first icon.

## See also

**Conceptual**

[GetAltTabInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getalttabinfoa)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)