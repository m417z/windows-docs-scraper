# _DXVADDI_VIDEOTRANSFERMATRIX enumeration

## Description

The DXVADDI_VIDEOTRANSFERMATRIX enumeration type contains values that identify the conversion matrix from Y'Cb'Cr' to (studio) R'G'B'.

## Constants

### `DXVADDI_VideoTransferMatrixMask`

Specifies the video transfer matrix mask. The first 3 (0x07) bits of a DWORD can be used to specify video transfer matrix.

### `DXVADDI_VideoTransferMatrix_Unknown`

Specifies that the video transfer matrix is not specified. The default value is BT601 for standard definition (SD) video and BT709 for high definition (HD) video.

### `DXVADDI_VideoTransferMatrix_BT709`

Specifies the BT709 transfer matrix.

### `DXVADDI_VideoTransferMatrix_BT601`

Specifies the BT601 transfer matrix.

### `DXVADDI_VideoTransferMatrix_SMPTE240M`

Specifies a HD video standard that is rarely used in Japan.

## Remarks

One of the values of DXVADDI_VIDEOTRANSFERMATRIX can be specified in the **VideoTransferMatrix** member of the [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat) structure.

## See also

[DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat)