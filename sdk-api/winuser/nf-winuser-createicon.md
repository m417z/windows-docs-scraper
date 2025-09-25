# CreateIcon function

## Description

Creates an icon that has the specified size, colors, and bit patterns.

To create a colored icon at run time you can use the [**CreateIconIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-createiconindirect) function, which creates a icon based on the content of an [**ICONINFO**](https://learn.microsoft.com/windows/desktop/api/Winuser/ns-winuser-iconinfo) structure.

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the instance of the module creating the icon.

### `nWidth` [in]

Type: **int**

The width, in pixels, of the icon. See remarks.

### `nHeight` [in]

Type: **int**

The height, in pixels, of the icon. See remarks.

### `cPlanes` [in]

Type: **BYTE**

The number of planes in the XOR bitmask of the icon. See remarks.

### `cBitsPixel` [in]

Type: **BYTE**

The number of bits-per-pixel in the XOR bitmask of the icon.

### `lpbANDbits` [in]

Type: **const BYTE***

An array of bytes that contains the bit values for the AND bitmask of the icon. This bitmask describes a monochrome bitmap. See remarks.

### `lpbXORbits` [in]

Type: **const BYTE***

An array of bytes that contains the bit values for the XOR bitmask of the icon. This bitmask describes a monochrome or color bitmap. See remarks.

## Return value

Type: **HICON**

If the function succeeds, the return value is a handle to an icon.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To determine the nominal size of the icon, use the [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function, specifying the **SM_CXICON** or **SM_CYICON** value. Also, you can use the DPI-aware version of this API, see (GetSystemMetricsForDpi)(/windows/win32/api/winuser/nf-winuser-getsystemmetricsfordpi). For more information see [Icon Sizes](https://learn.microsoft.com/windows/desktop/menurc/about-icons#icon-sizes) and [High DPI Desktop Application Development on Windows](https://learn.microsoft.com/windows/win32/hidpi/high-dpi-desktop-application-development-on-windows).

For more information about _lpbANDbits_ and _lpbXORbits_ parameters see description of _lpBits_ parameter of [CreateBitmap](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-createbitmap) function.

In case of monochrome icon **CreateIcon** applies the following truth table to the AND and XOR bitmasks:

| AND bitmask | XOR bitmask | Display |
|:-:|:-:|:-:|
| 0 | 0 | Black |
| 0 | 1 | White |
| 1 | 0 | Screen |
| 1 | 1 | Reverse screen |

When you are finished using the icon, destroy it using the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function.

#### Examples

For an example, see [Creating an Icon](https://learn.microsoft.com/windows/desktop/menurc/using-icons).

## See also

[CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-createiconindirect)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

[Icon Sizes](https://learn.microsoft.com/windows/desktop/menurc/about-icons#icon-sizes)