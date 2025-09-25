# _DXVA_BufferDescription structure

## Description

The DXVA_BufferDescription structure is sent by the host decoder to the accelerator to provide information to the accelerator about the buffer that is currently being passed from the host to the accelerator.

## Members

### `dwTypeIndex`

Identifies the type of buffer passed to the accelerator. The following table lists the numeric identifiers and the associated buffer type.

| **Value** | **Buffer Type** |
|:--|:--|
| 1 | Picture decoding parameter buffers. |
| 2 | [Macroblock control command buffers](https://learn.microsoft.com/windows-hardware/drivers/display/macroblock-oriented-picture-decoding) (closely associated with and having a 1:1 correspondence with residual difference block data buffers). |
| 3 | Residual difference block data buffers. See [Macroblock-Oriented Picture Decoding](https://learn.microsoft.com/windows-hardware/drivers/display/macroblock-oriented-picture-decoding) for more information. |
| 4 | Deblocking filter control command buffers (with or without a restriction on the effect of the filter). |
| 5 | Inverse-quantization matrix buffers (only used with off-host VLD processing). |
| 6 | Slice-control buffers (closely associated with and having a 1:1 correspondence with bitstream data buffers). |
| 7 | Bitstream data buffers. |
| 8 | AYUV alpha-blending sample buffers. |
| 9 | IA44/AI44 alpha-blending surface buffers. |
| 10 | DPXD alpha-blending surface buffers. |
| 11 | Highlight data buffers. |
| 12 | DCCMD data buffers. |
| 13 | Alpha-blend combination buffers. |
| 14 | Picture resampling control buffers. |
| 15 | Read-back command buffers containing commands to read macroblocks of the resulting picture back to the host. |

### `dwBufferIndex`

Specifies the sequence number of the buffer within the buffers of the same type that were passed in the same [buffer description list](https://learn.microsoft.com/windows-hardware/drivers/display/buffer-description-list).

### `dwDataOffset`

Specifies the offset of the relevant data from the beginning of the buffer in bytes. The use of this member is currently restricted to the value zero.

### `dwDataSize`

Specifies the amount of relevant data in the buffer in bytes. The location of the last byte of content in the buffer is **dwDataOffset**, plus **dwDataSize** minus 1.

### `dwFirstMBaddress`

Specifies the macroblock address of the first macroblock in the buffer passed to the accelerator. The macroblock address is given in raster scan order. The address is determined by the members of [DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters). Examples of macroblock addresses are as follows.

| **Macroblock** | **Address** |
|:--|:--|
| top-left | zero |
| top-right | **wPicWidthInMBminus1** |
| lower-left | wPicHeightInMBminus1 x (wPicWidthInMBminus1+1) |
| lower-right | (wPicHeightInMBminus1+1) x (wPicWidthInMBminus1+1)-1 |

This member must be zero if the data buffer is among the following types: picture decoding parameters, inverse-quantization matrix, slice control, bitstream data, AYUV, IA44/AI44, DPXD, Highlight, and DCCMD.

If the data buffer is a residual difference block data buffer, **dwFirstMBaddress** must have the same value as for the corresponding macroblock control command buffer. See [Macroblock-Oriented Picture Decoding](https://learn.microsoft.com/windows-hardware/drivers/display/macroblock-oriented-picture-decoding) for more information.

### `dwNumMBsInBuffer`

Specifies the number of macroblocks of data in the buffer. This count includes skipped macroblocks. Must be zero if the data buffer is among the following types: picture decoding parameters, inverse-quantization matrix, AYUV, IA44/AI44, DPXD, Highlight, or DCCMD.

The value for **dwNumMBsInBuffer** depends on the type of data buffer being used as shown in the following table.

| **Buffer Type** | **Value of dwNumMBsInBuffer** |
|:--|:--|
| Macroblock control command | Must be equal to the sum of all values for MBskipsFollowing, added to the number of macroblock control commands in the macroblock control command buffer. |
| Residual difference block | Must have the same value as for the corresponding macroblock control command buffer. |
| Slice-control command | Must be equal to the value of the wNumberMBsInSlice member of the [DXVA_SliceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_sliceinfo) structure in the slice-control buffer. |
| Bitstream | Must have the same value as for the corresponding slice-control command buffer. |

### `dwWidth`

Specifies the width of the data in the buffer as the number of units of bits for the following types of data: AYUV (data is specified in 32-bit units), IA44/AI44 (data is specified in 8-bit units), or DPXD (data is specified in 2-bit units). This member must be zero if the data buffer is not among the preceding types.

### `dwHeight`

Specifies the height of the data in the buffer as the number of units of bits for the following types of data: AYUV (data is specified in 32-bit units), IA44/AI44 (data is specified in 8-bit units), or DPXD (data is specified in 2-bit units).This member must be zero if the data buffer is not among the preceding types.

### `dwStride`

Specifies the stride of the data in the buffer as the number of units of bits for the following types of data: AYUV (data is specified in 32-bit units), IA44/AI44 (data is specified in 8-bit units), or DPXD (data is specified in 2-bit units). The stride for the applicable buffer types is determined from the buffer allocation setup performed by the accelerator. This member must be zero if the data buffer is not among the preceding types.

### `dwReservedBits`

Reserved bits used for packing and alignment. Must be zero.

## Remarks

An array of DXVA_BufferDescription structures is referred to as a buffer description list. When a set of buffers is sent from the host decoder to the hardware accelerator, a buffer description list is sent to describe the buffers. The buffer description list contains one DXVA_BufferDescription structure for each buffer in this set. The buffer description list starts with a DXVA_BufferDescription structure for the first buffer of the first type, followed by a DXVA_BufferDescription structure for the next buffer of the same type, and so on. The buffer description list then continues with a DXVA_BufferDescription structure for the first buffer of the next type, and so on.

## See also

[DXVA_PictureParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_pictureparameters)

[DXVA_SliceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_sliceinfo)