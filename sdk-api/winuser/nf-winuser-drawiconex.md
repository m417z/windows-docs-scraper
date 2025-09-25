# DrawIconEx function

## Description

Draws an icon or cursor into the specified device context, performing the specified raster operations, and stretching or compressing the icon or cursor as specified.

## Parameters

### `hdc` [in]

Type: **HDC**

A handle to the device context into which the icon or cursor will be drawn.

### `xLeft` [in]

Type: **int**

The logical x-coordinate of the upper-left corner of the icon or cursor.

### `yTop` [in]

Type: **int**

The logical y-coordinate of the upper-left corner of the icon or cursor.

### `hIcon` [in]

Type: **HICON**

A handle to the icon or cursor to be drawn. This parameter can identify an animated cursor.

### `cxWidth` [in]

Type: **int**

The logical width of the icon or cursor. If this parameter is zero and the *diFlags* parameter is **DI_DEFAULTSIZE**, the function uses the **SM_CXICON** system metric value to set the width. If this parameter is zero and **DI_DEFAULTSIZE** is not used, the function uses the actual resource width.

### `cyWidth` [in]

Type: **int**

The logical height of the icon or cursor. If this parameter is zero and the *diFlags* parameter is **DI_DEFAULTSIZE**, the function uses the **SM_CYICON** system metric value to set the width. If this parameter is zero and **DI_DEFAULTSIZE** is not used, the function uses the actual resource height.

### `istepIfAniCur` [in]

Type: **UINT**

The index of the frame to draw, if *hIcon* identifies an animated cursor. This parameter is ignored if *hIcon* does not identify an animated cursor.

### `hbrFlickerFreeDraw` [in, optional]

Type: **HBRUSH**

A handle to a brush that the system uses for flicker-free drawing. If *hbrFlickerFreeDraw* is a valid brush handle, the system creates an offscreen bitmap using the specified brush for the background color, draws the icon or cursor into the bitmap, and then copies the bitmap into the device context identified by *hdc*. If *hbrFlickerFreeDraw* is **NULL**, the system draws the icon or cursor directly into the device context.

### `diFlags` [in]

Type: **UINT**

The drawing flags. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DI_COMPAT**<br><br>0x0004 | This flag is ignored. |
| **DI_DEFAULTSIZE**<br><br>0x0008 | Draws the icon or cursor using the width and height specified by the system metric values for icons, if the *cxWidth* and *cyWidth* parameters are set to zero. If this flag is not specified and *cxWidth* and *cyWidth* are set to zero, the function uses the actual resource size. |
| **DI_IMAGE**<br><br>0x0002 | Draws the icon or cursor using the image. See Remarks. |
| **DI_MASK**<br><br>0x0001 | Draws the icon or cursor using the mask. See Remarks. |
| **DI_NOMIRROR**<br><br>0x0010 | Draws the icon as an unmirrored icon. By default, the icon is drawn as a mirrored icon if *hdc* is mirrored. |
| **DI_NORMAL**<br><br>0x0003 | Combination of **DI_IMAGE** and **DI_MASK**. See Remarks. |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **DrawIconEx** function places the icon's upper-left corner at the location specified by the *xLeft* and *yTop* parameters. The location is subject to the current mapping mode of the device context.

If only one of the **DI_IMAGE** and **DI_MASK** flags is set, then the corresponding bitmap is drawn with the **SRCCOPY** [raster operation code](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-bitblt).

If both the **DI_IMAGE** and **DI_MASK** flags are set:
* If the icon or cursor is a 32-bit alpha-blended icon or cursor, then the image is drawn with **AC_SRC_OVER** [blend function](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-blendfunction) and the mask is ignored.
* For all other icons or cursors, the mask is drawn with the **SRCAND** [raster operation code](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-bitblt), and the image is drawn with the **SRCINVERT** [raster operation code](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-bitblt)

To duplicate `DrawIcon (hDC, X, Y, hIcon)`, call **DrawIconEx** as follows:

``` syntax
DrawIconEx (hDC, X, Y, hIcon, 0, 0, 0, NULL, DI_NORMAL | DI_COMPAT | DI_DEFAULTSIZE);
```

## See also

**Conceptual**

[CopyImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyimage)

[DrawIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawicon)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

[LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea)

**Reference**

[BitBlt](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-bitblt)

[AlphaBlend](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-alphablend)

[BLENDFUNCTION](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-blendfunction)