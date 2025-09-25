# _DXVA_PicResample structure

## Description

The DXVA_PicResample structure is sent by the host decoder to the accelerator to control the resampling process. This process is invoked when the [bDXVA_Func variable](https://learn.microsoft.com/windows-hardware/drivers/display/bdxva-func-variable) is equal to 4.

## Members

### `wPicResampleSourcePicIndex`

Specifies the reference buffer to be resampled.

### `wPicResampleDestPicIndex`

Specifies the buffer to be used for the output of the reference picture resampling operation.

### `wPicResampleRcontrol`

Specifies the rounding mode for averaging in the resampling operation. In the case of H.263 Annex O Spatial Scalability, this member is 1. (This corresponds to the value of *RCRPR* in H.263 Annex P that is equivalent to the upsampling needed for H.263 Annex O spatial scalability.) In the case of H.263 Annex P Reference Picture Resampling, this value is equal to the H.263 variable *RCRPR*

### `bPicResampleExtrapWidth`

Indicates if horizontal resampling must include padding of the resampled picture. If nonzero and the padding method of using motion vectors over picture boundaries is used on the accelerator, any resampling must include padding of the resampled picture. This padding must cover at least the specified width around each edge of the resampled picture regardless of the resampling operation that is performed.

### `bPicResampleExtrapHeight`

Indicates if vertical resampling must include padding of the resampled picture. If nonzero and the padding method of using motion vectors over picture boundaries is used on the accelerator, any resampling must include padding of the resampled picture. This padding must cover at least the specified height around each edge of the resampled picture regardless of the resampling operation that is performed.

### `dwPicResampleSourceWidth`

Specifies the width in units of luminance samples of the area of the source picture to be resampled to the destination picture.

### `dwPicResampleSourceHeight`

Specifies the height of the area of the source picture, in units of luminance samples to be resampled to the destination picture.

### `dwPicResampleDestWidth`

Specifies the width of the area of the destination picture, in units of luminance samples to contain the resampled data from the source picture.

### `dwPicResampleDestHeight`

Specifies the height of the area of the destination picture in units of luminance samples to contain the resampled data from the source picture.

### `dwPicResampleFullDestWidth`

Specifies the full width of the area of the destination picture in units of luminance samples to contain the resampled data from the source picture.

### `dwPicResampleFullDestHeight`

Specifies the full height of the area of the destination picture in units of luminance samples to contain the resampled data from the source picture.

## Remarks

The clipping performed by **dwPicResampleFullDestHeight** is used to generate any samples outside the source resampling area. (This value is necessary for H.263 Annex P support of custom source formats in which the luminance width or height is not divisible by 16.)

In the case of H.263 Annex O Spatial Scalability, the value of **wPicResampleRcontrol** is 1. This value corresponds to the value of *RCRPR* in H.263 Annex P that is equivalent to the upsampling needed for H.263 Annex O spatial scalability. In the case of H.263 Annex P Reference Picture Resampling, **wPicResampleRcontrol** is equal to the H.263 variable *RCRPR*.