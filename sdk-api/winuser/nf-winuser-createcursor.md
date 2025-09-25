# CreateCursor function

## Description

Creates a monochrome cursor having the specified size, bit patterns, and hot spot.

To create a colored cursor at run time you can use the [**CreateIconIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-createiconindirect) function, which creates a cursor based on the content of an [**ICONINFO**](https://learn.microsoft.com/windows/desktop/api/Winuser/ns-winuser-iconinfo) structure.

## Parameters

### `hInst` [in, optional]

Type: **HINSTANCE**

A handle to the current instance of the application creating the cursor.

### `xHotSpot` [in]

Type: **int**

The horizontal position of the cursor's hot spot.

### `yHotSpot` [in]

Type: **int**

The vertical position of the cursor's hot spot.

### `nWidth` [in]

Type: **int**

The width of the cursor, in pixels.

### `nHeight` [in]

Type: **int**

The height of the cursor, in pixels.

### `pvANDPlane` [in]

Type: **const VOID***

An array of bytes that contains the bit values for the AND mask of the cursor, as in a monochrome bitmap. See remarks.

### `pvXORPlane` [in]

Type: **const VOID***

An array of bytes that contains the bit values for the XOR mask of the cursor, as in a monochrome bitmap. See remarks.

## Return value

Type: **HCURSOR**

If the function succeeds, the return value is a handle to the cursor.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To determine the nominal size of a cursor, use the [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function, specifying the **SM_CXCURSOR** or **SM_CYCURSOR** value. Also, you can use the DPI-aware version of this API, see [GetSystemMetricsForDpi](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getsystemmetricsfordpi). For more information see [High DPI Desktop Application Development on Windows](https://learn.microsoft.com/windows/win32/hidpi/high-dpi-desktop-application-development-on-windows).

For more information about _pvANDPlane_ and _pvXORPlane_ parameters see description of _lpBits_ parameter of [CreateBitmap](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-createbitmap) function.

**CreateCursor** applies the following truth table to the AND and XOR bitmasks:

| AND bitmask | XOR bitmask | Display |
|:-:|:-:|:-:|
| 0 | 0 | Black |
| 0 | 1 | White |
| 1 | 0 | Screen |
| 1 | 1 | Reverse screen |

Before closing, an application must call the [DestroyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycursor) function to free any system resources associated with the cursor.

### DPI Virtualization

This API does not participate in DPI virtualization. The output returned is in terms of physical coordinates, and is not affected by the DPI of the calling thread. Note that the cursor created may still be scaled to match the DPI of any given window it is drawn into.

#### Examples

For an example, see [Creating a Cursor](https://learn.microsoft.com/windows/desktop/menurc/using-cursors).

## See also

[CreateIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createicon)

[CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-createiconindirect)

[DestroyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycursor)

[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)