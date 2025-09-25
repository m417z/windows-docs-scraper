# DIBSECTION structure

## Description

The **DIBSECTION** structure contains information about a DIB created by calling the [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection) function. A **DIBSECTION** structure includes information about the bitmap's dimensions, color format, color masks, optional file mapping object, and optional bit values storage offset. An application can obtain a filled-in **DIBSECTION** structure for a given DIB by calling the [GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject) function.

## Members

### `dsBm`

A [BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap) data structure that contains information about the DIB: its type, its dimensions, its color capacities, and a pointer to its bit values.

### `dsBmih`

A [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure that contains information about the color format of the DIB.

### `dsBitfields`

Specifies three color masks for the DIB. This field is only valid when the **BitCount** member of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure has a value greater than 8. Each color mask indicates the bits that are used to encode one of the three color channels (red, green, and blue).

### `dshSection`

Contains a handle to the file mapping object that the [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection) function used to create the DIB.
If **CreateDIBSection** was called with a **NULL** value for its *hSection* parameter,
causing the system to allocate memory for the bitmap, the *dshSection* member will be **NULL**.

### `dsOffset`

The offset to the bitmap's bit values within the file mapping object referenced by *dshSection*.
If *dshSection* is **NULL**, the *dsOffset* value has no meaning.

## See also

[BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap)

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader)

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[GetDIBColorTable](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibcolortable)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)