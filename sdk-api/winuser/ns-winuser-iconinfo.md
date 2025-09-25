# ICONINFO structure

## Description

Contains information about an icon or a cursor.

## Members

### `fIcon`

Type: **BOOL**

Specifies whether this structure defines an icon or a cursor. A value of **TRUE** specifies an icon; **FALSE** specifies a cursor.

### `xHotspot`

Type: **DWORD**

The x-coordinate of a cursor's hot spot. If this structure defines an icon, the hot spot is always in the center of the icon, and this member is ignored.

### `yHotspot`

Type: **DWORD**

The y-coordinate of the cursor's hot spot. If this structure defines an icon, the hot spot is always in the center of the icon, and this member is ignored.

### `hbmMask`

Type: **HBITMAP**

A handle to the icon monochrome mask [bitmap](https://learn.microsoft.com/windows/win32/gdi/bitmaps).

### `hbmColor`

Type: **HBITMAP**

A handle to the icon color [bitmap](https://learn.microsoft.com/windows/win32/gdi/bitmaps).

## Remarks

For monochrome icons, the **hbmMask** is twice the height of the icon (with the AND mask on top and the XOR mask on the bottom), and **hbmColor** is **NULL**. Also, in this case the height should be an even multiple of two.

For color icons, the **hbmMask** and **hbmColor** bitmaps are the same size, each of which is the size of the icon.

You can use a [GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject) function to get contents of **hbmMask** and **hbmColor** in the [BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap) structure. The bitmap bits can be obtained with call to [GetDIBits](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-getdibits) on the bitmaps in this structure.

## See also

**Conceptual**

[CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconindirect)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

[Bitmaps](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[GetDIBits](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-getdibits)

[BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap)

**Reference**