# ICDRAWSUGGEST structure

## Description

The **ICDRAWSUGGEST** structure contains compression parameters used with the [ICM_DRAW_SUGGESTFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-suggestformat) message to suggest an appropriate input format.

## Members

### `lpbiIn`

Pointer to the structure containing the compressed input format.

### `lpbiSuggest`

Pointer to a buffer to return a compatible input format for the renderer.

### `dxSrc`

Width of the source rectangle.

### `dySrc`

Height of the source rectangle.

### `dxDst`

Width of the destination rectangle.

### `dyDst`

Height of the destination rectangle.

### `hicDecompressor`

Handle to a decompressor that supports the format of data described in **lpbiIn**.

## See also

[ICM_DRAW_SUGGESTFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-suggestformat)

Video Compression Manager

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)