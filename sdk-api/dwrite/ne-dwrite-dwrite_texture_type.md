# DWRITE_TEXTURE_TYPE enumeration

## Description

Identifies a type of alpha texture.

## Constants

### `DWRITE_TEXTURE_ALIASED_1x1`

Specifies an alpha texture for aliased text rendering (that is, each pixel is either fully opaque or fully transparent), with one byte per pixel.

### `DWRITE_TEXTURE_CLEARTYPE_3x1`

Specifies an alpha texture for ClearType text rendering, with three bytes per pixel in the horizontal dimension and one byte per pixel in the vertical dimension.

## Remarks

An alpha texture is a bitmap of alpha values, each representing opacity of a pixel or subpixel.