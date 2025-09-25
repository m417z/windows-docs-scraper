# BP_BUFFERFORMAT enumeration

## Description

Specifies the format of the buffer. Used by [BeginBufferedAnimation](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedanimation) and [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint).

## Constants

### `BPBF_COMPATIBLEBITMAP`

Compatible bitmap. The number of bits per pixel is based on the color format of the device associated with the HDC specified with [BeginBufferedPaint](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedpaint) or [BeginBufferedAnimation](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-beginbufferedanimation)—typically, this is the display device.

### `BPBF_DIB`

Bottom-up device-independent bitmap. The origin of the bitmap is the lower-left corner. Uses 32 bits per pixel.

### `BPBF_TOPDOWNDIB`

Top-down device-independent bitmap. The origin of the bitmap is the upper-left corner. Uses 32 bits per pixel.

### `BPBF_TOPDOWNMONODIB`

Top-down, monochrome, device-independent bitmap. Uses 1 bit per pixel.

## See also

[CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap)

[Device-Independent Bitmaps](https://learn.microsoft.com/windows/desktop/gdi/device-independent-bitmaps)

**Other Resources**