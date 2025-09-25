# DXGI_OUTDUPL_POINTER_SHAPE_TYPE enumeration

## Description

Identifies the type of pointer shape.

## Constants

### `DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MONOCHROME:0x1`

The pointer type is a monochrome mouse pointer, which is a monochrome bitmap. The bitmap's size is specified by width and height in a 1 bits per pixel (bpp) device independent bitmap (DIB) format AND mask that is followed by another 1 bpp DIB format XOR mask of the same size.

### `DXGI_OUTDUPL_POINTER_SHAPE_TYPE_COLOR:0x2`

The pointer type is a color mouse pointer, which is a color bitmap. The bitmap's size is specified by width and height in a 32 bpp ARGB DIB format.

### `DXGI_OUTDUPL_POINTER_SHAPE_TYPE_MASKED_COLOR:0x4`

The pointer type is a masked color mouse pointer. A masked color mouse pointer is a 32 bpp ARGB format bitmap with the mask value in the alpha bits. The only allowed mask values are 0 and 0xFF. When the mask value is 0, the RGB value should replace the screen pixel. When the mask value is 0xFF, an XOR operation is performed on the RGB value and the screen pixel; the result replaces the screen pixel.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)

[DXGI_OUTDUPL_POINTER_SHAPE_INFO](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_outdupl_pointer_shape_info)