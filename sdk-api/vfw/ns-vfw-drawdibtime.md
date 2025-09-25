# DRAWDIBTIME structure

## Description

The **DRAWDIBTIME** structure contains elapsed timing information for performing a set of DrawDib operations. The [DrawDibTime](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibtime) function resets the count and the elapsed time value for each operation each time it is called.

## Members

### `timeCount`

Number of times the following operations have been performed since [DrawDibTime](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibtime) was last called:

* Draw a bitmap on the screen.
* Decompress a bitmap.
* Dither a bitmap.
* Stretch a bitmap.
* Transfer bitmap data by using the [BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt) function.
* Transfer bitmap data by using the [SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits) function.

### `timeDraw`

Time to draw bitmaps.

### `timeDecompress`

Time to decompress bitmaps.

### `timeDither`

Time to dither bitmaps.

### `timeStretch`

Time to stretch bitmaps.

### `timeBlt`

Time to transfer bitmaps by using the [BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt) function.

### `timeSetDIBits`

Time to transfer bitmaps by using the [SetDIBits](https://learn.microsoft.com/previous-versions//ms532281(v=vs.85)) function.

## See also

[DrawDib](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib)

[DrawDib Structures](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-structures)

[DrawDibTime](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibtime)

[SetDIBits](https://learn.microsoft.com/previous-versions//ms532281(v=vs.85))