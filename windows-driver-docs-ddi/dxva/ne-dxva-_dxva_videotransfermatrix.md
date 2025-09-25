# _DXVA_VideoTransferMatrix enumeration

## Description

The DXVA_VideoTransferMatrix enumeration type contains enumerators that identify the conversion matrix from Y'Cb'Cr' to R'G'B'.

## Constants

### `DXVA_VideoTransferMatrixShift`

Specifies to shift bits by 15 positions (DXVA_ExtColorData_ShiftBase + 7, or 8 + 7).

### `DXVA_VideoTransferMatrixMask`

Specifies the video transfer matrix mask. 3 (0x00038000) bits of a DWORD can be used to specify video transfer matrix.

### `DXVA_VideoTransferMatrix_Unknown`

Specifies that the video transfer matrix is not specified. The default is BT601 for standard definition (SD) video and BT709 for high definition (HD) video.

### `DXVA_VideoTransferMatrix_BT709`

Specifies the BT709 transfer matrix.

### `DXVA_VideoTransferMatrix_BT601`

Specifies the BT601 transfer matrix.

### `DXVA_VideoTransferMatrix_SMPTE240M`

Specifies a HD video standard rarely used in Japan.

## Remarks

One of the enumerators of DXVA_VideoTransferMatrix can be specified in the **VideoTransferMatrix** member of the [DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat) structure.

## See also

[DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat)