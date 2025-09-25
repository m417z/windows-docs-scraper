# NMCUSTOMTEXT structure

## Description

Contains information used with custom text notification.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about this notification.

### `hDC`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The device context to draw to.

### `lpString`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The string to draw.

### `nCount`

Type: **int**

Length of lpString.

### `lpRect`

Type: **LPRECT**

The rect to draw in.

### `uFormat`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One or more of the DT_* flags. For more information, see the description of the *uFormat* parameter of the [DrawText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext) function. This may be **NULL**.

### `fLink`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Whether the text is a link.