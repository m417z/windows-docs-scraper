# _DXVA_QmatrixData structure

## Description

The DXVA_QmatrixData structure is sent by the host decoder to the accelerator to load inverse-quantization matrix data for off-host bitstream compressed video picture decoding.

## Members

### `bNewQmatrix`

Indicates which new inverse-quantization matrices are present in an inverse-quantization matrix buffer. Each element in this array corresponds to an inverse-quantization matrix type and indicates whether a new inverse-quantization matrix of that type is present in the buffer. If any element in the **bNewQmatrix** array contains a value of 1, a new inverse-quantization matrix of the type specified for that array element follows in the inverse-quantization matrix buffer. The inverse-quantization matrices that can be used are as follows.

|NewQmatrix Element|Inverse-Quantization Matrix Type|
|--- |--- |
|0|Specifies intra-luminance quantization.|
|1|Specifies inter-luminance quantization.|
|2|Specifies intra-chrominance quantization.|
|3|Specifies inter-chrominance quantization.|

The value in **bNewQmatrix**[0] and **bNewQmatrix**[1] must not both be zero.

If the value for **bNewQmatrix**[2] or **bNewQmatrix**[3] is zero, then the following applies:

If **bNewQmatrix**[*i* - 2] is zero, the previous inverse-quantization matrix defined by the *i*th element must continue to be used by the accelerator.

If **bNewQmatrix**[*i* - 2] is 1, the inverse-quantization matrix defined by the *i*th element is set equal to the new inverse-quantization matrix for *i* - 2.

### `Qmatrix`

A two-dimensional array that specifies an inverse-quantization matrix buffer. This array is present only for each element in **bNewQmatrix** equal to 1. The matrix consists of (**bBlockWidthMinus1**+1) X (**bBlockHeightMinus1**+1) unsigned words (in which only the lower 8 bits of each word are used for the dominant video coding standards), where **bBlockWidthMinus1** and **bBlockHeightMinus1** are members of the [DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters) structure.

**Note** For MPEG-2 bitstreams, the data values within Qmatrix are in zigzag inverse scan order, as specified in subclause 7.3.1 and figure 7-2 of MPEG-2.

## Remarks

If the video coding does not need inverse-quantization matrices (for example, H.261 and H.263), inverse-quantization matrix buffers must not be sent. If the video coding does need inverse-quantization matrices, some value must be provided for these inverse-quantization matrices by the host prior to, or in conjunction with, the transfer of any bitstream data buffers at the start of the video decoding process.

No default values of inverse-quantization matrices may be assumed by the accelerator in the absence of any prior value sent by the host. The quantization matrix values must be sent explicitly, even if they contain values that are available by default in the relevant video coding specification.

Inverse-quantization matrix buffers are sent only when the **bConfigBitstreamRaw** member of the [DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode) structure is 1.

The order of the data values within the inverse-quantization matrix is as specified in the relevant video coding specification.

## See also

[DXVA_ConfigPictureDecode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_configpicturedecode)

[DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters)