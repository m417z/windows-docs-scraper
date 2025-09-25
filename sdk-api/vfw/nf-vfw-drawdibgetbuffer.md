# DrawDibGetBuffer function

## Description

The **DrawDibGetBuffer** function retrieves the location of the buffer used by DrawDib for decompression.

## Parameters

### `hdd`

Handle to a DrawDib DC.

### `lpbi`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/previous-versions//ms532284(v=vs.85)) structure. This structure is made up of a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure and a 256-entry table defining the colors used by the bitmap.

### `dwSize`

Size, in bytes, of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure pointed to by *lpbi*

### `dwFlags`

Reserved; must be zero.

## Return value

Returns the address of the buffer or **NULL** if no buffer is used. if *lpbr* is not **NULL**, it is filled with a copy of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure describing the buffer.

## See also

[DrawDib Functions](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-functions)