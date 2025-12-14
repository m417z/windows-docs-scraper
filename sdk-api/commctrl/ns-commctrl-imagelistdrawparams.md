# IMAGELISTDRAWPARAMS structure

## Description

Contains information about an image list draw operation and is used with the [IImageList::Draw](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-draw) function.

## Members

### `cbSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of this structure, in bytes.

### `himl`

Type: **HIMAGELIST**

A handle to the image list that contains the image to be drawn.

### `i`

Type: **int**

The zero-based index of the image to be drawn.

### `hdcDst`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the destination device context.

### `x`

Type: **int**

The x-coordinate that specifies where the image is drawn.

### `y`

Type: **int**

The y-coordinate that specifies where the image is drawn.

### `cx`

Type: **int**

A value that specifies the number of pixels to draw, relative to the upper-left corner of the drawing operation as specified by **xBitmap** and **yBitmap**. If **cx** and **cy** are zero, then [Draw](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-draw) draws the entire valid section. The method does not ensure that the parameters are valid.

### `cy`

Type: **int**

A value that specifies the number of pixels to draw, relative to the upper-left corner of the drawing operation as specified by **xBitmap** and **yBitmap**. If **cx** and **cy** are zero, then [Draw](https://learn.microsoft.com/windows/desktop/api/commoncontrols/nf-commoncontrols-iimagelist-draw) draws the entire valid section. The method does not ensure that the parameters are valid.

### `xBitmap`

Type: **int**

The x-coordinate that specifies the upper-left corner of the drawing operation in reference to the image itself. Pixels of the image that are to the left of **xBitmap** and above **yBitmap** do not appear.

### `yBitmap`

Type: **int**

The y-coordinate that specifies the upper-left corner of the drawing operation in reference to the image itself. Pixels of the image that are to the left of **xBitmap** and above **yBitmap** do not appear.

### `rgbBk`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The image background color. This parameter can be an application-defined RGB value or one of the following values.

| Value | Meaning |
| --- | --- |
| **CLR_DEFAULT** | The default background color. The image is drawn using the image list background color. |
| **CLR_NONE** | No background color. The image is drawn transparently. |

### `rgbFg`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The image foreground color. This member is used only if **fStyle** includes the [ILD_BLEND25](https://learn.microsoft.com/windows/desktop/Controls/imagelistdrawflags) or [ILD_BLEND50](https://learn.microsoft.com/windows/desktop/Controls/imagelistdrawflags) flag. This parameter can be an application-defined RGB value or one of the following values:

| Value | Meaning |
| --- | --- |
| **CLR_DEFAULT** | The default foreground color. The image is drawn using the system highlight color as the foreground color. |
| **CLR_NONE** | No blend color. The image is blended with the color of the destination device context. |

### `fStyle`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A flag specifying the drawing style and, optionally, the overlay image. See the comments section at the end of this topic for information on the overlay image. This member can contain one or more [image list drawing flags](https://learn.microsoft.com/windows/desktop/Controls/imagelistdrawflags).

### `dwRop`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value specifying a raster operation code. These codes define how the color data for the source rectangle will be combined with the color data for the destination rectangle to achieve the final color. This member is ignored if **fStyle** does not include the [ILD_ROP](https://learn.microsoft.com/windows/desktop/Controls/imagelistdrawflags) flag. Some common raster operation codes include:

| Value | Meaning |
| --- | --- |
| **BLACKNESS** | Fills the destination rectangle using the color associated with index zero in the physical palette. (This color is black for the default physical palette.) |
| **DSTINVERT** | Inverts the destination rectangle. |
| **MERGECOPY** | Merges the source rectangle colors with the specified pattern by using the Boolean **AND** operator. |
| **MERGEPAINT** | Merges the inverted source rectangle colors with the destination rectangle colors by using the Boolean **OR** operator. |
| **NOTSRCCOPY** | Copies the inverted source rectangle to the destination. |
| **NOTSRCERASE** | Combines the source and destination rectangle colors by using the Boolean **OR** operator. Inverts the resultant color. |
| **PATCOPY** | Copies the specified pattern into the destination bitmap. |
| **PATINVERT** | Combines the specified pattern colors with the destination rectangle colors by using the Boolean **XOR** operator. |
| **PATPAINT** | Combines the pattern colors with the inverted source rectangle colors and combines the result with the destination rectangle colors by using the Boolean **OR** operator. |
| **SRCAND** | Combines the source and destination rectangle colors by using the Boolean **AND** operator. |
| **SRCCOPY** | Copies the source rectangle directly to the destination rectangle. |
| **SRCERASE** | Combines the destination rectangle's inverted colors with the source rectangle colors by using the Boolean **AND** operator. |
| **SRCINVERT** | Combines the source and destination rectangle colors by using the Boolean **XOR** operator. |
| **SRCPAINT** | Combines the source and destination rectangle colors by using the Boolean **OR** operator. |
| **WHITENESS** | Fills the destination rectangle using the color associated with index one in the physical palette. This color is white for the default physical palette. |

### `fState`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A flag that specifies the drawing state. This member can contain one or more [image list state flags](https://learn.microsoft.com/windows/desktop/Controls/imageliststateflags). You must use comctl32.dll version 6 to use this member. See the Remarks.

### `Frame`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Used with the **alpha blending** effect.

When used with [ILS_ALPHA](https://learn.microsoft.com/windows/desktop/Controls/imageliststateflags), this member holds the value for the alpha channel. This value can be from 0 to 255, with 0 being completely transparent, and 255 being completely opaque.

You must use comctl32.dll version 6 to use this member. See the Remarks.

### `crEffect`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A color used for the **glow** and **shadow** effects. You must use comctl32.dll version 6 to use this member. See the Remarks.

## Remarks

An overlay image is an image that is drawn on top of the primary image specified in the **i** member of this structure. To specify an overlay image, use the bitwise **OR** operator to combine **fStyle** with the [INDEXTOOVERLAYMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro, passing the one-based index of the overlay image in the macro. This image must have been previously specified as an overlay image using the [ImageList_SetOverlayImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_setoverlayimage) API.

To extract the overlay image from the **fStyle**, use the bitwise **AND** operator to mask **fStyle** with the [ILD_OVERLAYMASK](https://learn.microsoft.com/windows/desktop/Controls/imagelistdrawflags) value.

Comctl32.dll version 6 is not redistributable. To use Comctl32.dll version 6, you must specify it in a manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).