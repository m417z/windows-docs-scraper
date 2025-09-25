# _WIAS_DOWN_SAMPLE_INFO structure

## Description

The WIAS_DOWN_SAMPLE_INFO structure stores information used by the downsampling helper function, [wiasDownSampleBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasdownsamplebuffer).

## Members

### `ulOriginalWidth`

Specifies the width, in pixels, of the input data.

### `ulOriginalHeight`

Specifies the height, in pixels, of the input data.

### `ulBitsPerPixel`

Specifies the number of bits per pixel of the input data.

### `ulXRes`

Specifies the horizontal resolution of the input data.

### `ulYRes`

Specifies the vertical resolution of the input data.

### `ulDownSampledWidth`

Specifies the width, in pixels, of the output data.

### `ulDownSampledHeight`

Specifies the width, in pixels, of the output data.

### `ulActualSize`

Specifies the number of bytes placed in the destination buffer.

### `ulDestBufSize`

Specifies the size, in bytes, of the destination buffer.

### `ulSrcBufSize`

Specifies the size, in bytes, of the source buffer.

### `pSrcBuffer`

Points to the source buffer.

### `pDestBuffer`

Points to the destination buffer.

## See also

[wiasDownSampleBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasdownsamplebuffer)