# BLENDFUNCTION structure

## Description

The **BLENDFUNCTION** structure controls blending by specifying the blending functions for source and destination bitmaps.

## Members

### `BlendOp`

The source blend operation. Currently, the only source and destination blend operation that has been defined is AC_SRC_OVER. For details, see the following Remarks section.

### `BlendFlags`

Must be zero.

### `SourceConstantAlpha`

Specifies an alpha transparency value to be used on the entire source bitmap. The **SourceConstantAlpha** value is combined with any per-pixel alpha values in the source bitmap. If you set **SourceConstantAlpha** to 0, it is assumed that your image is transparent. Set the **SourceConstantAlpha** value to 255 (opaque) when you only want to use per-pixel alpha values.

### `AlphaFormat`

This member controls the way the source and destination bitmaps are interpreted. **AlphaFormat** has the following value.

| Value | Meaning |
| --- | --- |
| AC_SRC_ALPHA | This flag is set when the bitmap has an Alpha channel (that is, per-pixel alpha). Note that the APIs use premultiplied alpha, which means that the red, green and blue channel values in the bitmap must be premultiplied with the alpha channel value. For example, if the alpha channel value is x, the red, green and blue channels must be multiplied by x and divided by 0xff prior to the call. |

## Remarks

When the **AlphaFormat** member is AC_SRC_ALPHA, the source bitmap must be 32 bpp. If it is not, the [AlphaBlend](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-alphablend) function will fail.

When the **BlendOp** member is AC_SRC_OVER, the source bitmap is placed over the destination bitmap based on the alpha values of the source pixels.

If the source bitmap has no per-pixel alpha value (that is, AC_SRC_ALPHA is not set), the **SourceConstantAlpha** value determines the blend of the source and destination bitmaps, as shown in the following table. Note that SCA is used for **SourceConstantAlpha** here. Also, SCA is divided by 255 because it has a value that ranges from 0 to 255.

|  |  |  |
| --- | --- | --- |
| Dst.Red | = Src.Red * (SCA/255.0) | + Dst.Red * (1.0 - (SCA/255.0)) |
| Dst.Green | = Src.Green * (SCA/255.0) | + Dst.Green * (1.0 - (SCA/255.0)) |
| Dst.Blue | = Src.Blue * (SCA/255.0) | + Dst.Blue * (1.0 - (SCA/255.0)) |

If the destination bitmap has an alpha channel, then the blend is as follows.

|  |  |  |
| --- | --- | --- |
| Dst.Alpha | = Src.Alpha * (SCA/255.0) | + Dst.Alpha * (1.0 - (SCA/255.0)) |

If the source bitmap does not use **SourceConstantAlpha** (that is, it equals 0xFF), the per-pixel alpha determines the blend of the source and destination bitmaps, as shown in the following table.

|  |  |  |
| --- | --- | --- |
| Dst.Red | = Src.Red | + (1 - Src.Alpha) * Dst.Red |
| Dst.Green | = Src.Green | + (1 - Src.Alpha) * Dst.Green |
| Dst.Blue | = Src.Blue | + (1 - Src.Alpha) * Dst.Blue |

If the destination bitmap has an alpha channel, then the blend is as follows.

|  |  |  |
| --- | --- | --- |
| Dest.alpha | = Src.Alpha | + (1 - SrcAlpha) * Dst.Alpha |

If the source has both the **SourceConstantAlpha** (that is, it is not 0xFF) and per-pixel alpha, the source is pre-multiplied by the **SourceConstantAlpha** and then the blend is based on the per-pixel alpha. The following tables show this. Note that **SourceConstantAlpha** is divided by 255 because it has a value that ranges from 0 to 255.

|  |  |  |
| --- | --- | --- |
| Src.Red | = Src.Red | * SourceConstantAlpha / 255.0; |
| Src.Green | = Src.Green | * SourceConstantAlpha / 255.0; |
| Src.Blue | = Src.Blue | * SourceConstantAlpha / 255.0; |
| Src.Alpha | = Src.Alpha | * SourceConstantAlpha / 255.0; |
| Dst.Red | = Src.Red | + (1 - Src.Alpha) * Dst.Red |
| Dst.Green | = Src.Green | + (1 - Src.Alpha) * Dst.Green |
| Dst.Blue | = Src.Blue | + (1 - Src.Alpha) * Dst.Blue |
| Dst.Alpha | = Src.Alpha | + (1 - Src.Alpha) * Dst.Alpha |

## See also

[AlphaBlend](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-alphablend)

[Bitmap Structures](https://learn.microsoft.com/windows/desktop/gdi/bitmap-structures)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)