# D2D1_BITMAPSOURCE_ORIENTATION enumeration

## Description

Specifies whether a flip and/or rotation operation should be performed by the [Bitmap source effect](https://learn.microsoft.com/windows/desktop/Direct2D/bitmap-source)

## Constants

### `D2D1_BITMAPSOURCE_ORIENTATION_DEFAULT:1`

The effect doesn't change the orientation of the input.

### `D2D1_BITMAPSOURCE_ORIENTATION_FLIP_HORIZONTAL:2`

Flips the image horizontally.

### `D2D1_BITMAPSOURCE_ORIENTATION_ROTATE_CLOCKWISE180:3`

Rotates the image clockwise 180 degrees.

### `D2D1_BITMAPSOURCE_ORIENTATION_ROTATE_CLOCKWISE180_FLIP_HORIZONTAL:4`

Rotates the image clockwise 180 degrees and flips it horizontally.

### `D2D1_BITMAPSOURCE_ORIENTATION_ROTATE_CLOCKWISE270_FLIP_HORIZONTAL:5`

Rotates the image clockwise 270 degrees and flips it horizontally.

### `D2D1_BITMAPSOURCE_ORIENTATION_ROTATE_CLOCKWISE90:6`

Rotates the image clockwise 90 degrees.

### `D2D1_BITMAPSOURCE_ORIENTATION_ROTATE_CLOCKWISE90_FLIP_HORIZONTAL:7`

Rotates the image clockwise 90 degrees and flips it horizontally.

### `D2D1_BITMAPSOURCE_ORIENTATION_ROTATE_CLOCKWISE270:8`

Rotates the image clockwise 270 degrees.

### `D2D1_BITMAPSOURCE_ORIENTATION_FORCE_DWORD:0xffffffff`