# _DXVA_AYUVsample2 structure

## Description

The DXVA_AYUVsample2 structure is sent by the host decoder to the accelerator to specify Y, Cb, Cr color values, and an associated opacity.

## Members

### `bCrValue`

Specifies a chrominance (Cr) sample value (scaled per ITU-R Rec. BT.601) as an unsigned value. Thus, the color black is nominally specified by Y=16, Cb=Cr=128, and the color white is nominally specified by Y=235, Cb=Cr=128.

### `bCbValue`

Specifies a chrominance (Cb) sample value (scaled per ITU-R Rec. BT.601) as an unsigned value. Thus, the color black is nominally specified by Y=16, Cb=Cr=128, and the color white is nominally specified by Y=235, Cb=Cr=128.

### `bY_Value`

Specifies a luminance (Y) sample value (scaled per ITU-R Rec. BT.601) as an unsigned value. Thus, the color black is nominally specified by Y=16, Cb=Cr=128, and the color white is nominally specified by Y=235, Cb=Cr=128.

### `bSampleAlpha8`

Specifies the opacity of the pixel when used as a source graphic for blending with another picture. For Windows Server 2003 SP1 and Windows XP SP2, the opacity level is not used and should be ignored by the driver.

## Remarks

A value of zero for **bSampleAlpha8** indicates that the pixel is transparent (so that the other entries have no effect on the resulting blended picture), and a value of 255 indicates that the pixel is opaque (so that the other entries completely determine the value of the resulting blended picture sample).

For nonzero values of **bSampleAlpha8**, the blend to use is calculated by the following expression:

( ( ( (**bSampleAlpha8**+1) x (graphic value) ) + ( (255 - **bSampleAlpha8**) x (picture value) ) ) + 128 ) >> 8

For a zero value of **bSampleAlpha8**, the specified blend to use is the picture value without alteration.

**Note** If the alpha-blending surface originates as a DVD video subpicture, the preferred method for converting from the 4-bit alpha used by DVD video to the 8-bit alpha specified by **bSampleAlpha8** is to map a 4-bit alpha value of zero to an 8-bit alpha value of zero and to convert all nonzero 4-bit alphas to 8-bit alphas by performing a left shift of four places and adding the constant 15.

The width and height of the AYUV alpha-blending surface are specified in the associated [buffer description list](https://learn.microsoft.com/windows-hardware/drivers/display/buffer-description-list) defined by the [DXVA_BufferDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_bufferdescription) structure.

The **DXVA_AYUVsample2** structure is used for each sample in a DirectX VA AYUV blending surface, for **OutsideYUVcolor** in a [DXVA_BlendCombination](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_blendcombination) structure, and for each of the entries in a 16-entry AYUV alpha-blending palette.

## See also

[DXVA_BlendCombination](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_blendcombination)

[DXVA_BufferDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_bufferdescription)