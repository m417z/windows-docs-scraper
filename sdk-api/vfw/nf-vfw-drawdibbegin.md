# DrawDibBegin function

## Description

The **DrawDib** function changes parameters of a DrawDib DC or initializes a new DrawDib DC.

## Parameters

### `hdd`

Handle to a DrawDib DC.

### `hdc`

Handle to a DC for drawing. This parameter is optional.

### `dxDst`

Width, in **MM_TEXT** client units, of the destination rectangle.

### `dyDst`

Height, in **MM_TEXT** client units, of the destination rectangle.

### `lpbi`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the image format. The color table for the DIB follows the image format and the **biHeight** member must be a positive value.

### `dxSrc`

Width, in pixels, of the source rectangle.

### `dySrc`

Height, in pixels, of the source rectangle.

### `wFlags`

Applicable flags for the function. The following values are defined.

| Value | Meaning |
| --- | --- |
| DDF_ANIMATE | Allows palette animation. If this value is present, DrawDib reserves as many entries as possible by setting **PC_RESERVED** in the **palPalEntry** array entries of the [LOGPALETTE](https://learn.microsoft.com/previous-versions//ms532642(v=vs.85)) structure, and the palette can be animated by using the [DrawDibChangePalette](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibchangepalette) function. If your application uses the **DrawDibBegin** function with the [DrawDibDraw](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibdraw) function, set this value with **DrawDibBegin** rather than **DrawDibDraw**. |
| DDF_BACKGROUNDPAL | Realizes the palette used for drawing as a background task, leaving the current palette used for the display unchanged. (This value is mutually exclusive of **DDF_SAME_HDC**.) |
| DDF_BUFFER | Causes DrawDib to try to use an off-screen buffer so **DDF_UPDATE** can be used. This disables decompression and drawing directly to the screen. If DrawDib is unable to create an off-screen buffer, it will decompress or draw directly to the screen. For more information, see the **DDF_UPDATE** and **DDF_DONTDRAW** values described for [DrawDibDraw](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibdraw). |
| DDF_DONTDRAW | Current image is not drawn, but is decompressed. **DDF_UPDATE** can be used later to draw the image. This flag supersedes the **DDF_PREROLL** flag. |
| DDF_FULLSCREEN | Not supported. |
| DDF_HALFTONE | Always dithers the DIB to a standard palette regardless of the palette of the DIB. If your application uses **DrawDibBegin** with [DrawDibDraw](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibdraw), set this value with **DrawDibBegin** rather than **DrawDibDraw**. |
| DDF_JUSTDRAWIT | Draws the image by using GDI. Prohibits DrawDib functions from decompressing, stretching, or dithering the image. This strips DrawDib of capabilities that differentiate it from the [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits) function. |
| DDF_SAME_DRAW | Use the current drawing parameters for [DrawDibDraw](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibdraw). Use this value only if *lpbi*, *dxDest*, *dyDest*, *dxSrc*, and *dySrc* have not changed since using **DrawDibDraw** or **DrawDibBegin**. This flag supersedes the **DDF_SAME_DIB** and **DDF_SAME_SIZE** flags. |
| DDF_SAME_HDC | Use the current DC handle and the palette currently associated with the DC. |
| DDF_UPDATE | Last buffered bitmap needs to be redrawn. If drawing fails with this value, a buffered image is not available and a new image needs to be specified before the display can be updated. |

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

This function prepares to draw a DIB specified by *lpbi* to the DC. The image is stretched to the size specified by *dxDest* and *dyDest*. If *dxDest* and *dyDest* are set to −1, the DIB is drawn to a 1:1 scale without stretching.

You can update the flags of a DrawDib DC by reissuing **DrawDibBegin**, specifying the new flags, and changing at least one of the following settings: *dxDest*, *dyDest*, *lpbi*, *dxSrc*, or *dySrc*.

If the parameters of **DrawDibBegin** have not changed, subsequent calls to the function have no effect.

## See also

[DrawDib Functions](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-functions)