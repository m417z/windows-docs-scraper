# DXVADDI_AYUVSAMPLE8 structure

## Description

The **DXVADDI_AYUVSAMPLE8** structure describes 8-bit Cr, Cb, and Y color values and an associated opacity.

## Members

### `Cr` [in]

An 8-bit chrominance (V) sample value.

### `Cb` [in]

An 8-bit chrominance (U) sample value.

### `Y` [in]

An 8-bit luminance (Y) sample value.

### `Alpha` [in]

The 8-bit opacity of the pixel when it is used as a source graphic for blending with another picture.

## Remarks

A value of 0 in the **Alpha** member indicates that the pixel is transparent (so that the other entries have no effect on the resulting blended picture), and a value of 255 indicates that the pixel is opaque (so that the other entries completely determine the value of the resulting blended picture sample).

For nonzero values of **Alpha**, the blend to use is calculated by the following expression:

```cpp
( ( ( (Alpha + 1) x (graphic value) ) + ( (255 - Alpha) x (picture value) ) )  + 128 ) >> 8
```

If **Alpha** is 0, the specified blend to use is the picture value without alteration.

The color value is scaled according to ITU-R Rec. BT.601, which you can learn about from the [International Telecommunication Union](https://www.itu.int/rec/R-REC-BT.601/) website. Therefore, the color black is nominally specified by Y=16, Cb=Cr=128, and the color white is nominally specified by Y=235, Cb=Cr=128.

> [!NOTE]
> If the alpha-blending surface originates as a DVD video subpicture, the preferred method for converting from the 4-bit alpha that is used by DVD video to the 8-bit alpha that is specified by **Alpha** is to map a 4-bit alpha value of zero to an 8-bit alpha value of zero and to convert all of the nonzero 4-bit alphas to 8-bit alphas by performing a left shift of four places and adding the constant 15.

The width and height of the AYUV alpha-blending surface are specified in the associated [buffer description list](https://learn.microsoft.com/windows-hardware/drivers/display/buffer-description-list) that is defined by the [**DXVADDI_DECODEBUFFERDESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodebufferdesc) structure.

## See also

[**DXVADDI_DECODEBUFFERDESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_decodebufferdesc)

[**DXVADDI_VIDEODESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videodesc)