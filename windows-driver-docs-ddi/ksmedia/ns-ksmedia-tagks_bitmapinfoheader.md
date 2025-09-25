# tagKS_BITMAPINFOHEADER structure

## Description

The KS_BITMAPINFOHEADER structure describes details about the video stream, such as image dimensions and pixel depth.

## Members

### `biSize`

Specifies the size of the structure in bytes.

### `biWidth`

Specifies the width of the bitmap in pixels.

### `biHeight`

Specifies the height of the bitmap in pixels.

### `biPlanes`

Specifies the number of planes. This is always set to 1.

### `biBitCount`

Specifies the color bits per pixel. For example, 1, 4, 8, or 24.

### `biCompression`

Specifies the compression scheme.

### `biSizeImage`

Specifies the size of bitmap bits in bytes. (Only required if using compression.)

### `biXPelsPerMeter`

Specifies the horizontal resolution in pixels per meter.

### `biYPelsPerMeter`

Specifies the vertical resolution in pixels per meter.

### `biClrUsed`

Specifies the number of colors used in the image.

### `biClrImportant`

Specifies the number of important colors in the image.

## Remarks

This is the same structure as the user-mode GDI bitmap header (BITMAPINFOHEADER) structure.